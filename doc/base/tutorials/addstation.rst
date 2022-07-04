.. _tutorials_addstation:

*****************
Add a new station
*****************

This tutorial guides you through the most common activities
involved in configuring a single new station in your existing SeisComP system.
Depending on your needs, you will use parts of other tutorials to do this.

Pre-requisites for this tutorial:

* :ref:`tutorials_postinstall`
* An understanding of :ref:`concepts_inventory`.

You may also need to consult

* :ref:`tutorials_waveforms`
* :ref:`tutorials_processing`
* :ref:`tutorials_archiving`

Afterwards/Results/Outcomes:

* Optionally, data for the new station are acquired and archived in real time.
* Optionally, the new station is used for automatic real-time data processing.

Time range estimate:

* Variable

----------

Before you start
================

Try to answer the questions:

* where will you get data?
* if you want to process data locally, where will you get inventory?
* which data will you share?
* how long will you archive, and what streams?

For this example, we'll add the GRSN Station Collm (CLL)
from the GR network.

* If you want to process data on this system, you will need
  inventory (metadata).
  Metadata can be obtained from many different sources or created from scratch.
* If you don't want to process on this system, you won't need inventory,
  but you will have to create key file by hand for acquisition and archiving.


Obtaining inventory for your station
====================================

For processing, you will need inventory for the new station.
How to obtain this will vary.
You can fetch inventory from:

* Other SeisComP systems. Use :ref:`scxmldump` to fetch inventories.
* EIDA nodes :cite:p:`eida`. Use web interfaces such as web browsers or `wget`
  to fetch an inventory.
* Data centers providing :cite:t:`fdsn`. Use web interfaces such as web browsers
  or `wget` to fetch an inventory.
* Your own or shared user repositories on :cite:t:`smp`.


.. note:: Create and share inventories

   gempa's :cite:t:`smp` is a tool for creating inventory from scratch and
   community sharing. Create inventories for new or old networks and stations
   from permanent or temporary deployments.
   SMP provides inventories in :term:`SCML` format in multiple versions
   which can be used without modification.


Configuring inventory
=====================

Suppose that, by one of the methods above,
we have it in a single file, :file:`inventory_CLL.xml`.
This must be converted from StationXML to SeisComP XML.
The resulting file goes into
:file:`~/seiscomp/etc/inventory`.
See the chapter on :ref:`concepts_inventory`.

.. code:: bash

   ~/seiscomp/bin/seiscomp exec import_inv  fdsnxml ~/inventory_CLL.xml
   Generating output to /home/user/seiscomp/etc/inventory/inventory_CLL.xml
   No inventory read from inventory db
   Create empty one
   Processing /home/user/inventory_CLL.xml
    - parsing StationXML
    - converting into SeisComP-XML
   Finished processing
   Writing inventory to /home/user/seiscomp/etc/inventory/inventory_CLL.xml

When inventory is loaded, you will see your station in the results
of :ref:`scinv` with the `ls` option:

.. code-block:: sh

    $ ~/seiscomp/bin/seiscomp exec scinv ls
    WARNING: /home/user/seiscomp/etc/inventory/README ignored: wrong extension
    [..]
    Parsing /home/user/seiscomp/etc/inventory/MY.xml ... done
    Parsing /home/user/seiscomp/etc/inventory/GE.xml ... done
    [..]
    Merging inventory ... done
      network GR       German Regional Seismic Network, BGR Hannover
        epoch 1976-02-17
        station CLL    GRSN Station Collm
          epoch 1993-04-01
          location __
            epoch 2007-02-07
            channel BHE
              epoch 2007-02-07
            channel BHN
              epoch 2007-02-07
            channel BHZ
              epoch 2007-02-07
            channel HHE
              epoch 2007-02-07

This shows the networks, stations, and channels, and the time spans for
which they are known.
For active stations, there must be an epoch (time span) with a start date
but no end date shown for the desired channel.

The inventory is not yet synchronized with the database. To finalize
inventory configuration, run::

  $ seiscomp update-config

.. warning::

  If you get an error, make sure that MySQL/MariaDB is running and the
  database has been created correctly (see :ref:`tutorials_postinstall`).


Configuring for acquisition
===========================

If you've configured inventory above, you'll already have a top-level
key file for the station in the :file:`~/seiscomp/etc/key` directory.

- You will need to know the waveform source, channels to be acquired,
  location code used, if any.
  See :ref:`tutorials_waveforms` for the remaining details.


Configuring processing
======================

Now you can enable the station for processing.
Follow the :ref:`tutorials_processing` tutorial.


Configuring for archiving
=========================

If you want to archive waveforms, consider how long they should be retained.
See :ref:`tutorials_archiving` for how to do this.
