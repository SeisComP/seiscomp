############################################################################
#    Copyright (C) by gempa GmbH, GFZ Potsdam                              #
#                                                                          #
#    You can redistribute and/or modify this program under the             #
#    terms of the SeisComP Public License.                                 #
#                                                                          #
#    This program is distributed in the hope that it will be useful,       #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of        #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
#    SeisComP Public License for more details.                             #
############################################################################

import os
import sys
import glob
import getpass

try:
    # Python 2.5
    from xml.etree import ElementTree
    from xml.parsers.expat import ExpatError as ParseError
except ImportError:
    from elementtree import ElementTree
    from xml.parsers.expat import ExpatError as ParseError

from seiscomp import config

# Python version depended string conversion
if sys.version_info[0] < 3:
    py3input = raw_input #pylint: disable=E0602
else:
    py3input = input


def tagname(element):
    names = element.tag.split("}")
    if len(names) == 0:
        return ""

    return names.pop()


def oneliner(txt):
    return txt.strip().replace("\n", "")


def block(txt, width=80):
    lines = [l.strip() for l in txt.strip().replace("\r", "").split('\n')]
    line = "\n".join(lines)

    current = 0
    lines = []

    while current < len(line):
        end = line.find('\n', current)
        if (end == -1) or (end - current > width):
            if len(line) - current > width:
                end = line.rfind(' ', current, current+width)
                if end == -1:
                    end = line.find(' ', current)
                    if end == -1:
                        end = len(line)
            else:
                end = len(line)

        lines.append(line[current:end].strip())

        current = end + 1

    return lines


class SetupNode:
    def __init__(self, parent, inp, next = None):
        self.parent = parent
        self.next = next
        self.child = None
        self.activeChild = None

        self.modname = ""
        self.groupname = ""
        self.input = inp
        self.value = ""
        self.path = ""
        self.optionValue = None
        self.isOption = False


class Option:
    """
    Setup input option wrapper.
    """

    def __init__(self, value):
        self.value = value
        self.desc = None
        self.inputs = []


class Input:
    """
    Setup input wrapper.
    """

    def __init__(self, name, t, default_value=None):
        self.name = name
        self.type = t
        self.default_value = default_value
        self.text = None
        self.desc = None
        self.echo = None
        self.options = []


def dumpTree(cfg, node):
    if node.input:
        cfg.setString(node.modname + "." + node.path, node.value)

    if node.activeChild:
        if node.isOption:
            dumpTree(cfg, node.activeChild.child)
        else:
            dumpTree(cfg, node.activeChild)

    if not node.next is None:
        dumpTree(cfg, node.next)


class Simple:
    """
    Simple console setup handler that parses all description xml files
    and extracts the setup part. It asks for all available setting line
    by line and passes the resulting configuration back which is then
    passed to all init modules that have a setup method.
    """

    def __init__(self, args = []):
        self.modules = args
        self.setupTree = SetupNode(None, None)
        self.paths = []
        self.currentNode = None

    def run(self, env):
        desc_pattern = os.path.join(
            env.SEISCOMP_ROOT, "etc", "descriptions", "*.xml")
        xmls = glob.glob(desc_pattern)

        setup_groups = {}

        for f in xmls:
            try:
                tree = ElementTree.parse(f)
            except ParseError as xxx_todo_changeme:
                (err) = xxx_todo_changeme
                sys.stderr.write("%s: parsing XML failed: %s\n" % (f, err))
                continue

            root = tree.getroot()
            if tagname(root) != "seiscomp":
                sys.stderr.write(
                    "%s: wrong root tag, expected 'seiscomp'\n" % f)
                continue

            # Read all modules
            mods = tree.findall("module")

            for mod in mods:
                modname = mod.get('name')
                if not modname:
                    sys.stderr.write("%s: skipping module without name\n" % f)
                    continue

                if modname in setup_groups:
                    raise Exception(
                        "%s: duplicate module name: %s" % (f, modname))

                if self.modules and modname not in self.modules:
                    continue

                setup = mod.find("setup")
                if setup is None:
                    continue

                groups = setup.findall("group")
                if len(groups) == 0:
                    continue

                setup_groups[modname] = groups

            # Read all plugin's
            plugins = tree.findall("plugin")

            for plugin in plugins:
                try:
                    modname = plugin.find('extends').text.strip()
                except:
                    raise Exception("%s: plugin does not define 'extends'" % f)

                if modname.find('\n') >= 0:
                    raise Exception("%s: wrong module name in plugin." \
                                    "extends: no newlines allowed" % f)

                if not modname:
                    sys.stderr.write("%s: skipping module without name\n" % f)
                    continue

                setup = plugin.find("setup")
                if setup is None:
                    continue

                groups = setup.findall("group")
                if len(groups) == 0:
                    continue

                if modname in setup_groups:
                    setup_groups[modname] += groups
                else:
                    setup_groups[modname] = groups

        for name, groups in sorted(setup_groups.items()):
            self.addGroups(self.setupTree, name, groups)

        # Always descend to the first child (if available)
        self.setupTree.activeChild = self.setupTree.child
        self.currentNode = self.setupTree.activeChild

        sys.stdout.write('''
====================================================================
SeisComP setup
====================================================================

This initializes the configuration of your installation.
If you already made adjustments to the configuration files
be warned that this setup will overwrite existing parameters
with default values. This is not a configurator for all
options of your setup but helps to setup initial standard values.

--------------------------------------------------------------------
Hint: Entered values starting with a dot (.) are handled
      as commands. Available commands are:

      quit: Quit setup without modification to your configuration.
      back: Go back to the previous parameter.
      help: Show help about the current parameter (if available).

      If you need to enter a value with a leading dot, escape it
      with backslash, e.g. "\\.value".
--------------------------------------------------------------------

''')

        try:
            self.fillTree()
        except StopIteration:
            raise Exception("aborted by user")

        cfg = config.Config()
        dumpTree(cfg, self.setupTree)

        return cfg

    def addGroups(self, node, modname, groups):
        for g in groups:
            self.addInputs(None, node, modname, g.get(
                'name'), g, g.get('name', "") + ".")

    def addInputs(self, obj, parent, modname, group, xml, prefix):
        childs = parent.child;
        if not childs is None:
            while not childs.next is None:
                childs = childs.next

        inputs = xml.findall("input")
        for inp in inputs:
            name = inp.get('name')
            if not name:
                raise Exception("%s: no name defined" % prefix)

            input_ = Input(name, inp.get('type'), inp.get('default'))
            try:
                input_.text = oneliner(inp.find('text').text)
            except Exception:
                input_.text = input_.name

            try:
                input_.desc = block(inp.find('description').text)
            except Exception:
                pass

            input_.echo = inp.get('echo')

            if obj:
                obj.inputs.append(input_)

            opts = inp.findall("option")

            node = SetupNode(parent, input_)
            node.path = prefix + input_.name
            node.value = input_.default_value
            node.modname = modname
            node.groupname = group
            node.isOption = len(opts) > 0

            if childs is None:
                childs = node
                parent.child = childs
            else:
                childs.next = node
                childs = childs.next;

            options = node.child

            for opt in opts:
                value = opt.get('value')
                if not value:
                    raise Exception("%s: option without value" % prefix)

                optionNode = SetupNode(node, input_)
                optionNode.path = node.path + "." + value
                optionNode.modname = modname
                optionNode.groupname = group
                optionNode.isOption = False
                optionNode.optionValue = value

                option = Option(value)
                try:
                    option.desc = block(opt.find('description').text, 74)
                except Exception:
                    pass
                input_.options.append(option)

                if options is None:
                    options = optionNode
                    node.child = options
                else:
                    options.next = optionNode
                    options = options.next

                self.addInputs(option, optionNode, modname,
                               group, opt, node.path + ".")

    def fillTree(self):
        while True:
            if not self.currentNode:
                sys.stdout.write("\nFinished setup\n--------------\n\n")
                sys.stdout.write("P) Proceed to apply configuration\n")
                sys.stdout.write("D) Dump entered parameters\n")
                sys.stdout.write("B) Back to last parameter\n")
                sys.stdout.write("Q) Quit without changes\n")

                value = py3input('Command? [P]: ').upper()
                if value == "Q":
                    raise StopIteration()
                if value == "D":
                    sys.stdout.write("\n----\n")
                    cfg = config.Config()
                    dumpTree(cfg, self.setupTree)
                    cfg.writeConfig("-")
                    sys.stdout.write("----\n\n")
                    continue
                if value == "P" or not value:
                    sys.stdout.write("\nRunning setup\n-------------\n\n")
                    return
                if value == "B":
                    self.prevStep()
                    continue

                sys.stdout.write("\nEnter either p, b or q\n")
                continue

            if not self.currentNode.input:
                self.nextStep()
                continue

            default_value = self.valueToString(self.currentNode)

            isChoice = False
            isPassword = False
            if self.currentNode.input.echo == "password":
                isPassword = True

            node_text = default_value
            prompt = self.currentNode.input.text

            if isPassword:
                node_text = '*' * len(node_text)
                prompt += " (input not echoed)"

            if (not self.currentNode.input.type or \
                self.currentNode.input.type != "boolean") and \
                len(self.currentNode.input.options) > 0:
                idx = 0
                def_idx = 0
                for opt in self.currentNode.input.options:
                    sys.stdout.write("%2d) %s\n" % (idx, opt.value))
                    if opt.desc:
                        for l in opt.desc:
                            sys.stdout.write("      %s\n" % l)
                    if default_value == opt.value:
                        def_idx = idx
                    idx += 1
                isChoice = True
                prompt += " [%d]: " % def_idx
            else:
                prompt += " [%s]: " % node_text

            if self.currentNode.input.echo == "password":
                value = getpass.getpass(prompt)
            else:
                value = py3input(prompt)

            if not value:
                value = default_value
            elif value == ".help":
                if self.currentNode.input.desc:
                    sys.stdout.write("\n%s\n\n" %
                                     "\n".join(self.currentNode.input.desc))
                else:
                    sys.stdout.write("\nSorry, no help available.\n\n")
                continue
            elif value == ".back":
                self.prevStep()
                continue
            elif value == ".quit":
                raise StopIteration()
            elif value.startswith("."):
                sys.stdout.write("Unknown command. Values starting with '.' are handled has commands such as\n"
                                 "'.help', '.quit' or '.back'. To use a leading dot in a value, escape it with '\'\n"
                                 "e.g. '\\.color'\n")
                continue
            else:
                # Replace leading \. with .
                if value.startswith('\\.'):
                    value = value[1:]

                if isChoice:
                    try:
                        idx = int(value)
                    except ValueError:
                        idx = -1
                    if idx < 0 or idx >= len(self.currentNode.input.options):
                        sys.stdout.write("\nEnter a number between 0 and %d\n\n" % (
                            len(self.currentNode.input.options)-1))
                        continue
                    value = self.currentNode.input.options[idx].value

            if self.currentNode.input.type and self.currentNode.input.type == "boolean":
                if not value in ["yes", "no"]:
                    sys.stdout.write("Please enter 'yes' or 'no'\n")
                    continue

                if value == "yes":
                    value = "true"
                else:
                    value = "false"

            self.currentNode.value = value
            self.nextStep()

    @staticmethod
    def valueToString(node):
        if not node.input.type:
            if node.value is None:
                return ""
            return node.value

        if node.input.type == "boolean":
            if node.value == "true":
                return "yes"
            if node.value == "false":
                return "no"
            return "yes"

        if node.value is None:
            return ""
        return node.value

    def prevStep(self):
        if len(self.paths) == 0:
            sys.stdout.write("No previous step available\n")
            return

        self.currentNode = self.paths.pop()

    def nextStep(self):
        self.currentNode.activeChild = None
        self.paths.append(self.currentNode)

        # Choice?
        if self.currentNode.isOption:
            child = self.currentNode.child
            while not child is None:
                if child.optionValue == self.currentNode.value:
                    if not child.child is None:
                        self.currentNode.activeChild = child
                        self.currentNode = child.child
                        return

                    break
                child = child.next

        next = self.currentNode.next
        while next is None and not self.currentNode.parent is None:
            self.currentNode = self.currentNode.parent
            if not self.currentNode.optionValue is None:
                continue
            next = self.currentNode.next

        self.currentNode = next
