.. _tutorials_upgrade:

******************
Upgrading SeisComP
******************

You will ...

* Upgrade a SeisComP system
* Migrate a SeisComP3 system to a newer SeisComP version

Pre-requisites for this tutorial:

* Tutorial on :ref:`installation <tutorials_postinstall>` and SeisComP previously installed

Afterwards/Results/Outcomes:

* Upgraded SeisComP

Time range estimate:

* 60 minutes

------------


Background
==========


SeisComP versions
-----------------

SeisComP has :ref:`developed over time <history>`. The versions can be distinguished
by the name of the release:

* **SeisComP since version 4.0.0** uses release version numbers
* **SeisComP3** uses release versions, names, numbers and patch numbers.

  Full example:  *SeisComP3-jakarta-2020.330.02*

  * 3: release version
  * jakarta: release name
  * 2020.330: release number
  * 02: patch number

  Names are adjusted depending on changes in source code:

  * **Release version:** major changes in module groups, functionality, concepts, data model.
    Example: SeisComp3 is SeisComP in version 3.0
    in comparison to version 2.5 the GUIs were introduced.
  * **Release name:** major changes in functionality, concepts, data model.
    Example: with SeisComP3-Seattle the new user friendly configuration GUI :ref:`scconfig`
    was introduced.
  * **Release number:** changes in data model version and/or major changes in applications and optimizations.
    The numbers include the year and the day of the year of the software release.
    Example: Jakarta-2018.327
  * **Patch number:** optimizations of applications without changes in the data model version.


Upgrade SeisComP on multiple machines
-------------------------------------

Applications can only connect to a messaging system that runs with a database
in an equal or lower data model version. Therefore, the SeisComP system which
operates the messaging system is always updated last.

**Example:** A distributed system
includes a processing system with the messaging system and database and a GUI work
station connected to the processing system:

#. Upgrade the GUI work station
#. Upgrade the processing system, take actions to
   :ref:`upgrade the database version <tutorials_upgrade_number>`.

.. note::

   Always stop all SeisComP modules before upgrading:

   .. code-block:: sh

      seiscomp stop


.. _tutorials_upgrade_changelog:

Package download
================

Get the latest or older SeisComP release packages from gempa GmbH or from the
download website of :cite:t:`seiscomp`.


Documentation of changes
========================

The important novelties, optimizations and changes that are available after upgrading
are documented in the change log.
It is recommend to read the change log before taking further actions. The details
can be found in the file

.. code-block:: sh

   $SEISCOMP_ROOT/share/doc/seiscomp/CHANGELOG

The change log can be directly accessed from the |scname| :ref:`documentation <sc-changelog>`
or from the *Docs* panel in :ref:`scconfig`.

.. note::

   New features are regularly advertised and described in detail on the
   `News website of gempa GmbH <https://www.gempa.de/news/>`_ and on the
   :cite:t:`seiscomp-forum`.


.. _tutorials_upgrade_number:

Upgrade to a higher release number
==================================

Installing a new SeisComP release or version is typically simple. **More actions** are
required when

* Upgrading :ref:`from SeisComP3 to SeisComP in version 4 or higher <tutorials_upgrade_v4>`.
* Upgrading :ref:`from SeisComP3 Jakarta-2018.327 or older to Jakarta-2020.330 or
  SeisComP in version 4 or higher <tutorials_upgrade_seedlink>`.

The normal upgrade takes only a few steps:

#. Download the SeisComP package
#. Stop all SeisComP modules: ::

      seiscomp stop

#. Install the new packages

   .. note::

      Users of external, e.g. |gempa| modules must ensure that the gempa modules
      match the SeisComP release version if they depend on SeisComP libraries.

#. When installing a new SeisComP release, upgrading the database may be required.
   The database version will be tested and the required actions will be shown when executing:

   .. code-block:: sh

      seiscomp update-config

   or when pressing the Update Configuration button in scconfig.
   An upgrade from version SeisComP3 jakarta-2017.334 to SeisComP in version 4.1.0
   will give, e.g.:

   .. code-block:: sh

      seiscomp update-config
      * starting kernel modules
      starting scmaster
      * configure kernel
      * configure scmaster
      INFO: checking DB schema version of queue: production
        * check database write access ... OK
        * database schema version is 0.10
        * last migration version is 0.11
        * migration to the current version is required. apply the following
          scripts in exactly the given order:
          * /home/sysop/seiscomp/share/db/migrations/mysql/0_10_to_0_11.sql
      error: updating configuration for scmaster failed

   The shown migration scripts can be used directly with the database command for upgrading:

   * MySQL / MariaDB: ::

        mysql -u sysop -p -D seiscomp -h localhost < /home/sysop/seiscomp/share/db/migrations/mysql/0_10_to_0_11.sql

   * PostgreSQL: ::

        psql -U sysop -d seiscomp -h localhost -W -f /home/sysop/seiscomp/share/db/migrations/postgresql/0_10_to_0_11.sql

   Using the migration scripts provides a more user friendly way than copying the
   lines of MySQL code from the changelog. In future versions we might add the option
   to automatically run the migrations.

   .. warning::

      Upgrading the database make take some time. Do no interrupt the process!
      During this time, the |scname| messaging system is unavailable causing a downtime of the system.

   After applying the migration scripts the database should be at the correct version.
   Test again with: ::

      seiscomp update-config

#. After a successful upgrade, start all modules again and observe the status: ::

      seiscomp start
      seiscomp status


.. _tutorials_upgrade_v4:

Migrate from SeisComP3 to version >=4
=====================================

SeisComP in version 4 has some major differences to SeisComP3 which require adjustments.
The main differences are in the :ref:`directories of the SeisComP installation <sec-tutorials_upgrading_path>`
and the :ref:`messaging system <sec-tutorials_upgrading_messaging>`.
The changes and the required actions are explained below. They must be considered
in addition to the steps set out in section :ref:`tutorials_upgrade_number`.


.. _sec-tutorials_upgrading_path:

Files and directories
---------------------

With **SeisComP3** all the default installation typically required all modules and configurations
in the directories

* seiscomp3/ , typically $HOME/seiscomp3 or /opt/seiscomp3/
* $HOME/.seiscomp3/

As of **SeisComP in version 4** the directories are:

* seiscomp/ , typically $HOME/seiscomp/ or /opt/seiscomp/
* $HOME/.seiscomp/

**All configuration files** must be migrated to the new structures. This
includes:

* Configurations and inventory in seiscomp3/:

  * seiscomp3/etc/\*.cfg
  * seiscomp3/etc/inventory/
  * seiscomp3/etc/keys/

* Configurations in $HOME/.seiscomp3/
* Logs in $HOME/.seiscomp3/log (optional)
* All user-defined files and directories in seiscomp3/share/
* All user-defined :ref:`seedlink` and other templates in seiscomp3/share/templates/
* The waveform archive and other archives typically in seiscomp3/var/lib/
* User-defined files and directories in other places.

  .. warning::

     Some configuration default and description files have changed. Spread, arclink
     and arclinkproxy are not part of |scname| anymore. **Therefore, do not migrate:**

     * any default configuration, description and init files. Better enable the desired
       daemon modules again:

       .. code-block:: sh

          seiscomp/bin/seiscomp enable [module]

     *   any file related to spread or the arclink and arclinkproxy servers.

Configurations containing absolute paths, e.g. :file:`/home/sysop/seiscomp3/share/scautoloc/grid_custom.conf`,
must be adjusted. Better use :ref:`internal SeisComP variables <concepts_configuration_variables>`
such as *@DATADIR@* instead of *seiscomp3/share* or *seiscomp/share*.


Software dependencies
---------------------

The software dependencies may have changed.
:ref:`Install the missing ones <software_dependencies>`.


System variables
----------------

The system environment variables must be updated, e.g. in :file:`$HOME/.bashrc`.
Remove or uncomment the lines  :file:`$HOME/.bashrc` referring to the depreciated SeisComP3
version. Then execute

.. code-block:: sh

   seiscomp/bin/seiscomp print env >> $HOME/.bashrc
   source $HOME/.bashrc


Pipelines
---------

When using pipelines or alias modules, create and enable the alias module names again, e.g.

.. code-block:: sh

   seiscomp alias create [alias] [module]
   seiscomp enable [alias]

Migrate the module and bindings configurations of the alias modules including all related additional files which are referred to
in the configurations.


.. _sec-tutorials_upgrading_messaging:

Messaging system
----------------

One of the main changes SeisComP3 to SeisComP in version 4.0 is the :ref:`messaging system <concepts_messaging>`.
Spread does not exist anymore and only :ref:`scmaster` is started initially for
the messaging system. :ref:`scmaster` allows to operate several queues in parallel with
different databases. This flexibility comes with additional parameters which require
configuration. Migrate the legacy database parameters and configure the new one:


#. Remove or comment the obsolete *dbplugin* plugin manually from
   :file:`scmaster.cfg` and :file:`global.cfg` ::

   # plugins = dbplugin

#. Set up the messaging queues in the configuration of :ref:`scmaster` in
   :file:`scmaster.cfg`.

   * Add and configure a new queue or stay with the default ones.

     * *production* considers a database by default.
     * *playback* considers no database by default. Here, parameters can be
       exchanged through the messaging without storing in the database.

     In the following examples, the *production* queue shall be assumed.

     .. note::

        The *production* queue is used by default by all modules connected
        to the messaging system. When removing this queue and a database shall be
        used, another queue must exist
        and the queue name must be configured for all modules in the global
        :confval:`connection.server` parameter. See below for an example.

     * Add the required plugins per queue. Currently only *dbstore* is supported.
       Example for the *production* queue:

       .. code-block:: sh

          queues.production.plugins = dbstore

     * Add non-default message groups, e.g. *L1PICK* and *L1LOCATION* to the list
       of groups **in one of the ways**:

       * Set :confval:`defaultGroups` ::

            defaultGroups = L1PICK, L1LOCATION, AMPLITUDE,PICK,LOCATION,MAGNITUDE,FOCMECH,EVENT,QC,PUBLICATION,GUI,INVENTORY,ROUTING,CONFIG,LOGGING,IMPORT_GROUP,SERVICE_REQUEST,SERVICE_PROVIDE

       * Set groups per queue in :confval:`queues.$name.groups`,
         ignoring groups in :confval:`defaultGroups` ::

          queues.production.groups = L1PICK, L1LOCATION, AMPLITUDE,PICK,LOCATION,MAGNITUDE,FOCMECH,EVENT,QC,PUBLICATION,GUI,INVENTORY,ROUTING,CONFIG,LOGGING,IMPORT_GROUP,SERVICE_REQUEST,SERVICE_PROVIDE

       * Add groups per queues to defaults in :confval:`queues.$name.groups`, e.g.
         for the *production* group.
         This convenient configuration per queue
         considers the default groups in :confval:`defaultGroups` and simply adds
         new groups in the configuration of queues ::

            queues.production.groups = ${defaultGroups}, L1PICK, L1LOCATION

       .. warning::

          When setting groups in the queues all groups configured in
          :confval:`defaultGroups` will be ignored unless `${defaultGroups}` is used.
          Add all groups from :confval:`defaultGroups` to the queues to keep the
          default groups.

     * Add the interface name, currently only *dbstore* is supported. Example for
       a queue names *production*

       .. code-block:: sh

          queues.production.processors.messages = dbstore

     * Add the database parameters which can be used from the legacy configuration

       .. code-block:: sh

          queues.production.processors.messages.dbstore.driver = mysql
          queues.production.processors.messages.dbstore.read = sysop:sysop@localhost/seiscomp3
          queues.production.processors.messages.dbstore.write = sysop:sysop@localhost/seiscomp3

       .. note::

          The name of the database can be freely chosen. The example assumes that
          the database named *seiscomp3* exists already and that it shall be continued
          to be used with the new SeisComP in version 4.x.x.

   * Add one or more of the queues to the :confval:`queues` parameter to register
     them by their names ::

        queues = production, playback


#. Configure the connection parameters of all modules connecting to the messaging
   system in the global configuration, e.g. in :file:`global.cfg`.
   As in SeisComP3 the connection server is
   localhost. The queue name is added to the host by "/". The default queue
   is *production*, e.g.

   .. code-block:: sh

      connection.server = localhost/production

   .. note::

      If *production* shall be used, then no additional configuration is required.


Database
--------

After adjusting the structure, variables and configuration parameters, check if the
:ref:`database requires an upgrade <tutorials_upgrade_number>` as well.


Seedlink
--------

When upgrading from SeisComp3 Jakrata-2018.327 or older and using :ref:`seedlink`,
consider the sections :ref:`tutorials_upgrade_seedlink` and
:ref:`tutorials_proc_seedlink`.


Automatic module check
----------------------

If applied, adjust the settings for automatic module status check, e.g. crontab entries.
For crontab use:

.. code-block:: sh

   crontab -e


System daemon
-------------

If |scname| is controlled by the system daemon, e.g. to start enabled |scname|
modules automatically during computer startup, then the startup script must be
adjusted.


Upgrade from SeisComP3 Jakarta-2018.327 or before
=================================================


.. _tutorials_upgrade_seedlink:

SeedLink buffer
---------------

In SeisComP3 prior to Jakarta-2020.330 two stations with the same
station but different network code were mixed in one buffer directory.
As of  Jakarta-2020.330 and SeisComP in version 4 the buffer directories are now
unique!
Before upgrading :ref:`seedlink`, you should therefore rename the buffer directories
accordingly.

.. warning::

   You may discover data gaps if you do not rename the buffer directories.

**Example:**

#. Check the current situation: ::

      sysop@host:~/seiscomp3/var/lib/seedlink/buffer$ ls
      PB02
#. Rename the directories properly:

   #. Stop seedlink: ::

         sysop@host:seiscomp stop seedlink

   #. Upgrade to SeisComP3-jakarta-2020.330 or SeisComP in version 4 or higher.
   #. Rename all seedlink buffer directories to NET.STA, e.g. ::

         sysop@host:~/seiscomp3/var/lib/seedlink/buffer$ mv PB02 CX.PB02
         sysop@host:~/seiscomp3/var/lib/seedlink/buffer$ ls
         CX.PB02

      .. note:

         The :ref:`script below <seedlink-buffer-script>` can be used for renaming the seedlink buffer directories.
   #. Update configuration: ::

         sysop@host:seiscomp update-config
   #. Start SeedLink ::

         sysop@host:seiscomp start seedlink

.. _seedlink-buffer-script:

Script for renaming the seedlink buffer directories:

.. code-block:: bash

   #!/bin/bash

   if [ -z ${SEISCOMP_ROOT+x} ]; then
           echo "Environment variable SEISCOMP_ROOT is not set."
           echo "Either use 'seiscomp exec [script]' or set SEISCOMP_ROOT to the installation "
        exit 1
        echo "path of your SeisComP installation."
   fi

   grep -A 2 ^station $SEISCOMP_ROOT/var/lib/seedlink/seedlink.ini | while read a b c; do
       if [ "$a" = station -a "$b" != .dummy ]; then
                id=$b
                sta=""
                net=""
                while read a b c; do
                        case $a in
                                --) break;;
                                name) eval sta=$c;;
                                network) eval net=$c;;
                        esac
                done
                if [ -z "$id" -o -z "$sta" -o -z "$net" ]; then
                        echo "Error parsing seedlink.ini"
                        break
                fi

                if [ "$id" != "$net.$sta" ]; then
                        mv -v "$SEISCOMP_ROOT/var/lib/seedlink/buffer/$id" "$SEISCOMP_ROOT/var/lib/seedlink/buffer/$net.$sta"
                else
                        echo "$id: No renaming required"
                fi
        fi
   done


.. _tutorials_proc_seedlink:

SeedLink stream processor
-------------------------

Since SeisComP3 in version Jakarta-2020.030 and SeisComP in version 4.0.0,
SeedLink stream processors (``proc`` parameter) can be attached to both, stations
and plugin instances. In order to distinguish between the two cases, either
``proc`` (attach to station) or ``sources.*.proc`` (attach to plugin instance)
parameter (or both) can be used in SeedLink bindings.


chain plugin
~~~~~~~~~~~~

In case of ``chain_plugin``, there is normally just one instance, so stream
processors attached to this instance apply to all stations. **This is normally
not what we want.** Therefore the chain_plugin does not support the
``sources.*.proc`` option.

Before SeisComP3 in version Jakarta-2020.030 and SeisComP in version 4.0.0,
stream processors were always attached to stations, even when ``sources.*.proc``
was used. This means when upgrading:

#. ``sources.chain.proc`` must be renamed to ``proc``
#. streams\_\*.tpl templates must be moved one level up, from
   :file:`$SEISCOMP_ROOT/seiscomp/share/templates/seedlink/chain/` to
   :file:`$SEISCOMP_ROOT/seiscomp/share/templates/seedlink/`.

.. note::

   Using a stream processor with chain_plugin makes only sense when raw
   data is generated (:confval:`sources.chain.channels.unpack`).


Background
~~~~~~~~~~

A stream processor is an object defined in XML, which is used to create MiniSEED
from raw data and optionally downsample the data. What is the difference between
attaching a stream processor to station and plugin instance?

Let's take a look at the following stream processor definition in
:file:`$SEISCOMP_ROOT/share/templates/seedlink/streams_stream100.tpl`:

.. code-block:: XML

   <proc name="stream100">
     <tree>
       <input name="Z" channel="Z" location="" rate="100"/>
       <input name="N" channel="N" location="" rate="100"/>
       <input name="E" channel="E" location="" rate="100"/>
       <node filter="FS2D5" stream="BH">
         <node filter="F96C">
           <node filter="ULP" stream="LH">
             <node filter="VLP" stream="VH"/>
           </node>
         </node>
       </node>
     </tree>
   </proc>

This creates 20Hz BH\*, 1Hz LH\* and 0.1Hz VH\* streams from 100Hz Z, N, E raw
data. If one plugin instance is used for the station, it does not make a
difference whether this is attached to station or plugin instance. But suppose
the station is using two plugin instances—one for broad-band and the other for
strong-motion data—, both sending Z, N and E channels. Now if the stream processor
is attached to station, data from both plugin instances would mixed up. We must
attach a different stream processor to each plugin instance—one producing BH\*,
LH\* and VH\* and the other one producing BN\* and so on.
