#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys

from seiscomp import core, client


class InvApp(client.Application):

    def __init__(self, argc, argv):
        super().__init__(argc, argv)
        self.setDaemonEnabled(False)
        self.setMessagingEnabled(False)
        self.setDatabaseEnabled(True, False)
        self.setLoadInventoryEnabled(True)
        self.setLoadConfigModuleEnabled(False)
        self.setLoggingToStdErr(True)

    def validateParameters(self):
        if not super().validateParameters():
            return False

        # no database is needed when inventory is provided by SCML file
        if not self.isInventoryDatabaseEnabled():
            self.setDatabaseEnabled(False, False)

        return True

    def run(self):
        now = core.Time.UTC()
        lines = []
        inv = client.Inventory.Instance().inventory()
        nnet = inv.networkCount()
        for inet in range(nnet):
            network = inv.network(inet)
            print(f"working on network {network.code()}", file=sys.stderr)
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
                        line = (
                            f"{network.code()} {station.code()} {location.code()} "
                            f"{stream.code()} {stream.gain():g}"
                        )
                        lines.append(line)

        lines.sort()
        for line in lines:
            print(line)

        return True


def main():
    app = InvApp(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
