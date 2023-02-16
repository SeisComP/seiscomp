from __future__ import print_function
import os, sys, subprocess as sub
import seiscomp.kernel, seiscomp.config

class Module(seiscomp.kernel.Module):
    def __init__(self, env):
      seiscomp.kernel.Module.__init__(self, env, env.moduleName(__file__))

    def start(self):
      cfg = seiscomp.config.Config()
      cfg.readConfig(os.path.join(self.env.SEISCOMP_ROOT, "etc", "defaults", self.name + ".cfg"))
      cfg.readConfig(os.path.join(self.env.SEISCOMP_ROOT, "etc", self.name + ".cfg"))
      try: cfg.readConfig(os.path.join(os.environ['HOME'], ".seiscomp", self.name + ".cfg"))
      except: pass

      run_dir = os.path.join(self.env.SEISCOMP_ROOT, "var", "run", self.name)
      try: os.makedirs(run_dir)
      except: pass

      # Set defaults
      threshold = 95
      emails = []

      try: threshold = cfg.getInt("threshold")
      except: pass
      try: emails = cfg.getStrings("emails")
      except: pass

      if len(emails) == 0:
        sys.stderr.write("%s: warning: nothing to do, no email addresses configured\n" % self.name)
        return 0

      cmd = 'df | awk -v max="%d" \'/[0-9]%%/ { use = $5; gsub("%%", "", use); if ( int(use) > max ) print $0; }\'' % threshold
      p = sub.Popen(['sh', '-c', cmd], stdout=sub.PIPE)
      msg = p.stdout.read().decode()

      statfile = os.path.join(run_dir, "msg_sent")

      if msg.find('\n') < 0:
        # Nothing to do
        try: os.remove(statfile)
        except: print("ERROR: could not remove stat file %s" % statfile)
        return 1

      # Message already sent?
      if os.path.exists(statfile):
        return 0

      try: hostname = os.uname()[1]
      except: hostname = 'unknown host'

      msg = "The following disks at %s are nearly full:\n\n" % hostname + msg
      try: open(statfile, "w")
      except: print("ERROR: could not create stat file in %s" % statfile)

      os.system('echo "%s" | mail -s "disk nearly full" %s' % (msg, " ".join(emails)))
      return 0


    def stop(self):
      return True
