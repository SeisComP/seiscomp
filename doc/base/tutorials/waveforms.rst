.. _tutorials_waveforms:

*****************************************************************
Get real-time data from a remote Seedlink server (single station)
*****************************************************************

You will use :program:`scconfig` to add waveforms for a single station
which is already in inventory.

Pre-requisites for this tutorial:

* :ref:`Installation<tutorials_postinstall>`
* Inventory for the station already loaded.

Afterwards/Results/Outcomes:

* :program:`slinktool -Q` locally shows the station's streams are available.

Time range estimate:

* 10 minutes

Related tutorial(s):

* :ref:`tutorials_archiving`
* :ref:`tutorials_servefdsnws`
* :ref:`tutorials_addstation`

----------

We suppose there is an upstream Seedlink server, such as that
from GEOFON, IRIS, or some other public source.


Check data are available
========================

First, we'll query the upstream Seedlink server,
to confirm that it has current data.
We do this with SeisComP's :program:`slinktool` command,
giving it the '-L' option to list the available stations.
For this example, we'll use the server at host `geofon.gfz-potsdam.de`
on port 18000 (the default) ::

  $ slinktool -L geofon.gfz-potsdam.de
  AW VNA1  VNA1
  AW VNA2  VNA2
  [..]
  GR BSEG  BSEG
  GR BUG   BUG
  GR CLL   CLL
  GR CLZ   CLZ
  [..]

This can be a long list. It shows the network code and station code of each
of the stations for which data is available from this Seedlink server.
We can restrict the output to our station of interest using `grep`. ::

  $ slinktool -Q geofon.gfz-potsdam.de | grep GR.CLL
  GR CLL      LHN D 2020/05/06 15:13:41.2249  -  2020/05/06 21:15:28.0299
  GR CLL      BHZ D 2020/05/06 15:13:41.2249  -  2020/05/06 21:22:13.1300
  GR CLL      BHN D 2020/05/06 15:13:41.2249  -  2020/05/06 21:22:15.4300
  GR CLL      HHE D 2020/05/06 15:13:41.2249  -  2020/05/06 21:22:50.3450
  GR CLL      HHN D 2020/05/06 15:13:41.2249  -  2020/05/06 21:22:52.4650
  GR CLL      HHZ D 2020/05/06 15:13:41.2249  -  2020/05/06 21:22:53.6850
  GR CLL      LOG L 2020/05/06 15:13:41.2249  -  2020/05/06 19:59:53.3850
  GR CLL      BHE D 2020/05/06 15:13:41.2249  -  2020/05/06 21:22:08.9300
  [..]

The '-Q' option provides a formatted stream list,
with one line for each stream available from the server.
The columns are: network code, station code, location code (which may
be empty) and channel code, a flag, and then the (UTC) time of the
first and last data available at the server.
(The `grep` command here is used to limit output to just those CLL streams;
without it, this server provides thousands of lines of output.)

For an active station the last data time (shown on the
right) will be very recent.


.. note::

   **(Advanced)**
   You can restrict who has access to a station's data (from your server)
   in your Seedlink bindings.
   This sets the :confval:`access` variable in your :file:`seedlink.ini` file.
   This can be done for all stations, or per station.
   The documentation for :program:`seedlink` gives details.


Configure bindings
==================

In :program:`scconfig`, under the Bindings tab:

1. Create a *seedlink* profile named "geofon", named after the upstream server.

   * Double click on the profile.
   * Select the 'chain' plugin for the souce from the drop-down menu
   * To add the plugin click on the green "plus" button on the left. Name it anything or even leave the name blank.
   * Open this and set the name of the server (:confval:`address`)
     and its TCP port, :confval:`port`. Normally you leave the port at 18000 which is the default.
   * If you wish to limit the data requested to particular channels,
     based on channel or location code,
     set Seedlink's :confval:`selectors <sources.chain.selectors>` to "BH?.D" say
     for fetch all BH stream and no auxiliary streams. Add the location code without
     a space to limit by location as well, e.g. 00BH?.D. You may add a comma-separated
     list of streams, e.g. "00BH?.D, 10BH?.D".
     Otherwise you will be requesting all streams available for this
     station, potentially wasting bandwidth and slowing your system.
     No other changes are normally necessary.

#. Drag and drop this profile from the right side to the network icon on the
   left side (you may do that also at the station level)
   to apply it to your station.

#. Press Ctrl+S to save the configuration.
   This writes configuration files in :file:`~/seiscomp/etc/key`.


Update the configuration
========================

The SeisComP database must already be updated with the inventory
(see Tutorial :ref:`tutorials_addstation`).
SeisComP's modules then require restarting to load the updated information.

* Go to the System tab and press ESC (the Escape key, to de-select all modules).

  #. Click on "Update configuration", at the right of the window.
     (**Not** "Refresh", - that just refreshes :program:`scconfig`'s
     display of what is running!)
  #. Press *Start* to start acquiring data from the already configured stations.

* Alternatively, at the command line::

    $ seiscomp update-config seedlink
    $ seiscomp restart seedlink


Check it works
==============

* To confirm that you have waveform data for the station locally,
  run ::

     slinktool -Q localhost


Further steps
=============

At this point,
you can follow the same procedure for other networks/stations, provided you

1. Have metadata available. You may follow the tutorial :ref:`tutorials_addstation`.
2. Know the location of a Seedlink server for, and have access to, the waveforms.
