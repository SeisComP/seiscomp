#!/usr/bin/env seiscomp-python

from __future__ import division, print_function

import glob
import importlib
import os
import shutil
import signal
import socket
import subprocess
import sys
import traceback
import seiscomp.shell

# Problem: if
# import seiscomp.config
# fails, then in any case a sometimes misleading exception
# ImportError: No module named _config
# is raised, even if the seiscomp._config module exists but for
# another reason fails to import. We therefore...
import seiscomp._config
# ...here explicitly to get a meaningful exception if this fails.

import seiscomp.config
import seiscomp.kernel

# Python version depended string conversion
if sys.version_info[0] < 3:
    py3ustr = str
else:
    py3ustr = lambda s: s.decode('utf-8', 'replace')

try:
    real_raw_input = raw_input
except NameError:
    real_raw_input = input


# request and optionally enforce user input
# @param question The question to be answered.
# @param default The default value to use if no input was made
# @param options List or string of available options. If defined the input must
#        match one of the options (unless a default is specified). If the input
#        is invalid the question is repeated.
def getInput(question, default=None, options=None):

    def _default(text):
        # print default value to previous line if no input was made
        if default:
            print("\033[F\033[{}G{}".format(len(text)+1, default))
        return default

    # no options: accept any type of input
    if not options:
        defaultStr = "" if default is None else " [{}]".format(default)
        question = "{}{}: ".format(question, defaultStr)
        return real_raw_input(question) or _default(question)

    if default is not None:
        default = str(default).lower()

    # options supplied: check and enforce input
    opts = [str(o).lower() for o in options]
    optStr = "/".join(o.upper() if o == default else o for o in opts)
    question = "{} [{}]: ".format(question, optStr)
    while True:
        res = real_raw_input(question)
        if not res and default:
            return _default(question)

        if res.lower() in opts:
            return res.lower()


if sys.platform == "darwin":
    SysLibraryPathVar = "DYLD_FALLBACK_LIBRARY_PATH"
    SysFrameworkPathVar = "DYLD_FALLBACK_FRAMEWORK_PATH"
else:
    SysLibraryPathVar = "LD_LIBRARY_PATH"
    SysFrameworkPathVar = None


def get_library_path():
    if sys.platform == "darwin":
        return LD_LIBRARY_PATH + ":" + DYLD_FALLBACK_FRAMEWORK_PATH

    return LD_LIBRARY_PATH


def get_framework_path():
    return DYLD_FALLBACK_FRAMEWORK_PATH


# Python 3 compatible string check
def is_string(variable):
    try:
        string_class = basestring
    except NameError:
        string_class = str

    return isinstance(variable, string_class)


# ------------------------------------------------------------------------------
# Helper functions
# ------------------------------------------------------------------------------
SIGTERM_SENT = False


def sigterm_handler(_signum, _):
    # pylint: disable=W0603
    global SIGTERM_SENT
    if not SIGTERM_SENT:
        SIGTERM_SENT = True
        os.killpg(0, signal.SIGTERM)

    sys.exit()


def system(args):
    proc = subprocess.Popen(args, shell=False, env=os.environ)
    while True:
        try:
            return proc.wait()
        except KeyboardInterrupt:
            continue
        except Exception as e:
            try:
                proc.terminate()
            except Exception:
                pass
            sys.stderr.write("Exception: %s\n" % str(e))
            continue

    # return subprocess.call(cmd, shell=True)


def error(msg):
    sys.stderr.write("error: %s\n" % msg)
    sys.stderr.flush()


def warning(msg):
    sys.stderr.write("warning: %s\n" % msg)
    sys.stderr.flush()


# Returns a seiscomp.kernel.Module instance
# from a given path with a given name
def load_module(path):
    modname0 = os.path.splitext(os.path.basename(path))[0].replace('.', '_')
    modname = '__seiscomp_modules_' + modname0

    if modname in sys.modules:
        mod = sys.modules[modname]
    else:
        if sys.path[0] != INIT_PATH:
            sys.path.insert(0, INIT_PATH)
        mod = importlib.import_module(modname0)
        mod.__file__ = path

        # store it in sys.modules
        sys.modules[modname] = mod

        module = mod.Module

    return module


def module_key(module):
    return (module.order, module.name)


def load_init_modules(path):
    modules = []

    if not os.path.exists(path):
        error("Cannot load any module - path not existing: %s" % path)
        return modules

    files = glob.glob(os.path.join(path, "*.py"))
    for f in files:
        try:
            pmod = load_module(f)
        except Exception as exc:
            error(("%s: " % f) + str(exc))
            continue

        try:
            mod = pmod(env)  # .Module(env)
        except Exception as exc:
            error(("%s: " % f) + str(exc))
            continue

        modules.append(mod)

    #mods = sorted(mods, key=lambda mod: mod.order)
    modules = sorted(modules, key=module_key)

    return modules


def get_module(name):
    for module in mods:
        if module.name == name:
            return module
    return None


def has_module(name):
    return get_module(name) is not None


def dump_paths():
    print('--------------------')
    print('SEISCOMP_ROOT="%s"' % SEISCOMP_ROOT)
    print('PATH="%s"' % os.environ["PATH"])
    print('%s="%s"' % (SysLibraryPathVar, os.environ[SysLibraryPathVar]))
    if SysFrameworkPathVar:
        print(
            '%s="%s"' %
            (SysFrameworkPathVar,
             os.environ[SysFrameworkPathVar]))
    print('PYTHONPATH="%s"' % sys.path)
    print('CWD="%s"' % os.getcwd())
    print('--------------------')


# Returns whether a module should run or not. It simply returns if its
# runfile exists.
def shouldModuleRun(mod_name):
    return os.path.exists(env.runFile(mod_name))


def touch(filename):
    try:
        open(filename, 'w').close()
    except Exception as exc:
        error(str(exc))


def start_module(mod):
    # Create runfile
    touch(env.runFile(mod.name))
    return mod.start()


def stop_module(mod):
    try:
        if not mod.stop():
            error("Failed to stop %s: unknown error" % mod.name)
            return 1
    except Exception as e:
        error("Failed to stop %s: %s" % (mod.name, str(e)))
        return 1

    # Delete runfile
    try:
        os.remove(env.runFile(mod.name))
    except BaseException:
        return 1

    return 0


def start_kernel_modules():
    for mod in mods:
        if isinstance(mod, seiscomp.kernel.CoreModule):
            return start_module(mod)

    return 1


def stop_kernel_modules():
    for mod in reversed(mods):
        if isinstance(mod, seiscomp.kernel.CoreModule):
            return stop_module(mod)

    return 1

# ------------------------------------------------------------------------------
# Commandline action handler
# ------------------------------------------------------------------------------
def on_setup(args, flags):
    # pylint: disable=W0621
    import seiscomp.setup

    if "stdin" in flags:
        cfg = seiscomp.config.Config()
        if not cfg.readConfig("-"):
            error("invalid configuration from stdin")
            return 1
    else:
        setup = seiscomp.setup.Simple()
        cfg = setup.run(env)

    retCode = 0

    for mod in config_mods:
        if len(args) == 0 or mod.name in args:
            try:
                hasSetupHandler = callable(getattr(mod, 'setup'))
            except BaseException:
                hasSetupHandler = False

            if hasSetupHandler:
                print("* setup %s" % mod.name)
                if mod.setup(cfg) != 0:
                    error("module '%s' failed to setup" % mod.name)
                    retCode = 1

    if retCode == 0:
        runpath = os.path.join(SEISCOMP_ROOT, "var", "run")
        if not os.path.exists(runpath):
            try:
                os.makedirs(runpath)
            except BaseException:
                error("failed to create directory: %s" % runpath)

        statfile = os.path.join(runpath, "seiscomp.init")
        if not os.path.exists(statfile):
            try:
                open(statfile, "w").close()
            except BaseException:
                error("failed to create status file: %s" % statfile)

    return retCode


def on_setup_help(_):
    print("Initialize the configuration of all available modules. Each module")
    print("implements its own setup handler which is called at this point. The")
    print("initialization takes the installation directory into account and")
    print("should be repeated when copying the system to another directory.")
    print("NOTE:")
    print("Setup might overwrite already made settings with default values.")
    return 0


def on_shell(_args, _):
    shell = seiscomp.shell.CLI()
    try:
        shell.run(env)
    except Exception as e:
        error(str(e))
        return 1
    return 0


def on_shell_help(_):
    print("Launches the SeisComP shell, a commandline interface which allows")
    print("to manage modules configurations and bindings.")
    return 0


def on_enable(args, _):
    if not args:
        error("module name required")
        return 1

    for name in args:
        modName = get_module(name)
        if modName is None:
            error("%s is not available" % name)
        elif isinstance(modName, seiscomp.kernel.CoreModule):
            error("%s is a kernel module and is enabled automatically" % name)
        else:
            env.enableModule(name)
    return 0


def on_enable_help(_):
    print("Enables all given modules to be started when 'seiscomp start' is")
    print("invoked without a module list.")
    print()
    print("Examples:")
    print("seiscomp enable seedlink slarchive")


def on_disable(args, _):
    if not args:
        error("module name required")
        return 1

    for name in args:
        modName = get_module(name)
        if modName is None:
            error("%s is not available" % modName)
        elif isinstance(modName, seiscomp.kernel.CoreModule):
            error("%s is a kernel module and cannot be disabled" % name)
        else:
            env.disableModule(name)
    return 0


def on_disable_help(_):
    print("Disables all given modules. See 'enable'.")
    print()
    print("Examples:")
    print("seiscomp disable seedlink slarchive")


def on_start(args, _):
    cntStarted = 0
    if not args:
        if start_kernel_modules() == 0:
            cntStarted += 1
        for mod in mods:
            # Kernel modules have been started already
            if isinstance(mod, seiscomp.kernel.CoreModule):
                continue
            # Module in autorun?
            if env.isModuleEnabled(mod.name):
                if start_module(mod) == 0:
                    cntStarted += 1
    else:
        for mod in mods:
            if mod.name in args or len(args) == 0:
                if start_module(mod) == 0:
                    cntStarted += 1

    if not useCSV:
        print("Summary: {} modules started".format(cntStarted))

    return 0


def on_start_help(_):
    print("Starts all enabled modules or a list of modules given.")
    print()
    print("Examples:")
    print("seiscomp start")
    print("seiscomp start seedlink slarchive")


def on_stop(args, _):
    cntStopped = 0
    if not args:
        for mod in reversed(mods):
            # Kernel modules will be stopped latter
            if isinstance(mod, seiscomp.kernel.CoreModule):
                continue
            if stop_module(mod) == 0:
                cntStopped += 1

        # Stop all kernel modules
        if stop_kernel_modules() == 0:
            cntStopped += 1
    else:
        for mod in reversed(mods):
            if mod.name in args or len(args) == 0:
                if stop_module(mod) == 0:
                    cntStopped += 1

    if not useCSV:
        print("Summary: {} modules stopped".format(cntStopped))

    return 0


def on_stop_help(_):
    print("Stops all enabled modules or a list of modules given.")
    print()
    print("Examples:")
    print("seiscomp stop")
    print("seiscomp stop seedlink slarchive")


def on_restart(args, flags):
    on_stop(args, flags)
    on_start(args, flags)
    return 0


def on_restart_help(_):
    print("Restarts all enabled modules or a list of modules given.")
    print("This command is equal to:")
    print("seiscomp stop {args}")
    print("seiscomp start {args}")
    print()
    print("Examples:")
    print("seiscomp restart")
    print("seiscomp restart seedlink slarchive")


def on_reload(args, _):
    if not args:
        for mod in mods:
            # Reload not supported by kernel modules
            if isinstance(mod, seiscomp.kernel.CoreModule):
                continue

            if shouldModuleRun(mod.name):
                mod.reload()
    else:
        for mod in mods:
            if mod.name in args or len(args) == 0:
                mod.reload()

    return 0


def on_reload_help(_):
    print("Reloads all enabled modules or a list of modules given.")
    print("This operation is module specific and implemented only for some")
    print("modules.")
    print()
    print("Examples:")
    print("seiscomp reload")
    print("seiscomp reload fdsnws")


def on_check(args, _):
    cntStarted = 0
    for mod in mods:
        if mod.name in args or len(args) == 0:
            if shouldModuleRun(mod.name):
                cntStarted += 1
                mod.check()

    if not useCSV:
        print("Summary: {} started modules checked".format(cntStarted))

    return 0


def on_check_help(_):
    print("Checks if a started module is still running. If not, it is")
    print("restarted. If no modules are given, all started modules are")
    print("checked.")
    print()
    print("Examples:")
    print("$ seiscomp check seedlink")
    print("seedlink is already running")


def on_exec(args, _):
    if len(args) < 1:
        error("no module name given")
        return False

    # Change back into the working dir
    env.chback()
    return system(args)


def on_exec_help(_):
    print("Executes a command like calling a command from commandline.")
    print("It will setup all paths and execute the command.")
    print("'seiscomp run' will block until the command terminates.")
    print("Example:")
    print("seiscomp exec scolv")


def on_list(args, _):
    if len(args) < 1:
        error("expected argument: {modules|aliases|enabled|disabled|started}")
        return 1

    if args[0] == "modules":
        found = 0
        for mod in mods:
            if env.isModuleEnabled(mod.name) or \
               isinstance(mod, seiscomp.kernel.CoreModule):
                state = "enabled"
            else:
                state = "disabled"
            found += 1
            print("%s is %s" % (mod.name, state))

        if not useCSV:
            print("Summary: {} modules reported".format(found))

        return 0

    if args[0] == "aliases":
        f = open(ALIAS_FILE, 'r')
        lines = [line.rstrip() for line in f.readlines()]
        for line in lines:
            if line.lstrip().startswith('#') or not line.strip():
                continue
            toks = [t.strip() for t in line.split('=')]
            # Remove invalid lines
            if len(toks) != 2:
                continue
            if useCSV:
                print("%s;%s" % (toks[0], toks[1]))
            else:
                print("%s -> %s" % (toks[0], toks[1]))
        f.close()
        return 0

    if args[0] == "enabled":
        found = 0
        for mod in mods:
            if env.isModuleEnabled(mod.name) or \
               isinstance(mod, seiscomp.kernel.CoreModule):
                print(mod.name)
                found += 1

        if not useCSV:
            print("Summary: {} modules enabled".format(found))

        return 0

    if args[0] == "disabled":
        found = 0
        for mod in mods:
            if not env.isModuleEnabled(mod.name) and \
               not isinstance(mod, seiscomp.kernel.CoreModule):
                print(mod.name)
                found += 1

        if not useCSV:
            print("Summary: {} modules disabled".format(found))

        return 0

    if args[0] == "started":
        found = 0
        for mod in mods:
            if shouldModuleRun(mod.name):
                print(mod.name)
                found += 1

        if not useCSV:
            print("Summary: {} modules started".format(found))

        return 0

    error(
        "wrong argument: {modules|aliases|enabled|disabled|started} expected")
    return 1


def on_list_help(_):
    print("Prints the result of a query. 5 queries are currently supported:")
    print(" modules: lists all existing modules")
    print(" aliases: lists all existing aliases")
    print(" enabled: lists all enabled modules")
    print(" disabled: lists all disabled modules")
    print(" started: lists all started modules")
    print()
    print("Examples:")
    print("$ seiscomp list aliases")
    print("l1autopick -> scautopick")


def on_status(args, _):
    found = 0
    if len(args) > 0 and args[0] == "enabled":
        for mod in mods:
            if env.isModuleEnabled(mod.name) or isinstance(
                    mod, seiscomp.kernel.CoreModule):
                mod.status(shouldModuleRun(mod.name))
                found += 1

        if not useCSV:
            print("Summary: {} modules enabled".format(found))

        return 0

    if len(args) > 0 and args[0] == "started":
        for mod in mods:
            if shouldModuleRun(mod.name):
                mod.status(shouldModuleRun(mod.name))
                found += 1

        if not useCSV:
            print("Summary: {} modules started".format(found))

        return 0

    for mod in mods:
        if mod.name in args or len(args) == 0:
            mod.status(shouldModuleRun(mod.name))
            found += 1

    if not useCSV:
        print("Summary: {} modules reported".format(found))
    return 0


def on_status_help(_):
    print("Prints the status of ")
    print(" * all modules")
    print(" * all enabled modules")
    print(" * all started modules")
    print(" * a list of modules")
    print("and gives a warning if a module should run but doesn't.")
    print("This command supports csv formatted output via '--csv' switch.")
    print()
    print("Examples:")
    print("$ seiscomp status started")
    print("$ seiscomp status enabled")
    print("scmaster             is not running [WARNING]")
    print("$ seiscomp status scautopick")
    print("scautopick           is not running")
    print("$ seiscomp --csv status scautopick")
    print("scautopick;0;0;0")
    print()
    print("CSV format:")
    print(" column 1: module name")
    print(" column 2: running flag")
    print(" column 3: should run flag")
    print(" column 4: enabled flag")


def on_print(args, _):
    if len(args) < 1:
        error("expected argument: {crontab|env}")
        return 1

    if args[0] == "crontab":
        print("*/3 * * * * %s check >/dev/null 2>&1" %
              os.path.join(env.SEISCOMP_ROOT, "bin", "seiscomp"))
        for mod in mods:
            mod.printCrontab()
    elif args[0] == "env":
        print('export SEISCOMP_ROOT="%s"' % SEISCOMP_ROOT)
        print('export PATH="%s:$PATH"' % BIN_PATH)
        print('export %s="%s:$%s"' %
              (SysLibraryPathVar, get_library_path(), SysLibraryPathVar))
        if sys.platform == "darwin":
            print(
                'export %s="%s:$%s"' %
                (SysFrameworkPathVar,
                 get_framework_path(),
                 SysFrameworkPathVar))

        print('export PYTHONPATH="%s:$PYTHONPATH"' % PYTHONPATH)
        print('export MANPATH="%s:$MANPATH"' % MANPATH)
        print(
            'source "%s/share/shell-completion/seiscomp.bash"' %
            SEISCOMP_ROOT)
        hostenv = os.path.join(SEISCOMP_ROOT, "etc", "env", "by-hostname",
                               socket.gethostname())
        if os.path.isfile(hostenv):
            print('source %s' % hostenv)
    else:
        error("wrong argument: {crontab|env} expected")
        return 1

    return 0


def on_print_help(_):
    print("seiscomp print {crontab|env}")
    print(" crontab: prints crontab entries of all registered or given modules.")
    print(" env: prints environment variables necessary to run SeisComP modules.")
    print()
    print("Examples:")
    print("Source SC environment into current bash session")
    print("$ eval $(seiscomp/bin/seiscomp print env)")


def on_install_deps_linux(args, _):
    try:
        out = subprocess.Popen(['lsb_release', '-sir'],
                               stdout=subprocess.PIPE).communicate()[0].splitlines()
        # some OS return release and version in one line
        if len(out) == 1:
            out = out[0].split()

        out = [l.decode('utf-8').strip() for l in out]
    except BaseException:
        error("lsb_release is not installed")
        print("*********************************************************************")
        print("seiscomp was not able to figure out the installed distribution")
        print("You need to check the documentation for required packages and install")
        print("them manually.")
        print("*********************************************************************")
        return 1

    try:
        release, version = out
    except BaseException:
        error("unexpected version result")
        return 1

    print("Distribution: " + release + " " + version)

    for n in range(version.count('.') + 1):
        ver = version.rsplit('.', n)[0]
        script_dir = os.path.join(
            env.SEISCOMP_ROOT, "share", "deps", release.lower(), ver.lower())
        if os.path.exists(script_dir):
            break

    if not os.path.exists(script_dir):
        print("*********************************************************************")
        print("Sorry, the installed distribution is not supported.")
        print("You need to check the documentation for required packages and install")
        print("them manually.")
        print("*********************************************************************")
        return 1

    for pkg in args:
        script = os.path.join(script_dir, "install-" + pkg + ".sh")
        if not os.path.exists(script):
            error("no handler available for package '%s'" % pkg)
            return 1

        if system(["sudo", "sh", script]) != 0:
            error("installation failed")
            return 1

    return 0


def on_install_deps(args, flags):
    if not args:
        error("expected package list: PKG1 [PKG2 [..]]")
        print("Example: seiscomp install-deps base gui mysql-server")
        print("For a list of available packages issue: seiscomp help install-deps")

    if sys.platform.startswith("linux"):
        return on_install_deps_linux(args, flags)

    error("unsupported platform")
    print("*********************************************************************")
    print("The platform you are currently running on is not supported to install")
    print("dependencies automatically.")
    print("You need to check the documentation for required packages and install")
    print("them manually.")
    print("*********************************************************************")
    return 1


def on_install_deps_help(_):
    print("seiscomp install-deps PKG1 [PKG2 [..]]")
    print("Installs OS dependencies to run SeisComP. This requires either a 'sudo'")
    print("or root account. Available packages are:")
    print("  base:   basic packages required by all installations")
    print("  gui:    required by graphical user interfaces, e.g. on workstations")
    print("  [mysql,mariadb,postgresql]-server:")
    print("          database management system required by the machine running")
    print("          the SeisComP messaging system (scmaster)")
    print("  fdsnws: required for data sharing via the FDSN web services")

    return 0


def on_update_config(args, _):
    kernelModsStarted = False
    configuredMods = {}

    listOfMods = args
    if not listOfMods:
        listOfMods = []
        for mod in config_mods:
            listOfMods.append(mod.name)

    while len(listOfMods) > 0:
        for mod in config_mods:
            if mod.name in listOfMods:
                if not kernelModsStarted and mod.requiresKernelModules():
                    print("* starting kernel modules")
                    start_kernel_modules()
                    kernelModsStarted = True
                print("* configure %s" % mod.name)

                proxy = None

                try:
                    proxy = mod.updateConfigProxy()
                    if is_string(proxy):
                        configuredMods.setdefault(proxy, False)
                except Exception:
                    pass

                if proxy is None:
                    result = mod.updateConfig()

                    try:
                        error_code = int(result)
                    except ValueError:
                        error("unexpected return type when updating "
                              "configuration of %s" % mod.name)
                        return 1

                    if error_code != 0:
                        error(
                            "updating configuration for %s failed" % mod.name)
                        return 1

                configuredMods[mod.name] = True

        listOfMods = []
        # Collect all unconfigured but indirectly requested mods
        for name, configured in configuredMods.items():
            if not configured:
                listOfMods.append(name)

    return 0


def on_update_config_help(_):
    print("Updates the configuration of all available modules. This command")
    print("will convert the etc/*.cfg to the modules native configuration")
    print("including its bindings.")
    return 0


def on_alias(args, _):
    if len(args) < 2:
        error("expected arguments: {create|remove} ALIAS_NAME APP_NAME")
        return 1

    aliasName = args[1]

    if args[0] == "create":
        if len(args) != 3:
            error("expected two arguments for create: ALIAS_NAME APP_NAME")
            return 1

        mod = None
        for module in mods:
            if module.name == args[2]:
                mod = module
                break

        if not mod:
            error("module '%s' not found" % args[2])
            return 1

        supportsAliases = False
        try:
            supportsAliases = mod.supportsAliases()
        except BaseException:
            pass

        if not supportsAliases:
            error("module '%s' does not support aliases" % args[2])
            return 1

        mod2 = args[2]
        if os.path.exists(os.path.join("bin", mod2)):
            mod1 = os.path.join("bin", aliasName)
        elif os.path.exists(os.path.join("sbin", mod2)):
            mod1 = os.path.join("sbin", aliasName)
        else:
            error("no %s binary found (neither bin nor sbin)")
            return 1

        # create alias line in etc/descriptions/aliases
        if not os.path.exists(DESC_PATH):
            try:
                os.makedirs(DESC_PATH)
            except Exception:
                error("failed to create directory: %s" % DESC_PATH)
                return 1

        has_alias = False
        lines = []
        new_lines = []
        try:
            f = open(ALIAS_FILE, 'r')
            lines = [line.rstrip() for line in f.readlines()]
            for line in lines:
                if line.lstrip().startswith('#') or not line.strip():
                    # Keep comments or empty lines
                    new_lines.append(line)
                    continue
                toks = [t.strip() for t in line.split('=')]
                # Remove invalid lines
                if len(toks) != 2:
                    continue
                if toks[0] == aliasName:
                    has_alias = True
                    break

                new_lines.append(line)
            f.close()
        except BaseException:
            pass

        if has_alias:
            warning("%s is already registered as alias for %s in " \
                    "$SEISCOMP_ROOT/etc/descriptions/aliases"  % (aliasName, toks[1]))
            warning("  + do not register again but trying to link the required files")
        else:
            print(
                "Registered alias '%s' in $SEISCOMP_ROOT/etc/descriptions/aliases" %
                (aliasName))

        # Check if target exists already
        if os.path.exists(os.path.join(SEISCOMP_ROOT, mod1)):
            warning(
                "link '%s' to '%s' exists already in %s/bin/" %
                (aliasName, mod2, SEISCOMP_ROOT))
            warning("  + do not link again")

        try:
            f = open(ALIAS_FILE, 'w')
        except BaseException:
            error("failed to open/create alias file: %s" % ALIAS_FILE)
            return 1

        new_lines.append("%s = %s" % (aliasName, args[2]))

        f.write("\n".join(new_lines) + "\n")
        f.close()

        # create symlink of defaults from etc/defaults/mod1.cfg to etc/defaults/mod2.cfg
        # use relative path to default_cfg2
        cwdAlias = os.getcwd()
        os.chdir(os.path.join(SEISCOMP_ROOT, "etc", "defaults"))
        default_cfg1 = aliasName + ".cfg"
        default_cfg2 = args[2] + ".cfg"
        if os.path.exists(default_cfg2):
            print("Linking default configuration: %s -> %s" %
                  (default_cfg2, default_cfg1))
            # - first: remove target
            try:
                os.remove(default_cfg1)
            except BaseException:
                pass
            # create symlink
            os.symlink(os.path.relpath(default_cfg2), default_cfg1)
        else:
            print("No default configuration to link")
        # return to initial directory
        os.chdir(cwdAlias)

        # create symlink from bin/mod1 to bin/mod2
        # - first: remove target
        try:
            os.remove(os.path.join(SEISCOMP_ROOT, mod1))
        except BaseException:
            pass
        print("Creating app symlink: %s -> %s" % (mod2, mod1))
        os.symlink(mod2, os.path.join(SEISCOMP_ROOT, mod1))

        # create symlink from etc/init/mod1.py to etc/init/mod2.py
        cwdAlias = os.getcwd()
        os.chdir(os.path.join(SEISCOMP_ROOT, "etc", "init"))
        init1 = aliasName + ".py"
        init2 = args[2] + ".py"
        print("Linking init script: %s -> %s" % (init2, init1))
        # - first: remove target
        try:
            os.remove(init1)
        except BaseException:
            pass
        # create symlink with relative path
        os.symlink(os.path.relpath(init2), init1)
        # return to initial directory
        os.chdir(cwdAlias)

        return 0

    if args[0] == "remove":
        if len(args) != 2:
            error("expected one argument for remove: alias-name")
            return 1

        print("Removing alias '%s'" % aliasName)
        #  check and remove alias line in etc/descriptions/aliases
        has_alias = False
        lines = []
        new_lines = []
        try:
            f = open(ALIAS_FILE, 'r')
            lines = [line.rstrip() for line in f.readlines()]
            for line in lines:
                if line.lstrip().startswith('#') or not line.strip():
                    # Keep comments or empty lines
                    new_lines.append(line)
                    continue
                toks = [t.strip() for t in line.split('=')]
                # Remove invalid lines
                if len(toks) != 2:
                    continue
                if toks[0] == aliasName:
                    has_alias = True
                else:
                    new_lines.append(line)
            f.close()
        except BaseException:
            pass

        if not has_alias:
            print("  + {} is not defined as an alias".format(aliasName))
            if not interactiveMode:
                print("  + remove related configuration with '--interactive'")
                if len(lines) == len(new_lines):
                    return 1

        try:
            f = open(ALIAS_FILE, 'w')
        except BaseException:
            error("  + failed to open/create alias file: %s" % ALIAS_FILE)
            return 1

        if len(lines) > 0:
            f.write("\n".join(new_lines) + "\n")
        f.close()

        if not has_alias:
            if not interactiveMode:
                return 1

        # remove symlink from bin/mod1
        if os.path.exists(os.path.join("bin", aliasName)):
            sym_link = os.path.join("bin", aliasName)
        elif os.path.exists(os.path.join("sbin", aliasName)):
            sym_link = os.path.join("sbin", aliasName)
        else:
            sym_link = ""

        if sym_link:
            print("  + removing app symlink: %s" % sym_link)
            try:
                os.remove(os.path.join(SEISCOMP_ROOT, sym_link))
            except BaseException:
                pass

        # remove symlink from etc/init/mod1.py
        init_scr = os.path.join("etc", "init", aliasName + ".py")
        print("  + removing init script: %s" % init_scr)
        try:
            os.remove(os.path.join(SEISCOMP_ROOT, init_scr))
        except BaseException:
            pass

        #  delete defaults etc/defaults/mod1.cfg
        default_cfg = os.path.join("etc", "defaults", aliasName + ".cfg")
        print("  + removing default configuration: {}/{}"
              .format(SEISCOMP_ROOT, default_cfg))
        try:
            os.remove(os.path.join(SEISCOMP_ROOT, default_cfg))
        except BaseException as e:
            error("    + could not remove %s" % e)

        if not interactiveMode:
            warning("No other configuration removed for '%s' - interactive"
                    " removal is supported by '--interactive'" % aliasName)
            return 0

        # test module configuration files
        # SYSTEMCONFIGDIR
        cfg = os.path.join("etc", aliasName + ".cfg")
        if os.path.isfile(cfg):
            print("  + found module configuration file: {}/{}"
                  .format(SEISCOMP_ROOT, cfg))
            answer = getInput("    + do you wish to remove it?", 'n', 'yn')
            if answer == "y":
                try:
                    os.remove(cfg)
                except Exception as e:
                    error("    + could not remove '%s' - try manually" % e)

        # CONFIGDIR
        cfg = os.path.join(
            os.path.expanduser("~"),
            ".seiscomp",
            aliasName + ".cfg")
        if os.path.isfile(cfg):
            print("  + found module configuration file: {}".format(cfg))
            answer = getInput("    + do you wish to remove it?", 'n', 'yn')
            if answer == "y":
                try:
                    os.remove(cfg)
                except Exception as e:
                    error("  + could not remove the file: %s - try manually" % e)

        # test module binding files
        bindingDir = os.path.join(SEISCOMP_ROOT, "etc", "key", aliasName)
        if os.path.exists(bindingDir):
            print("  + found binding directory: {}".format(bindingDir))
            answer = getInput("    + do you wish to remove it?", 'n', 'yn')
            if answer == "y":
                try:
                    shutil.rmtree(bindingDir)
                except Exception as e:
                    error("    + could not remove the directory: %s - try manually" % e)

        # test key files
        keyDir = os.path.join(SEISCOMP_ROOT, 'etc', 'key')
        dirContent = os.listdir(keyDir)
        keyFiles = []
        print("  + testing key files")
        for f in dirContent:
            if not os.path.isfile(os.path.join(keyDir, f)) or \
                    not f.startswith("station_"):
                continue

            keyFile = os.path.join(keyDir, f)
            with open(keyFile, 'r') as fp:
                # Read all lines in the file one by one
                for line in fp:
                    # check if the line starts with the module name
                    if line.startswith(aliasName):
                        keyFiles.append(keyFile)
                        print("    + found binding for '{}' in: {}".format(aliasName, keyFile))

        if keyFiles:
            print("    + found {} bindings for '{}' in key files".format(len(keyFiles), aliasName))
            question = "    + remove all '{}' bindings from key files?".format(aliasName)
            answer = getInput(question, 'n', 'yn')
            if answer == "y":
                shell = seiscomp.shell.CLI(env)
                shell.commandRemove(["module", aliasName, "*.*"])
        else:
            print("    + found no key files")

        return 0

    error("Wrong command '%s': expected 'create' or 'remove'" % args[0])
    return 1


def on_alias_help(_):
    print("seiscomp alias {create|remove} ALIAS_NAME APP_NAME")
    print("Creates/removes symlinks to applications. Symlinks to symlinks are not allowed.")
    print()
    print("Examples:")
    print("$ seiscomp alias create scautopick2 scautopick")
    print("Copy default configuration: etc/defaults/scautopick.cfg -> etc/defaults/scautopick2.cfg")
    print("Create app symlink: scautopick -> bin/scautopick2")
    print("Copy init script: etc/init/scautopick.py -> etc/init/scautopick2.py")
    print()
    print("$ seiscomp alias remove scautopick2")
    print("Remove default configuration: etc/defaults/scautopick2.cfg")
    print("Remove app symlink: bin/scautopick2")
    print("Remove init script: etc/init/scautopick2.py")


allowed_actions = [
    "install-deps",
    "setup",
    "shell",
    "enable",
    "disable",
    "start",
    "stop",
    "restart",
    "reload",
    "check",
    "status",
    "list",
    "exec",
    "update-config",
    "alias",
    "print",
    "help"
]


# Define all actions that do not need locking of seiscomp
actions_without_lock = [
    # "install-deps",
    "help",
    "list",
    "exec",
    "print"
]


def on_help(args, _):
    if not args:
        print("Name:")
        print("  seiscomp - Load the environment of the SeisComP installation from " \
              "where seiscomp is executed and run a command")
        print("\nSynopsis:")
        print("  seiscomp [flags] [commands] [arguments]")
        print("\nFlags:")
        print("  --asroot              Allow running a command as root")
        print("  --csv                 Print output as csv in machine-readable format")
        print("  -i, [--interactive]   Interactive mode: Allow deleting files " \
              "interactively when removing aliases")
        print("  --wait arg            Define a timeout in seconds for acquiring the seiscomp " \
              "lock file, e.g. `seiscomp --wait 10 update-config`")
        print("\nAvailable commands:")
        for helpAction in allowed_actions:
            print("  %s" % helpAction)

        print("\nUse 'help [command]' to get more help about a command")
        print("\nExamples:")
        print("  seiscomp help update-config          Show help for update-config")
        print("  seiscomp update-config               Run update-config for allmodules")
        print("  seiscomp update-config trunk         Run update-config for all trunk modules")
        print("  seiscomp update-config scautopick    Run update-config for scautopick")
        return 0

    cmd = args[0]
    try:
        func = globals()["on_" + cmd.replace("-", "_") + "_help"]
    except BaseException:
        print("Sorry, no help available for %s" % cmd)
        return 1
    func(args[1:])
    return 0


def run_action(runAction, args, flags):
    try:
        func = globals()["on_" + runAction.replace("-", "_")]
        return func(args, flags)
    except Exception as exc:
        error("command '%s' failed: %s" % (runAction, str(exc)))
        if "debug" in flags:
            info = traceback.format_exception(*sys.exc_info())
            for i in info:
                sys.stderr.write(i)
        return 2


def on_csv_help(_):
    print("If --csv is prepended to a usual command the internal output is")
    print("set to comma separated values. The only command that currently")
    print("uses this output format is 'status'.")
    print()
    print("Example:")
    print("seiscomp --csv status")
    return 0


# ------------------------------------------------------------------------------
# Check command line
# ------------------------------------------------------------------------------
useCSV = False
asRoot = False
lockTimeout = None
interactiveMode = False

argv = sys.argv[1:]
argflags = []

# Check for flags
while argv:
    if argv[0] == "--csv":
        useCSV = True
        argv = argv[1:]
    elif argv[0] == "--asroot":
        asRoot = True
        argv = argv[1:]
    if argv[0] == "--interactive" or argv[0] == "-i":
        interactiveMode = True
        argv = argv[1:]
    elif argv[0] == "--wait":
        argv = argv[1:]
        if not argv:
            print("--wait expects an integer value in seconds")
            sys.exit(1)
        try:
            lockTimeout = int(argv[0])
        except BaseException:
            print("Wait timeout is not an integer: %s" % argv[0])
            sys.exit(1)
        if lockTimeout < 0:
            print("Wait timeout must be positive: %s" % argv[0])
            sys.exit(1)
        argv = argv[1:]
    elif argv[0].startswith("--"):
        argflags.append(argv[0][2:])
        argv = argv[1:]
    else:
        break

if len(argv) < 1:
    print("seiscomp [flags] {%s} [args]" % "|".join(allowed_actions))
    print("\nUse 'seiscomp help' to get more help")
    sys.exit(1)

action = argv[0]
arguments = argv[1:]

if action not in allowed_actions:
    print("seiscomp [flags] {%s} [args]" % "|".join(allowed_actions))
    sys.exit(1)

if os.getuid() == 0 and not asRoot and action != "install-deps":
    print("Running 'seiscomp' as root is dangerous. Use --asroot only if you")
    print("know exactly what you are doing!")
    sys.exit(1)

# ------------------------------------------------------------------------------
# Initialize the environment
# ------------------------------------------------------------------------------

# Resolve symlinks to files (if any)
if os.path.islink(sys.argv[0]):
    # Read the link target
    target = os.readlink(sys.argv[0])
    # Is the target an absolute path then take it as is
    if os.path.isabs(target):
        sys.argv[0] = target
    # Otherwise join the dirname of the script with the target
    # to get the semi-real path of the seiscomp script. Semi-real
    # refers to the fact that symlinks are not completely resolved
    # and why the usage of os.path.realpath is avoided. If the
    # seiscomp directory itself is a symlink it should be preserved.
    else:
        sys.argv[0] = os.path.join(os.path.dirname(sys.argv[0]), target)

# Guess SEISCOMP_ROOT from path of called script, directory links are not
# resolved allowing to create separate SeisComP environments
if os.path.isabs(sys.argv[0]):
    root_path = sys.argv[0]
else:
    cwd = os.getenv('PWD')
    if cwd is None:
        cwd = os.getcwd()
    root_path = os.path.join(cwd, sys.argv[0])

SEISCOMP_ROOT = os.path.dirname(os.path.dirname(os.path.normpath(root_path)))
INIT_PATH = os.path.join(SEISCOMP_ROOT, "etc", "init")
DESC_PATH = os.path.join(SEISCOMP_ROOT, "etc", "descriptions")
ALIAS_FILE = os.path.join(DESC_PATH, "aliases")
BIN_PATH = os.path.join(SEISCOMP_ROOT, "bin")
SBIN_PATH = os.path.join(SEISCOMP_ROOT, "sbin")
PYTHONPATH = os.path.join(SEISCOMP_ROOT, "lib", "python")
MANPATH = os.path.join(SEISCOMP_ROOT, "share", "man")
LD_LIBRARY_PATH = os.path.join(SEISCOMP_ROOT, "lib")
DYLD_FALLBACK_FRAMEWORK_PATH = os.path.join(SEISCOMP_ROOT, "lib", "3rd-party")

# Run another process with proper LD_LIBRARY_PATH set otherwise the dynamic
# linker will not find dependent SC3 libraries
isWrapped = False
try:
    if os.environ["SEISCOMP_WRAP"] == "TRUE":
        isWrapped = True
except BaseException:
    pass


# Setup signal handler
#signal.signal(signal.SIGTERM, sigterm_handler)

if not isWrapped:
    try:
        os.environ["PATH"] = BIN_PATH + ":" + os.environ["PATH"]
    except BaseException:
        os.environ["PATH"] = BIN_PATH

    try:
        os.environ[SysLibraryPathVar] = get_library_path() + ":" + \
            os.environ[SysLibraryPathVar]
    except BaseException:
        os.environ[SysLibraryPathVar] = get_library_path()

    if sys.platform == "darwin":
        os.environ[SysFrameworkPathVar] = get_framework_path()

    try:
        os.environ["PYTHONPATH"] = PYTHONPATH + ":" + os.environ["PYTHONPATH"]
    except BaseException:
        os.environ["PYTHONPATH"] = PYTHONPATH
    try:
        os.environ["MANPATH"] = MANPATH + ":" + os.environ["MANPATH"]
    except BaseException:
        os.environ["MANPATH"] = MANPATH

    os.environ["SEISCOMP_WRAP"] = "TRUE"

    sys.exit(system(sys.argv))

# Register local lib/python in SEARCH PATH
sys.path.insert(0, PYTHONPATH)

# Create environment which supports queries for various SeisComP
# directoris and sets PATH, LD_LIBRARY_PATH and PYTHONPATH
env = seiscomp.kernel.Environment(SEISCOMP_ROOT)
env.setCSVOutput(useCSV)

# Check for lock file
isChild = False

if action in actions_without_lock:
    isChild = True
else:
    try:
        isChild = os.environ["SEISCOMP_LOCK"] == "TRUE"
    except KeyError:
        pass

if not isChild:
    if not env.tryLock("seiscomp", lockTimeout):
        error("Could not get lock %s - is another process using it?" %
              env.lockFile("seiscomp"))
        sys.exit(1)

    os.environ["SEISCOMP_LOCK"] = "TRUE"
    exitcode = system(
        ["run_with_lock", "-q", env.lockFile("seiscomp")] + sys.argv)
    sys.exit(exitcode)


# Change into SEISCOMP_ROOT directory. The env instance will change
# back into the current working directory automatically if destroyed.
env.chroot()

simpleCommand = (action == "install-deps") or \
                (action == "print" and arguments == "env")

if not simpleCommand:
    config_mods = load_init_modules(INIT_PATH)
    mods = []
    for m in config_mods:
        if m.isConfigModule:
            continue
        mods.append(m)

sys.exit(run_action(action, arguments, argflags))
