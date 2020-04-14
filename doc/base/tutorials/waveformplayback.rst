.. _tutorials_waveformplayback:

****************************
Play back archived waveforms
****************************

You will ...

* Use previously recorded waveform files to re-run the analysis
  of an old event using SeisComP. This is known as a *waveform playback*
* Use your current inventory, configuration and station bindings
* Inserts result into your current SeisComP database for later processing

Pre-requisites for this tutorial:

*  None

Afterwards/Results/Outcomes:

* The event is in your SeisComP system, with a new event ID

Time range estimate:

* 60 minutes

----------

Playbacks are an important way of testing network configuration
(choice of stations and streams used) and the SeisComp settings
used for locating events
(:program:`scautopick` and :program:`scevent` parameters).


General set-up
==============

For a playback, you need

#. Stations with inventory in the database.
   (See tutorial on :ref:`tutorials_geofon_waveforms`)
#. Station configuration via bindings.
#. Recorded waveforms in an :term:`SDS` archive.
   (See :ref:`tutorials_archiving`.)

Set up SeisComP with CX + GE networks
=====================================

For this playback we will pick on 100 Hz (HH*) streams from stations in the GE and CX networks.
Some of these stations use location code "10" for HH streams.
The SeisComP system needs to know which stream to work with for each station.
In :program:`scconfig` go to "Bindings".
Create two profiles in global giving descriptive names, e.g.:

* global/__HH
* global/10HH

Set detecStream=HH in both.
Leave detecLocid empty in the first, and set it to "10" in the second.
Bind both profiles to networks CX and GE.

Next we need to configure the picker. We start with a default configuration, which is suitable for teleseismic monitoring.

Add another profile:

* scautopick/teleseismic

No further configuration, just use the defaults.
Bind the scautopick/teleseismic profile to networks CX and GE, save the configuration and update the configuration in the database
(in :program:`scconfig`: System -> Update configuration).

At this point you are ready to run the playback as described below.

Final tests
===========

* In :program:`scolv`, the event is visible.
