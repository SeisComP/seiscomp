#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys
import traceback
from seiscomp import core, client, datamodel


class ListStreamsApp(client.Application):

    def __init__(self, argc, argv):
        client.Application.__init__(self, argc, argv)
        self.setMessagingEnabled(False)
        self.setDatabaseEnabled(True, False)
        self.setLoggingToStdErr(True)
        self.setDaemonEnabled(False)
#       self.setLoadInventoryEnabled(True)

    def validateParameters(self):
        try:
            if not client.Application.validateParameters(self):
                return False
            return True
        except Exception:
            traceback.print_exc()
            sys.exit(-1)

    def run(self):
        try:
            dbr = datamodel.DatabaseReader(self.database())
            now = core.Time.GMT()
            inv = datamodel.Inventory()
            dbr.loadNetworks(inv)

            result = []

            for inet in range(inv.networkCount()):
                network = inv.network(inet)
                dbr.load(network)
                for ista in range(network.stationCount()):
                    station = network.station(ista)
                    try:
                        start = station.start()
                    except Exception:
                        continue

                    try:
                        end = station.end()
                        if not start <= now <= end:
                            continue
                    except Exception:
                        pass

                    for iloc in range(station.sensorLocationCount()):
                        location = station.sensorLocation(iloc)
                        for istr in range(location.streamCount()):
                            stream = location.stream(istr)
                            result.append((network.code(), station.code(),
                                           location.code(), stream.code()))

            for net, sta, loc, cha in result:
                print("{:2} {:5} {:2} {:3}".format(net, sta, loc, cha))

            return True

        except Exception:
            traceback.print_exc()
            sys.exit(-1)


def main():
    app = ListStreamsApp(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
