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

SeisComP has :ref:`developed over time <history>`. In order to distinguish the developments
release versions, names, numbers and patch numbers are used:

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

Applications can only connect to a messaging system that runs with a database
in an equal or lower data model version. Therefore, the SeisComP system which
operates the messaging system is always updated last. Example: A distributed system
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

The change log can also be accessed from the Docs panel in :ref:`scconfig`.

.. note::

   New features are regularly advertised and described in detail on the
   `News website of gempa GmbH`_ and on the `SeisComP forum`_.

.. _tutorials_upgrade_number:

Upgrade to a higher release number
==================================

When installing a new SeisComP release upgrading the database may be required.
**More actions** are required when :ref:`upgrading from SeisComP3 to SeisComP in version 4 <tutorials_upgrade_v4>`.
The database version will be tested and the required actions will be shown when executing:

.. code-block:: sh

   seiscomp update-config

or when pressing the Update Configuration button in scconfig.
An upgrade from version SeisComP3 jakarta-2017.334 to jakarta-2018.327 will give:

.. code-block:: sh

   * starting kernel modules
     spread is already running
     starting scmaster
     * configure scmaster
       * check database write access ... OK
       * database schema version is 0.10
       * last migration version is 0.11
       * migration to the current version is required. apply the following
         scripts in exactly the given order:
         * /home/sysop/seiscomp/share/db/migrations/mysql/0_10_to_0_11.sql
     error: updating configuration for scmaster failed

The shown migration scripts can be used directly with the mysql command:

.. code-block:: sh

   seiscomp stop
   mysql -u sysop -p -D seiscomp -e 'source /home/sysop/seiscomp/share/db/migrations/mysql/0_10_to_0_11.sql;'
   seiscomp update-config
   seiscomp start

Using the migration scripts provides a more user friendly way than copying the
lines of mysql code from the changelog. In later versions we might add the option to automatically run the migrations.

.. warning::

   Upgrading the database make take some time. Do no interrupt the process!
   During this time, the SeisComP messaging system is unavailable causing a downtime of the system.

.. _tutorials_upgrade_v4:

Migrate from SeisComP3 to version 4
===================================

SeisComP in version has some major differences to SeisComP3 which require adjustments.
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

     Spread, arclink and arclinkproxy are not part of SeisComP anymore. Some default and
     description files have changed. **Therefore, do not migrate:**

     * any default configuration, description and init files. Better enable the desired
       daemon modules again.

       .. code-block:: sh

          seiscomp/bin/seiscomp enable [module]

     *   any file related to spread, arclink and arclinkproxy.

Configurations containing absolute paths, e.g. :file:`/home/sysop/seiscomp3/share/scautoloc/grid_custom.conf`,
must be adjusted. Better use :ref:`internal SeisComP variables <concepts_configuration_variables>`
such as *@DATADIR@* instead of *seiscomp3/share*.

System variables
----------------

The system environment variables must be updated, e.g. in :file:`$HOME/.bashrc`.
Remove or uncomment the lines  :file:`$HOME/.bashrc` referring to the depreciated SeisComP3
version execute

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

Database
--------

After adjusting the structure and variables, check if the :ref:`database requires an upgrade <tutorials_upgrade_number>` as well.

.. _sec-tutorials_upgrading_messaging:

Messaging system
----------------

One of the main changes SeisComP3 to SeisComP in version 4.0 is the :ref:`messaging system <concepts_messaging>`.
Spread does not exist anymore and only :ref:`scmaster` is started initially for
the messaging system. :ref:`scmaster` allows to operate several queues in parallel with
different databases. This flexibility comes with additional parameters which require
configuration. Migrate the legacy database parameters and configure the new one:

#. Setup the messaging queues to the configuration of :ref:`scmaster`.

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

   * Add message groups to the list of :confval:`default groups <defaultGroups>`, e.g.

     .. code-block:: sh

        queues.production.groups = L1PICK, L1LOCATION

     These groups will be available for all other connected modules in addition to the
     :confval:`default groups <defaultGroups>`.

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

#. Configure the connection parameters of all modules connecting to the messaging system.
   As in SeisComP3 the connection server is
   localhost. The queue is added to the host by "/". The default queue is *production*, e.g.

   .. code-block:: sh

      connection.server = localhost/production

   .. note::

      If *production* shall be used, then no configuration is required.

Crontab and system daemon
-------------------------

Finally, adjust the system daemon startup script and crontab entries. For crontab use:

.. code-block:: sh

   crontab -e



References
==========

.. target-notes::

.. _`News website of gempa GmbH` : https://www.gempa.de/news/
.. _`SeisComP forum` : https://forum.seiscomp.de/
.. _`SeisComP package downloader` : https://www.seiscomp.de/downloader/
