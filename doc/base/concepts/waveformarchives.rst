.. _concepts_waveformarchives:

*****************
Waveform archives
*****************

Scope
=====

This chapter describes waveform archives for long-term storage of miniSEED data.

Overview
========

While real-time data sources provide data for a rather short amount of time,
long-term access to waveforms can be established through waveform archives.
The :ref:`RecordStream interface <concepts_RecordStream>` allows a combined access
to real-time data and data in :ref:`SDS <concepts_sds>` or other archives.

.. note::

   It is assumed that instrument corrections applied to the recorded
   waveform data result in data in units of the real observations and their unmodified value.
   Therefore, it is recommended to store only unprocessed raw data in units of digital counts
   in the waveform archives and to provide the complete :ref:`inventory <concepts_inventory>`
   referring to input data given in counts.

.. _concepts_sds:

SDS archives
============

SeisComP uses the SeisComP Data Structure (SDS) for archiving miniSEED waveform data.
It has the structure:

.. code-block:: sh

   archive
     + year
       + network code
         + station code
           + channel code
             + one file per day and location, e.g. NET.STA.LOC.CHAN.D.YEAR.DOY

SeisComP ships with :ref:`slarchive` to create SDS archives from a miniSEED waveform
buffer by :ref:`seedlink` in real time and with :ref:`scart` to intergrate miniSEED
records from files into an SDS archive. :ref:`scart` can also be used to retrieve
miniSEED records from an SDS archive.

Access to waveform archives
===========================

Access from SeisComP processing and GUI modules to waveform archives is realized by
:ref:`RecordStream implementations <concepts_RecordStream>`.
The continuity of SDS archives can be monitored by :ref:`scardac` and exposed by
the :ref:`fdsnws availability feature <fdsnws>`.
miniSEED waveforms in SDS archives, can interactively retrieved using :ref:`scart`.
Waveforms stored in SDS archives can be served to clients, e.g. using :ref:`fdsnws`.

Related modules
===============

* :ref:`caps_plugin`
* :ref:`fdsnws`
* :ref:`scardac`
* :ref:`scart`
* :ref:`slarchive`
