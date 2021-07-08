#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys
import traceback
from seiscomp import core, client, datamodel


class InvApp(client.Application):

    def __init__(self, argc, argv):
        client.Application.__init__(self, argc, argv)
        self.setMessagingEnabled(False)
        self.setDatabaseEnabled(True, True)
        self.setLoggingToStdErr(True)

    def validateParameters(self):
        try:
            if not client.Application.validateParameters(self):
                return False

            return True

        except Exception:
            traceback.print_exc()
            sys.exit(-1)

    def run(self):
        now = core.Time.GMT()
        try:
            lines = []
            dbq = datamodel.DatabaseQuery(self.database())
            inv = datamodel.Inventory()
            dbq.loadNetworks(inv)
            nnet = inv.networkCount()
            for inet in range(nnet):
                network = inv.network(inet)
                sys.stderr.write("\rworking on network {:2}".format(network.code()))
                dbq.load(network)
                nsta = network.stationCount()
                for ista in range(nsta):
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

                    # now we know that this is an operational station
                    for iloc in range(station.sensorLocationCount()):
                        location = station.sensorLocation(iloc)
                        for istr in range(location.streamCount()):
                            stream = location.stream(istr)
                            line = "{:2} {:5} {:2} {:3} {:g}".format(
                                network.code(), station.code(), location.code(),
                                stream.code(), stream.gain())
                            lines.append(line)

            lines.sort()
            for line in lines:
                print(line)

            return True
        except Exception:
            traceback.print_exc()
            sys.exit(-1)


def main():
    app = InvApp(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
