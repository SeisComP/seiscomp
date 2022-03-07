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

This script was demonstrated at the |scname| workshop in Erice. It should be
relatively self-explanatory, but full understanding does require certain knowlege
of Python.

The script does nothing but

* connect to a |scname| messaging server
* subscribe to messages sent to messaging group "EVENT"
* listen to these messages
* dump the event IDs to the screen

event-listener.py
^^^^^^^^^^^^^^^^^^^^^^

No actual real-world use case but a truly minimum example for a |scname| application.

.. literalinclude:: sdk-examples/event-listener.py

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
invoked with the command-line ``-d`` option to specify the |scname| database
from which the information is to be read. For example:

.. code-block:: sh

   python configured-streams.py -d localhost

configured-streams.py
^^^^^^^^^^^^^^^^^^^^^

Print a list of all streams configured on a |scname| system.

.. literalinclude:: sdk-examples/configured-streams.py

station-coordinates.py
^^^^^^^^^^^^^^^^^^^^^^

Print the coordinates of all stations configured on a |scname| system.

.. literalinclude:: sdk-examples/station-coordinates.py

channel-gains.py
^^^^^^^^^^^^^^^^

Print channel gains for all streams configured on a |scname| system.

.. literalinclude:: sdk-examples/channel-gains.py


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

waveform-client.py
^^^^^^^^^^^^^^^^^^

.. literalinclude:: sdk-examples/waveform-client.py

The command-line option ``-I`` can be used to configure the record
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
with a given |scname| filter and dumps the content to stdout.

Goal
----

Illustrate the recordfilter concepts.

Script
------

waveform-filter.py
^^^^^^^^^^^^^^^^^^

.. literalinclude:: sdk-examples/waveform-filter.py
