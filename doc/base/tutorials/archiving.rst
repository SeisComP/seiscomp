.. _tutorials_archiving:

**********************
Set up local archiving
**********************

You will ...

* Set up :ref:`slarchive` with its necessary bindings.
* Set up `purge_datafiles` in crontab.

:Pre-requisites for this tutorial:
* :ref:`Tutorial on <tutorials_addstation>`
* :ref:`Tutorial on real time data<tutorials_geofon_waveforms>`,
  so that you have GE stations.
  Alternatively you may already obtain real-time waveform data from
  somewhere else.

:Afterwards/Results/Outcomes:
* See day files for GE stations in your local archive.

:Time range estimate:
* 5 minutes.

:Related tutorial(s):
* Tutorial on :ref:`tutorials_servefdsnws`
* Tutorial on :ref:`tutorials_waveformplayback`

----------

Motivation:
Without activating archiving, your local Seedlink server
will only keep waveforms for a short time.
This makes it hard to review old events, for example.

In this example, we'll arrange for keeping waveforms for one week.
Before starting, you'll need bindings for your stations
(see :ref:`tutorials_geofon_waveforms`).


In scconfig
===========

#. Under the Modules tab, go to Acquisition, and select "slarchive".
   Here you can see the default parameters used.
   By default, `slarchive` connects to your local Seedlink server,
   and archives to your local disk.

#. Under the System tab, select the line for slarchive, and click
   "Enable module(s)" button at the top.

#. Under Bindings:
   On RHS right-click "slarchive" to add an slarchive profile.
   Name it 'week', to keep waveforms for 7 days, and click 'Ok'.
   The new profile appears in the (bottom right corner of scconfig.
   Double click on the profile to open its settings.
   Unlock the box labeled "keep", and change the default from 30 to 7.

   Once you have a binding profile, drag it over all the stations it
   should apply to, under "Networks" on the left-hand side of the
   bindings tool.

.. warning:: The name "week" is just a label.
   Its functionality comes from changing the value of the `keep` parameter.
   Changing the *name* of a binding profile does not change its function.

.. note:: You can also choose which channels should be archived,
   using the "selectors" box.
   For instance, you may collect data at several sample rates,
   and only wish to archive the highest rate.
   (e.g. if you collect LH, BH, HH streams at 0.1, 20, and 100 samples
   per second respectively, you might retain only the HH streams,
   by setting "selectors" to "HH".)

#. Then return to System, and click 'Update configuration'.
   (Make sure the 'slarchive' module, or no module, is selected.)

#. Restart `slarchive`

Command line
============

You will need to edit each of your top-level key files to refer to
a new binding profile.
e.g.::

  $ cd ~/seiscomp/etc/key
  $ vi station_GE_APE

Add the line `slarchive:week` to whatever lines are already there.
Afterwards it will look something like this::

  # Binding references
  global:BH
  scautopick:default
  seedlink:geofon
  slarchive:week

Repeat this for each top-level key file (station_GE_ACRG, station_GE_ARPR,
and so on.)
Now create the binding profile in the key directory.
This is a file with a name corresponding to the binding profile name
(here "week")::

  $ cd ~/seiscomp/etc/key
  $ mkdir slarchive
  $ vi slarchive/profile_week
  # Number of days the data is kept in the archive. This requires purge_datafile
  # to be run as cronjob.
  keep = 7

  $ seiscomp enable slarchive
  $ seiscomp update-config slarchive
  $ seiscomp restart slarchive
  slarchive is not running
  starting slarchive


.. note ::

   Left unattended, your disk will eventually fill up with archived data.
   To prevent this you will need a script like `purge_database`,
   which is provided with SeisComP.
   This can be run once per day using the `cron` feature of your system.
   The command::

      $ seiscomp print crontab

   will print a number of lines to the terminal.
   Type `crontab -e` and insert these lines into the crontab file for your
   user (typically `sysop`).
   Exit your crontab editor.
   Displaying your crontab should now show a line for `purge_database`.::

     $ crontab -l
     20 3 * * * /home/sysop/seiscomp/var/lib/slarchive/purge_datafiles >/dev/null 2>&1
     [There may be other lines too.]

   This shows you that the `purge_datafiles` script
   will run every day at 3:20 a.m.

.. note ::

  If you examine the `purge_datafiles` script, you will see that all it does
  is look for files with a last modified time older than a certain number
  of days ago.
  The number of days to keep can be set station-by-station using the
  ARCH_KEEP feature.
  A convenient way to do this for many stations is with
  multiple binding profiles, one for each length of time desired.
