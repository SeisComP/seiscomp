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

SeisComP has :ref:`developed over time <history>`. The versions can be distinguished:

* SeisComP since version 4.0.0 uses release version numbers
* SeisComP3 uses release versions, names, numbers and patch numbers:

  * **Release version:** major changes in module groups, functionality, concepts, data model.
    Example: SeisComp3 is SeisComP in version 3.0
    in comparison to version 2.5 the GUIs were introduced.
  * **Release name:** major changes in functionality, concepts, data model.
    Example: with SeisComP3-Seattle the new user friendly configuration GUI scconfig
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
`SeisComP package downloader`_.


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
   `News website of gempa GmbH`_ and on the `SeisComP forum`_.


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

        mysql -u sysop -p -D seiscomp -e 'source /home/sysop/seiscomp/share/db/migrations/mysql/0_10_to_0_11.sql;'

   * PostgreSQL: ::

        psql -U sysop -d seiscomp -h localhost -W
        \i'seiscomp/share/db/migrations/postgresql/0_10_to_0_11.sql'

   Using the migration scripts provides a more user friendly way than copying the
   lines of MySQL code from the changelog. In future versions we might add the option
   to automatically run the migrations.

   .. warning::

      Upgrading the database make take some time. Do no interrupt the process!
      During this time, the SeisComP messaging system is unavailable causing a downtime of the system.

   After applying the migration scripts the database should be at the correct version.
   Test again with: ::

      seiscomp update-config

#. After a successful upgrade, start all modules again and observe the status: ::

      seiscomp start
      seiscomp status


.. _tutorials_upgrade_seedlink:

Upgrade from SeisComP3 Jakarta-2018.327 or before
=================================================

:ref:`seedlink`: In SeisComP3 prior to Jakarta-2020.330 two stations with the same
station but different network code were mixed in one buffer directory.
As of  Jakarta-2020.330 and SeisComP in version 4 the buffer directories are now unambiguous!
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


.. _tutorials_upgrade_v4:

Migrate from SeisComP3 to version 4
===================================

SeisComP in version 4 has some major differences to SeisComP3 which require adjustments.
The main differences are in the :ref:`directories of the SeisComP installation <sec-tutorials_upgrading_path>`
and the :ref:`messaging system <sec-tutorials_upgrading_messaging>`.


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
     and arclinkproxy are not part of SeisComP anymore. **Therefore, do not migrate:**

     * any default configuration, description and init files. Better enable the desired
       daemon modules again.

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

#. Set up the messaging queues in the configuration of :ref:`scmaster` in :file:`scmaster.cfg`.

   * Remove or comment the obsolete *dbplugin* plugin manually from :file:`scmaster.cfg`: ::

        #plugins = dbplugin

   * Add new queue or stay with the default queues.

     .. note::

        The **default queue is production** used by default by all modules connected
        to the messaging system. When removing this queue, another queue must exist
        and the queue name must be configured for all modules in the connection parameters.
        See below for an example.

   * Add the required plugins, currently only *dbstore* is supported. Example for
     a queue named *production*:

     .. code-block:: sh

        queues.production.plugins = dbstore

   * Add non-default message groups to the list of default groups in
     :confval:`defaultGroups`, e.g. for adding the groups *L1PICK* and *L1LOCATION* set ::

        defaultGroups = L1PICK, L1LOCATION, AMPLITUDE,PICK,LOCATION,MAGNITUDE,FOCMECH,EVENT,QC,PUBLICATION,GUI,INVENTORY,ROUTING,CONFIG,LOGGING,IMPORT_GROUP,SERVICE_REQUEST,SERVICE_PROVIDE

     or use the configuration of queues, e.g. ::

        queues.production.groups = L1PICK, L1LOCATION, AMPLITUDE,PICK,LOCATION,MAGNITUDE,FOCMECH,EVENT,QC,PUBLICATION,GUI,INVENTORY,ROUTING,CONFIG,LOGGING,IMPORT_GROUP,SERVICE_REQUEST,SERVICE_PROVIDE

     The configured groups will be available for all other connected modules in this queue
     in addition to the default groups.

     .. warning::

        When setting groups in the queues all groups configured in
        :confval:`defaultGroups` will be ignored. Add all groups from :confval:`defaultGroups`
        to the queues to keep the default groups.

   * Add the interface name, currently only *dbstore* is supported. Example for
     a queue names *production*

     .. code-block:: sh

        queues.production.processors.messages = dbstore

   * Add the database parameters which can be used from the legacy configuration. E.g.

     .. code-block:: sh

        queues.production.processors.messages.dbstore.driver = mysql
        queues.production.processors.messages.dbstore.read = sysop:sysop@localhost/seiscomp3
        queues.production.processors.messages.dbstore.write = sysop:sysop@localhost/seiscomp3

     .. note::

        The name of the database can be freely chosen. The example assumes that
        the database named *seiscomp3* exists already and that it shall be continued
        to be used with the new SeisComP.

   * Add the names of the queues to the :confval:`queues` parameter.

#. Configure the connection parameters of all modules connecting to the messaging
   system in the global configuration, e.g. in :file:`global.cfg`.
   As in SeisComP3 the connection server is
   localhost. The queue is added to the host by "/". The default queue is *production*, e.g.

   .. code-block:: sh

      connection.server = localhost/production

   .. note::

      If *production* shall be used, then no additional configuration is required.


Database
--------

After adjusting the structure, variables and configuration parameters, check if the
:ref:`database requires an upgrade <tutorials_upgrade_number>` as well.


Automatic module check
----------------------

If applied, adjust the settings for automatic module status check, e.g. crontab entries.
For crontab use:

.. code-block:: sh

   crontab -e


System daemon
-------------

If SeisComP is controlled by the system daemon, e.g. to start SeisComP automatically
during computer startup, then the startup script must be adjusted.


References
==========

.. target-notes::

.. _`News website of gempa GmbH` : https://www.gempa.de/news/
.. _`SeisComP forum` : https://forum.seiscomp.de/
.. _`SeisComP package downloader` : https://www.seiscomp.de/downloader/
