#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys

from seiscomp import core, client


class ListStreamsApp(client.Application):

    def __init__(self, argc, argv):
        super().__init__(argc, argv)
        self.setDaemonEnabled(False)
        self.setMessagingEnabled(False)
        self.setDatabaseEnabled(True, True)
        self.setLoadStationsEnabled(True)
        self.setLoggingToStdErr(True)

    def validateParameters(self):
        if not super().validateParameters():
            return False

        # no database is needed when inventory is provided by an SCML file
        if not self.isInventoryDatabaseEnabled():
            self.setDatabaseEnabled(False, False)

        return True

    def run(self):
        now = core.Time.UTC()
        inv = client.Inventory.Instance().inventory()

        result = []

        for inet in range(inv.networkCount()):
            network = inv.network(inet)
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
                        result.append(
                            (
                                network.code(),
                                station.code(),
                                location.code(),
                                stream.code(),
                            )
                        )

        for net, sta, loc, cha in result:
            print(f"{net} {sta} {loc} {cha}")

        return True


def main():
    app = ListStreamsApp(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
