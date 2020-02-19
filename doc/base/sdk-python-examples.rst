.. _sdk-python-examples:

********
Examples
********

Simple messaging client
=======================

Summary
-------

Example client that connects to the messaging, listens for event
objects and dumps the event IDs.

Goal
----

Illustrate the basic messaging concepts.

Script
------

This script was demonstrated at the SeisComP workshop in Erice. It should be
relatively self-explanatory, but full understanding does require certain knowlege
of Python.

The script does nothing but

* connect to a SeisComP messaging server
* subscribe to messages sent to messaging group "EVENT"
* listen to these messages
* dump the event IDs to the screen

No actual real-world use case but a truly minimum example for a SeisComP
application.


.. code-block:: python

   import sys, traceback, seiscomp.client

   class EventListener(seiscomp.client.Application):

       def __init__(self):
           seiscomp.client.Application.__init__(self, len(sys.argv), sys.argv)
           self.setMessagingEnabled(True)
           self.setDatabaseEnabled(True, True)
           self.setPrimaryMessagingGroup(seiscomp.client.Protocol.LISTENER_GROUP)
           self.addMessagingSubscription("EVENT")

       def doSomethingWithEvent(self, event):
           try:
               #######################################
               #### Include your custom code here ####
               print "event.publicID = %s" % event.publicID()
               #######################################
           except:
               info = traceback.format_exception(*sys.exc_info())
               for i in info: sys.stderr.write(i)

       def updateObject(self, parentID, object):
           # called if an updated object is received
           event = seiscomp.datamodel.Event.Cast(object)
           if event:
               print "received update for event %s" % event.publicID()
               self.doSomethingWithEvent(event)

       def addObject(self, parentID, object):
           # called if a new object is received
           event = seiscomp.datamodel.Event.Cast(object)
           if event:
               print "received new event %s" % event.publicID()
               self.doSomethingWithEvent(event)

       def run(self):
           # does not need to be reimplemented. it is just done to illustrate
           # how to override methods
           print "Hi! The EventListener is now running."
           return seiscomp.client.Application.run(self)

   app = EventListener()
   sys.exit(app())

Note that the EventListener class is derived from the application class
seiscomp.client.Application from which it inherits most of the functionality.
For instance the ability to connect to the messaging and to the database are
both provided by seiscomp.client.Application; the EventListener only has to
enable messaging and database usage in the __init__ routine. The real action
takes place in the doSomethingWithEvent routine, which is called by both
updateObject and addObject, depending on whether the event object received is a
newly added or just and updated event.


Inventory examples
==================

Summary
-------

Various Python example scripts that retrieve inventory information from the
database.

Goal
----

Illustrate the usefulness of simple Python scripts to retrieve inventory
information.

Scripts
-------

The scripts in this section all deal with inventory access. All need to be
invoked with the :option:`-d` command line option to specify the SeisComP database
from which the information is to be read. For example:

.. code-block:: sh

   python configured-streams.py -d localhost

configured-streams.py
^^^^^^^^^^^^^^^^^^^^^

Print a list of all streams configured on a SeisComP system.

.. code-block:: python

   #!/usr/bin/env python

   import sys, traceback, seiscomp.client

   class ListStreamsApp(seiscomp.client.Application):

       def __init__(self, argc, argv):
           seiscomp.client.Application.__init__(self, argc, argv)
           self.setMessagingEnabled(False)
           self.setDatabaseEnabled(True, True)
           self.setLoggingToStdErr(True)
           self.setDaemonEnabled(False)
   #       self.setLoadInventoryEnabled(True)

       def validateParameters(self):
           try:
               if seiscomp.client.Application.validateParameters(self) == False:
                   return False
               return True

           except:
               info = traceback.format_exception(*sys.exc_info())
               for i in info: sys.stderr.write(i)
               sys.exit(-1)

       def run(self):
           try:
               dbr = seiscomp.datamodel.DatabaseReader(self.database())
               now = seiscomp.core.Time.GMT()
               inv = seiscomp.datamodel.Inventory()
               dbr.loadNetworks(inv)

               result = []

               for inet in xrange(inv.networkCount()):
                   network = inv.network(inet)
                   dbr.load(network);
                   for ista in xrange(network.stationCount()):
                       station = network.station(ista)
                       try:
                           start = station.start()
                       except:
                           continue

                       try:
                           end = station.end()
                           if not start <= now <= end:
                               continue
                       except:
                           pass

                       for iloc in xrange(station.sensorLocationCount()):
                           location = station.sensorLocation(iloc)
                           for istr in range(location.streamCount()):
                               stream = location.stream(istr)

                               result.append( (network.code(), station.code(), location.code(), stream.code()) )

               for net, sta, loc, cha in result:
                   print "%-2s %-5s %-2s %-3s" % (net, sta, loc, cha)

               return True

           except:
               info = traceback.format_exception(*sys.exc_info())
               for i in info: sys.stderr.write(i)
               sys.exit(-1)


   def main():
       app = ListStreamsApp(len(sys.argv), sys.argv)
       return app()

   if __name__ == "__main__":
       sys.exit(main())


station-coordinates.py
^^^^^^^^^^^^^^^^^^^^^^

Print the coordinates of all stations configured on a SeisComP system.

.. code-block:: python

   #!/usr/bin/env python

   import sys, seiscomp.client, seiscomp.datamodel

   class InvApp(seiscomp.client.Application):
       def __init__(self, argc, argv):
           seiscomp.client.Application.__init__(self, argc, argv)
           self.setMessagingEnabled(False)
           self.setDatabaseEnabled(True, True)
           self.setLoggingToStdErr(True)

       def validateParameters(self):
           try:
               if seiscomp.client.Application.validateParameters(self) == False:
                   return False

               return True

           except:
               info = traceback.format_exception(*sys.exc_info())
               for i in info: sys.stderr.write(i)
               sys.exit(-1)

       def run(self):
           now = seiscomp.core.Time.GMT()
           try:
               lines = []
               dbr = seiscomp.datamodel.DatabaseReader(self.database())
               inv = seiscomp.datamodel.Inventory()
               dbr.loadNetworks(inv)
               nnet = inv.networkCount()
               for inet in xrange(nnet):
                   net = inv.network(inet)
                   dbr.load(net);
                   nsta = net.stationCount()
                   for ista in xrange(nsta):
                       sta = net.station(ista)
                       line = "%-2s %-5s %9.4f %9.4f %6.1f" % ( net.code(), sta.code(), sta.latitude(), sta.longitude(), sta.elevation() )
                       try:
                           start = sta.start()
                       except:
                           continue

                       try:
                           end = sta.end()
                           if not start <= now <= end:
                               continue
                       except:
                           pass

                       lines.append(line)

               lines.sort()
               for line in lines:
                   print line

               return True
           except:
               info = traceback.format_exception(*sys.exc_info())
               for i in info: sys.stderr.write(i)
               sys.exit(-1)

   def main():
       app = InvApp(len(sys.argv), sys.argv)
       return app()

   if __name__ == "__main__":
       sys.exit(main())


channel-gains.py
^^^^^^^^^^^^^^^^

Print channel gains for all streams configured on a SeisComP system.

.. code-block:: python

   #!/usr/bin/env python

   import traceback, sys, seiscomp.client, seiscomp.datamodel

   class InvApp(seiscomp.client.Application):
       def __init__(self, argc, argv):
           seiscomp.client.Application.__init__(self, argc, argv)
           self.setMessagingEnabled(False)
           self.setDatabaseEnabled(True, True)
           self.setLoggingToStdErr(True)

       def validateParameters(self):
           try:
               if seiscomp.client.Application.validateParameters(self) == False:
                   return False

               return True

           except:
               info = traceback.format_exception(*sys.exc_info())
               for i in info: sys.stderr.write(i)
               sys.exit(-1)

       def run(self):
           now = seiscomp.core.Time.GMT()
           try:
               lines = []
               dbq = seiscomp.datamodel.DatabaseQuery(self.database())
               inv = seiscomp.datamodel.Inventory()
               dbq.loadNetworks(inv)
               nnet = inv.networkCount()
               for inet in xrange(nnet):
                   network = inv.network(inet)
                   sys.stderr.write("\rworking on network %2s" % network.code())
                   dbq.load(network);
                   nsta = network.stationCount()
                   for ista in xrange(nsta):
                       station = network.station(ista)
                       try:
                           start = station.start()
                       except:
                           continue

                       try:
                           end = station.end()
                           if not start <= now <= end:
                               continue
                       except:
                           pass

                       # now we know that this is an operational station
                       for iloc in xrange(station.sensorLocationCount()):
                           location = station.sensorLocation(iloc)
                           for istr in range(location.streamCount()):
                               stream = location.stream(istr)

                               line = "%-2s %-5s %-2s %-3s %g" % (network.code(), station.code(), location.code(), stream.code(), stream.gain())
                               lines.append(line)

               lines.sort()
               for line in lines:
                   print line

               return True
           except:
               info = traceback.format_exception(*sys.exc_info())
               for i in info: sys.stderr.write(i)
               sys.exit(-1)

   def main():
       app = InvApp(len(sys.argv), sys.argv)
       return app()

   if __name__ == "__main__":
       sys.exit(main())


Simple waveform client
======================

Summary
-------

Example client that connects to a RecordStream service and dumps the content
to stdout.

Goal
----

Illustrate the basic RecordStream concepts.

Script
------

.. code-block:: python

   #!/usr/bin/env python

   import seiscomp.client, sys

   class App(seiscomp.client.StreamApplication):
       def __init__(self, argc, argv):
           seiscomp.client.StreamApplication.__init__(self, argc, argv)
           # Do not connect to messaging and do not use database at all
           self.setMessagingEnabled(False)
           self.setDatabaseEnabled(False, False)


       def init(self):
           if seiscomp.client.StreamApplication.init(self) == False:
               return False

           # For testing purposes we subscribe to the last 5 minutes of data.
           # To use real-time data, do not define an end time and configure
           # a real-time capable backend such as Seedlink.

           # First, query now
           now = seiscomp.core.Time.GMT()
           # Substract 5 minutes for the start time
           start = now - seiscomp.core.TimeSpan(300,0)
           # Set the start time in our RecordStream
           self.recordStream().setStartTime(start)
           # And the end time
           self.recordStream().setEndTime(now)

           # Now add some streams to fetch
           self.recordStream().addStream("GE", "MORC", "", "BHZ")
           self.recordStream().addStream("GE", "MORC", "", "BHN")

           return True


       # handleRecord is called when a new record is being read from the
       # RecordStream
       def handleRecord(self, rec):
           # Print the streamID which is a join of NSLC separated with '.'
           print rec.streamID()
           # Print the records start time in ISO format
           print "  %s" % rec.startTime().iso()
           # Print the sampling frequency
           print "  %fHz" % rec.samplingFrequency()
           # If data is available
           if rec.data():
               # Print the number of samples
               print "  %d samples" % rec.data().size()
               # Try to extract a float array. If the samples are of other
               # data types, use rec.dataType() to query the type and use
               # the appropriate array classes.
               data = seiscomp.core.FloatArray.Cast(rec.data())
               # Print the samples
               if data:
                   print "  data: %s" % str([data.get(i) for i in xrange(data.size())])
               else:
                   print "  no data"

   def main():
       app = App(len(sys.argv), sys.argv)
       return app()

   if __name__ == "__main__":
       sys.exit(main())

The :option:`-I` command line option can be used to configure the record
stream backend when running the test application.

.. code-block:: sh

   python testrec.py -I slink://localhost:18000

or to ask Arclink for data

.. code-block:: sh

   python testrec.py -I arclink://localhost:18001


Waveform client and record filtering
====================================

Summary
-------

Example client that connects to a RecordStream service, filters the records
with a given SeisComp3 filter and dumps the content to stdout.

Goal
----

Illustrate the recordfilter concepts.

Script
------

.. code-block:: python

   #!/usr/bin/env python

   import seiscomp.client, sys

   class App(seiscomp.client.StreamApplication):
       def __init__(self, argc, argv):
           seiscomp.client.StreamApplication.__init__(self, argc, argv)
           # Do not connect to messaging and do not use database at all
           self.setMessagingEnabled(False)
           self.setDatabaseEnabled(False, False)

       def init(self):
           if seiscomp.client.StreamApplication.init(self) == False:
               return False

           # For testing purposes we subscribe to the last 5 minutes of data.
           # To use real-time data, do not define an end time and configure
           # a real-time capable backend such as Seedlink.

           # First, query now
           now = seiscomp.core.Time.GMT()
           # Substract 5 minutes for the start time
           start = now - seiscomp.core.TimeSpan(300,0)
           # Set the start time in our RecordStream
           self.recordStream().setStartTime(start)
           # And the end time
           self.recordStream().setEndTime(now)

           # Now add some streams to fetch
           self.recordStream().addStream("GE", "MORC", "", "BHZ")
           self.recordStream().addStream("GE", "MORC", "", "BHN")

           # Create IIR filter instance that deals with data (samples)
           filterIIR = seiscomp.math.InPlaceFilterF.Create("BW(4,1,10")
           if not filterIIR:
               seiscomp.logging.error("Failed to create filter")
               return False

           # Create a record filter that applies the given IIR filter to
           # each record fed. Deals with gaps and sps changes on record basis.
           self.recordFilter = seiscomp.io.RecordIIRFilterF(filterIIR)

           # Demultiplexes record volumes and runs the passed filter
           # on each stream.
           self.demuxer = seiscomp.io.RecordDemuxFilter(self.recordFilter)

           return True


       # handleRecord is called when a new record is being read from the
       # RecordStream
       def handleRecord(self, raw_rec):
           # Feed the raw record into the demuxer and filter it
           rec = self.demuxer.feed(raw_rec)
           if not rec: return

           # Print the streamID which is a join of NSLC separated with '.'
           print rec.streamID()
           # Print the records start time in ISO format
           print "  %s" % rec.startTime().iso()
                   # Print the sampling frequency
                   print "  %fHz" % rec.samplingFrequency()
                   # If data is available
                   if rec.data():
                       # Print the number of samples
                       print "  %d samples" % rec.data().size()
                       # Try to extract a float array. If the samples are of other
                       # data types, use rec.dataType() to query the type and use
                       # the appropriate array classes.
                       data = seiscomp.core.FloatArray.Cast(rec.data())
                       # Print the samples
                       if data:
                           print "  data: %s" % str([data.get(i) for i in xrange(data.size())])
                       else:
                           print "  no data"

   def main():
       app = App(len(sys.argv), sys.argv)
           return app()

   if __name__ == "__main__":
       sys.exit(main())
