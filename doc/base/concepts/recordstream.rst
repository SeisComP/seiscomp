.. _concepts_RecordStream:

************
RecordStream
************

Scope
=====

This document describes the RecordStream interface for accessing waveform data.

Overview
========

A RecordStream refers to the interface which allows to retrieve records
(time series) from arbitrary sources. An implementation can either be real-time
and stream records continuously or time window based and just deliver what is
available at the time of requesting data.
A comprehensive list of RecordStream implementations is available in the
:ref:`technical documentation <global_recordstream>`.

RecordStream implementations have a name such as "slink", "fdsnws" or "file"
which is used as scheme in the configuration URL. The location part of the URL
is passed to the implementation. The scheme part is used to create the
implementation. As one might have noticed, that RecordStream
implementations can be added to existing applications with plugins.

What do they do actually?

Well, first of all they connect to or open the data source. If that fails, an
error is logged. Then they are configured with time windows and channel
identifieres. Once done, they are simply asked for new records in a loop. A
RecordStream implementation can run forever or finish after a short time.
The behavior depends on the implementation and configuration.

The application uses RecordStreams like that:

.. code-block:: python

   # The RecordStream URL passed is slink://localhost:18000
   scheme = URL.scheme()     # scheme = 'slink'
   location = URL.location() # location = 'localhost:18000'
   rs = RecordStream.Create(scheme)
   if not rs:
       throw Error()
   if not rs.setSource(location):
       throw Error()

   rs.setStartTime(Time(2019,1,1))
   rs.addStream('GE', 'UGM', '', 'BH?')
   rs.addStream('GE', 'MORC', '', 'BH?')

   while ( rec = rs.next() )
       do_something_with(rec)

In the example above the end time is not set, so actually an open time window
should be read. That works pretty well for the Seedlink implemtation but the
FDSNWS implementation would complain and issue an error because no end time
was set. So configuring a RecordStream for an application requires some
knowledge of the context and the supported features of the configured
implementation.

Although |scname| ships with the Seedlink server, the processing application
are not aware of the fact that they connect to Seedlink. All time series
retrieval is done with the RecordStream concept. There is no knowledge about
the underlying implementation. This leads to a high flexibility and
implementations can be added without the need to modify the base |scname|
sources.
