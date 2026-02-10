#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys

from seiscomp import core, client


class InvApp(client.Application):

    def __init__(self, argc, argv):
        super().__init__(argc, argv)
        self.setDaemonEnabled(False)
        self.setMessagingEnabled(False)
        self.setDatabaseEnabled(True, True)
        self.setLoadInventoryEnabled(True)
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
            net = inv.network(inet)
            nsta = net.stationCount()
            for ista in range(nsta):
                sta = net.station(ista)
                try:
                    elev = sta.elevation()
                except Exception:
                    elev = float("NaN")
                line = (
                    f"{net.code()} {sta.code()} {sta.latitude():9.4f} "
                    f"{sta.longitude():9.4f} {elev:6.1f}"
                )

                try:
                    start = sta.start()
                except Exception:
                    continue
                try:
                    end = sta.end()
                    if not start <= now <= end:
                        continue
                except Exception:
                    pass

                lines.append(line)

        lines.sort()
        for i, line in enumerate(lines):
            print(i, line)

        return True


def main():
    app = InvApp(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
