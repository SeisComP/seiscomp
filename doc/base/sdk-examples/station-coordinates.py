#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys
import traceback
from seiscomp import core, client, datamodel


class InvApp(client.Application):

    def __init__(self, argc, argv):
        client.Application.__init__(self, argc, argv)
        self.setMessagingEnabled(False)
        self.setDatabaseEnabled(True, False)
        self.setLoggingToStdErr(True)

    def validateParameters(self):
        try:
            if client.Application.validateParameters(self) is False:
                return False
            return True
        except Exception:
            traceback.print_exc()
            sys.exit(-1)

    def run(self):
        now = core.Time.GMT()
        try:
            lines = []
            dbr = datamodel.DatabaseReader(self.database())
            inv = datamodel.Inventory()
            dbr.loadNetworks(inv)
            nnet = inv.networkCount()
            for inet in range(nnet):
                net = inv.network(inet)
                dbr.load(net)
                nsta = net.stationCount()
                for ista in range(nsta):
                    sta = net.station(ista)
                    try:
                        elev = sta.elevation()
                    except Exception:
                        elev = float("NaN")
                    line = "{:2} {:5} {:9.4f} {:9.4f} {:6.1f}".format(
                        net.code(), sta.code(), sta.latitude(), sta.longitude(), elev)

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
        except Exception:
            traceback.print_exc()
            sys.exit(-1)


def main():
    app = InvApp(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
