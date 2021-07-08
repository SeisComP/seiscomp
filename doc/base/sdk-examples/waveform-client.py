#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys
from seiscomp import core, client


class App(client.StreamApplication):

    def __init__(self, argc, argv):
        client.StreamApplication.__init__(self, argc, argv)
        # Do not connect to messaging and do not use database at all
        self.setMessagingEnabled(False)
        self.setDatabaseEnabled(False, False)

    def init(self):
        if not client.StreamApplication.init(self):
            return False

        # For testing purposes we subscribe to the last 5 minutes of data.
        # To use real-time data, do not define an end time and configure
        # a real-time capable backend such as Seedlink.

        # First, query now
        now = core.Time.GMT()
        # Substract 5 minutes for the start time
        start = now - core.TimeSpan(300, 0)
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
        print(rec.streamID())
        # Print the records start time in ISO format
        print("{:s}".format(rec.startTime().iso()))
        # Print the sampling frequency
        print("{:f} Hz".format(rec.samplingFrequency()))
        # If data is available
        if rec.data():
            # Print the number of samples
            print("  {:d} samples".format(rec.data().size()))
            # Try to extract a float array. If the samples are of other
            # data types, use rec.dataType() to query the type and use
            # the appropriate array classes.
            data = core.FloatArray.Cast(rec.data())
            # Print the samples
            if data:
                print("  data: {:s}".format(str([data.get(i) for i in range(data.size())])))
            else:
                print("  no data")


def main():
    app = App(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
