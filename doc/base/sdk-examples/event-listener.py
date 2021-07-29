#!/usr/bin/env seiscomp-python
# -*- coding: utf-8 -*-

import sys
import traceback
from seiscomp import client, datamodel
from seiscomp.client import Protocol


class EventListener(client.Application):

    def __init__(self, argc, argv):
        client.Application.__init__(self, argc, argv)
        self.setMessagingEnabled(True)
        self.setDatabaseEnabled(False, False)
        self.setPrimaryMessagingGroup(Protocol.LISTENER_GROUP)
        self.addMessagingSubscription("EVENT")
        self.setLoggingToStdErr(True)

    def doSomethingWithEvent(self, event):
        try:
            #################################
            # Include your custom code here #
            print("event.publicID = {}".format(event.publicID()))
            #################################
        except Exception:
            traceback.print_exc()

    def updateObject(self, parentID, scobject):
        # called if an updated object is received
        event = datamodel.Event.Cast(scobject)
        if event:
            print("received update for event {}".format(event.publicID()))
            self.doSomethingWithEvent(event)

    def addObject(self, parentID, scobject):
        # called if a new object is received
        event = datamodel.Event.Cast(scobject)
        if event:
            print("received new event {}".format(event.publicID()))
            self.doSomethingWithEvent(event)

    def run(self):
        # does not need to be reimplemented. it is just done to illustrate
        # how to override methods
        print("Hi! The EventListener is now running.")
        return client.Application.run(self)


def main():
    app = EventListener(len(sys.argv), sys.argv)
    return app()


if __name__ == "__main__":
    sys.exit(main())
