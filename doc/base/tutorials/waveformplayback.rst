.. _tutorials_waveformplayback:

****************************
Play back archived waveforms
****************************

You will ...

* Use previously recorded waveform files to re-run the analysis
  of an old event using SeisComP. This is known as a *waveform playback*
* Inserts result into your current SeisComP database for later processing

Pre-requisites for this tutorial:

* Have SeisComP installed and configured
* Have access to :term:`miniSEED` waveforms

Afterwards/Results/Outcomes:

* The results from the playback are in your SeisComP system, e.g. :term:`picks <pick>`,
  :term:`origins <origin>`, :term:`amplitudes <amplitude>`, :term:`events <event>`

Time range estimate:

* 60 minutes

Related tutorial(s):

* Tutorial on :ref:`getting help <tutorials_help>`

----------

Playbacks are an important way of testing module and whole-sytem configuration,
operator trainings, system demonstrations and validations and tuning of the SeisComp modules
used for detecting and locating events, e.g. involving

* :ref:`scautopick`
* :ref:`scautoloc`
* :ref:`scamp`
* :ref:`scmag`
* :ref:`scevent`
* others.

Playbacks rely on miniSEED data which are obtained from the :term:`SDS` archive or
other sources. The miniSEED data records in the data files must be sorted by end time!

There are two types of playbacks:

* :ref:`Real-time playbacks <_tutorials_rtplayback>`
* :ref:`Non-real-time playbacks <_tutorials_rtplayback> or offline-playbacks`

Data preparation
================

First extract the data. Make sure the miniSEED records are sorted by end-time.
The data extraction depends on the data source.

* Extract the data from your own SDS archive using :ref:`scart` and save in new
  miniSEED file, sorted by end-time. The resulting
  file :file:`[your miniSEED file]` can be used for the playback.

  Example:

  .. code-block:: sh

     scart -dsEv -t '[start-time]~[end-time]' $SEISCOMP_ROOT/var/lib/archive > [your miniSEED file]

* Get the miniSEED data from an external FDSNWS server. The obtained data are
  initially sorted by station and must therefore be sorted by end time. The resulting
  file :file:`[your miniSEED file]` can be used for the playback.

  Example for 1 hour of data from the GE network from `FDSNWS at GEOFON`_:

  .. code-block:: sh

     wget -O data.mseed "https://geofon.gfz-potsdam.de/fdsnws/dataselect/1/query?net=GE&cha=BH*&starttime=2020-04-01T06:00:00Z&endtime=2012-06-04T07:00:00Z"
     scmssort -u -E data.mseed > [your miniSEED file]

* To extract the data from gempa's `CAPS server`_ use `capstool`_ together with :ref:`scmssort`.

Playbacks
=========

.. _tutorials_rtplayback:

Real-time playbacks
-------------------

In a real-time playback data are injected into the seedlink buffer from a file
using the command-line tool :ref:`msrtsimul`. Therefore, seedlink requires a configuration.

#. Prepare :ref:`seedlink` to except data from msrtsimul:

   * In the :ref:`module configuration <concepts_configuration>`
     of seedlink set

     .. code-block:: sh

        msrtsimul = true

   * Save the configuration, update the configuration and restart seedlink:

     .. code-block:: sh

        seiscomp update-config
        seiscomp restart seedlink

     Open :scrttv: to verify the success of this re-configuration. No new data must arrive.

#. Start all automatic data processing modules you wish to involve, e.g.

   .. code-block:: sh

      seiscomp start scmaster scautopick scautoloc scamp scmag scevent

#. Start all desired :term:`GUI` modules to observe the data acquisition and processing
   and the event results, e.g.:

   .. code-block:: sh

      scrttv & scmv & scesv & scolv

#. Start the playback using msrtsimul:

   .. code-block:: sh

      msrtsimul -v [your miniSEED file]

   This will play back the data as if they where perfectly recorded and received now.
   To preserve the time of the records use

   .. code-block:: sh

      msrtsimul -v -m historic [your miniSEED file]

Revert the seedlink configuration after the playback to return to the original real-time
data acquisition.

.. warning::

   Be careful with executing real-time playbacks on production SeisComP systems:

   * You potentially disrupt the real-time data acquisition
   * You potentially add data at wrong times to seedlink and your SDS waveform archive
   * You modify the history of the created events
   * You potentially add events at wrong origin times to your database.

   Better use separate test systems for real-time playbacks.

.. _tutorials_nonrtplayback:

Non-real-time playbacks
-----------------------

In non-real-time playbacks, also referred to as offline playbacks, data are processed
by each module as fast as possible. The results can be communicated by

* Messages: message-based offline playback
* XML files in :term:`SCML` format: XML playback. They require the processing
  modules to provide the *--ep* option.

.. warning::

   In non-real-time playbacks scheduling and the creation history is not representative of
   real-time situations.

Reviewing results
=================

Use :ref:`scolv` or other :term:`GUIs <GUI>` to review the results:

*  Event parameters are in the default database and the waveforms are in the default :term:`SDS` archive:

   .. code-block:: sh

      scolv -d mysql://sysop:sysop@localhost/seiscomp3 -I sdsarchvive:///home/sysop/seiscomp3/var/lib/archive

*  Event parameters are in the default database but the waveforms are read from the miniSEED file:

   .. code-block:: sh

      scolv -d mysql://sysop:sysop@localhost/seiscomp3 -I file://[your file]

*  Event parameters are available in one XML file and the waveforms are read from the miniSEED file:

   .. code-block:: sh

      scolv --offline -d mysql://sysop:sysop@localhost/seiscomp3 -I file://[your miniSEED file]

   To open the XML file click on the *File* menu of scolv. When results are available in several
   XML files, the files can be merged beforehand using :ref:`scxmlmerge`.

.. note::

   Adjust the arguments to match your configuration. Use your own values for arguments enclosed by
   brackets, e.g. [your file]

References
==========

.. target-notes::

.. _`FDSNWS at GEOFON` : https://geofon.gfz-potsdam.de/waveform/webservices.php
.. _`CAPS server` : https://www.gempa.de/products/caps/
.. _`capstool` : https://docs.gempa.de/caps/current/apps/capstool.html
