.. _getting-started:

*****************************
Getting Started with |scname|
*****************************

Once the Linux system is installed the |scname| modules need to be configured including
the :ref:`initial configuration and the connection to the database <getting-started-initial>`.
The central tool to configure and control the system is :program:`seiscomp` which
is explained more deeply in the :ref:`next chapter<system-management>`. A user-friendly
graphical frontend to :program:`seiscomp` is :ref:`scconfig`.


.. _getting-started-initial:

Database Configuration
======================

Once the database server is defined and optimized as described in the section
:ref:`database_configuration` you may configure |scname| with the database.
Initially execute the steps listed in this section. You will need to consider
differences in databases:

* :ref:`MySQL <getting-started-mysql>` (not recommended),
* :ref:`MariaDB <getting-started-mariadb>`,
* :ref:`PostgreSQL <getting-started-postgresql>`.


.. _getting-started-mysql:

MySQL
-----

The initial configuration by the :program:`seiscomp` script or the
wizard of :ref:`scconfig` allows to create and configure the MySQL database
for |scname|. If you want to use MySQL continue with the
:ref:`general setup <getting-started-setup>`.

.. warning ::

   * Using MySQL is currently not recommended. Preferably use MariaDB instead of MySQL
     as MariaDB is the default SQL flavor of most supported Linux systems!
   * As of MySQL 8.0 the password encryption and policy has changed resulting in
     errors when connecting to a MySQL server. In 04/2021 this
     does not seem to be fully supported in **Ubuntu 20.04**. Therefore, you need
     to use a native password on the MySQL server.

     .. code-block:: sh

        $ sudo mysql -u root -p

          ALTER USER 'sysop'@'%%' IDENTIFIED WITH mysql_native_password BY 'my_super_secret_password_matching_the_mysql_password_validation_policy';


.. _getting-started-mariadb:

MariaDB
-------

The initial configuration by the :program:`seiscomp` script or the
wizard of :ref:`scconfig` allows to create and configure the MySQL database
for |scname|.

For setting up the database manually with MariaDB follow the instructions
below.

.. note::

    With **Ubuntu 16.04** MariaDB has become the standard flavor of MySQL in
    Ubuntu and either MariaDB or MySQL can be installed. The implementation
    of MariaDB in Ubuntu requires additional steps. They must be taken
    **before** the initial configuration in order to allow |scname| to make
    use of MariaDB. Previously, the :ref:`scconfig` wizard and
    :command:`seiscomp setup` could not be used to set up the MariaDB database.
    **The option "Create database" had to be unchecked or answered with "no"**.
    The issue is resolved in this release and both, :ref:`scconfig` wizard and
    :command:`seiscomp setup` are now fully capable of the required actions.

The full procedure to create the seiscomp database:

.. code-block:: sh

   user@host:~$ sudo mysql -u root -p
        CREATE DATABASE seiscomp CHARACTER SET utf8 COLLATE utf8_bin;
        grant usage on seiscomp.* to sysop@localhost identified by 'sysop';
        grant all privileges on seiscomp.* to sysop@localhost;
        grant usage on seiscomp.* to sysop@'%' identified by 'sysop';
        grant all privileges on seiscomp.* to sysop@'%';
        flush privileges;
        quit

   user@host:~$ mysql -u sysop -p seiscomp < ~/seiscomp/share/db/mysql.sql


.. _getting-started-postgresql:

PostgreSQL
----------

The initial configuration allows configuring the PostgreSQL database parameters
for |scname|.
It also allows :ref:`creating the database <database_configuration_postgresql>`
and the database tables.

For a manual setup of the PostgreSQL database first :ref:`setup the database
server<database_configuration_postgresql>`, then create the user, the database
and the tables.


#. Create the user and the database

   :program:`CentOS`:

   .. code-block:: sh

      sudo@host:~$ sudo su
      root@host:~$ sudo -i -u postgres
      postgres@host:~$ psql

         postgres=# create database seiscomp;
         postgres=# create user sysop with encrypted password 'sysop';
         postgres=# grant all privileges on database seiscomp to sysop;
         postgres=# alter database seiscomp owner to sysop;
         postgres=# exit

      root@host:~$ exit

#. Create the database tables

   .. code-block:: sh

      user@host:~$ psql -f ~/seiscomp/share/db/postgres.sql -t seiscomp -U sysop

Continue with the :ref:`general setup <getting-started-setup>` considering the
created database but **do not create the database again**.


.. _getting-started-setup:

General |scname| Setup
======================

Use :command:`seiscomp setup` or the wizard from within :ref:`scconfig` (:kbd:`Ctrl+N`) for the
initial configuration including the database parameters. :command:`seiscomp setup` is the
successor of the former :program:`./setup` script.

In :command:`seiscomp setup` default values are given in brackets []: ::

   user@host:~$ seiscomp/bin/seiscomp setup

   ====================================================================
   seiscomp setup
   ====================================================================

   This initializes the configuration of your installation.
   If you already made adjustments to the configuration files
   be warned that this setup will overwrite existing parameters
   with default values. This is not a configurator for all
   options of your setup but helps to setup initial standard values.

   --------------------------------------------------------------------
   Hint: Entered values starting with a dot (.) are handled
         as commands. Available commands are:

         quit: Quit setup without modification to your configuration.
         back: Go back to the previous parameter.
         help: Show help about the current parameter (if available).

         If you need to enter a value with a leading dot, escape it
         with backslash, e.g. "\.value".
   --------------------------------------------------------------------

This will ask for initial settings as database (if package trunk is installed)
parameters and the logging backend.

----

.. code-block:: none

   Organization name []:

Sets the organisation name printed e.g. when you say *hello* to Seedlink
or Arclink.

----

.. code-block:: none

   Enable database storage [yes]:

Enables or disables the database for the system. This option should be left
enabled unless all modules should connect to remote processing machine which
is already available. The database is required to store inventory information
as well as processing results. The database is the central storage for all
trunk modules and the default request handler of Arclink.

----

.. code-block:: none

    0) mysql
         MySQL server.
    1) postgresql
         PostgreSQL server. There is currently no support in setup to create the
         database for you. You have to setup the database and user accounts on
         your own. The database schema is installed under share/db/postgresql.sql.
   Database backend [0]:

If the database is enable the database backend can be selected. |scname|
supports two main backends: MySQL and PostgreSQL. Select the backend to be used
here but be prepared that only for the MySQL backend the setup can help to
create the database and tables for you. If you are using PostgreSQL you have
to provide a working database with the correct schema. The schema files are
part of the distribution and can be found in :file:`seiscomp/share/db/postgresql.sql`.

.. note::

   As of PostgreSQL version 9 the default output encoding has changed to hex.
   In order to fix issues with seiscomp log in to your database and run the
   following command.

   .. code-block:: sql

      ALTER DATABASE seiscomp SET bytea_output TO 'escape';


----

.. code-block:: none

   Create database [yes]:

.. warning ::

   If MySQL is selected it is possible to let :command:`seiscomp setup` to create
   the database and all tables for you. Otherwise currently not and you need to set up the
   database manually following the :ref:`given instructions <getting-started-mysql>`.
   If the database has been created already, answer 'no' here.

----

.. code-block:: none

   MYSQL root password (input not echoed) []:

Give the MySQL root password for your database server to create the database
tables. This is only required if the last question has been answered with 'yes'.

----

.. code-block:: none

   Drop existing database [no]:

If a database with the same name (to be selected later) exists already and the
database should be created for you, an error is raised. To delete an existing
database with the same name, say 'yes' here.

----

.. code-block:: none

   Database name [seiscomp]:
   Database hostname [localhost]:
   Database read-write user [sysop]:
   Database read-write password [sysop]:
   Database public hostname [localhost]:
   Database read-only user [sysop]:
   Database read-only password [sysop]:

Setup the various database options valid for all database backends. Give
:command:`help` for more information.

----

If all question have been answered the final choice needs to be made to either
create the initial configuration, go back to the last question or to quit
without doing anything.

.. code-block:: none

   Finished setup
   --------------

   P) Proceed to apply configuration
   B) Back to last parameter
   Q) Quit without changes
   Command? [P]:


Environment variables
=====================

Commands can be used along with the :program:`seiscomp` script located in *seiscomp/bin/seiscomp*.
Read the section :ref:`sec-management-commands` for more details on :program:`seiscomp`.
E.g. |scname| modules can be executed like ::

   user@host:~$ seiscomp/bin/seiscomp exec scrttv

Calling :program:`seiscomp` with its full path, e.g.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp [command]

will load the full |scname| environment.
Providing the full path allows starting other |scname| modules in a specific
|scname| environment. Thus, multiple SeisComP installations can be maintained
and referred to on the same machine.

:program:`seiscomp` can also be used for printing the considered |scname| environment ::

   user@host:~$ seiscomp/bin/seiscomp print env

resulting in ::

   export SEISCOMP_ROOT="/home/sysop/seiscomp"
   export PATH="/home/sysop/seiscomp/bin:$PATH"
   export LD_LIBRARY_PATH="/home/sysop/seiscomp/lib:$LD_LIBRARY_PATH"
   export PYTHONPATH="/home/sysop/seiscomp/lib/python:$PYTHONPATH"
   export MANPATH="/home/sysop/seiscomp/share/man:$MANPATH"
   source "/home/sysop/seiscomp/share/shell-completion/seiscomp.bash"

For convenience, the default |scname| installation can be referred to, when defining
the required system variables, e.g. in :file:`~/.bashrc`. Then, the |scname| environment
is known to the logged in user and |scname| modules can be
executed without the :program:`seiscomp` script.

For setting the environment

#. Use the :program:`seiscomp` script itself to generate the parameters and write
   the parameters to :file:`~/.bashrc` ::

      user@host:~$ seiscomp/bin/seiscomp print env >> ~/.bashrc

#. Load the environment or log out and in again ::

      user@host:~$ source ~/.bashrc

Thereafter, modules can be executed by their names without involving :program:`seiscomp`,
e.g. ::

   user@host:~$ scrttv


Activate/Enable Modules
=======================

After the installation all module are disabled for auto start. If :command:`seiscomp start`
is called, nothing will happen until modules are enabled. To enable a set of modules,
:command:`seiscomp enable` needs to be called with a list of modules.
For example, for a processing system with SeedLink for data acquisition,
you may use:

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp enable seedlink slarchive scautopick scautoloc scamp scmag scevent
   enabled seedlink
   enabled slarchive
   enabled scautopick
   enabled scautoloc
   enabled scamp
   enabled scmag
   enabled scevent

A successive call of :command:`seiscomp start` will then start all enabled
modules. This is also required to restart enabled modules with :command:`seiscomp check`.

Alternatively, :ref:`scconfig<scconfig>` can be used to enable/disable
and to start/stop/restart modules.

However, before starting seiscomp, station information (metadata) need to
be provided and the configuration needs to be updated.


Supply Station Metadata
=======================

|scname| requires the metadata from seismic network and stations including full responses
for data acquisition
and processing. The metadata can be obtained from network operators or
various other sources in different formats. The metadata include, e.g.:

- Network association
- Operation times
- Location
- Sensor and data logger specifications with full response information
- Data stream specifications

|scname| comes with various importers to add metadata
for networks and stations including full response information.

:ref:`import_inv` is the tool to import inventory data into |scname|.
Alternatively can be used.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp exec import_inv dlsv inventory.dataless

This will import a dataless SEED volume into `etc/inventory/inventory.dataless.xml`.

Repeat this step for all inventory data you want to import.


Configure Station Bindings
==========================

The configuration of modules and bindings is explained in :ref:`global`. To
add bindings in a more convenient way, start :ref:`scconfig`.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp exec scconfig

Typical binding profiles or station bindings involve bindings configurations for
data acquisition and processing modules:

* :ref:`seedlink`: Configure the plugin for the real-time data acquisition.
* :ref:`slarchive`: Configure the data archiving.
* :ref:`global <global>`: Configure :confval:`detecStream` and :confval:`detecLocid` to determine the
  default streams for phase detection and for showing stations and streams in GUIs
  like :ref:`scmv`, :ref:`scrttv` or :ref:`scolv`.
* :ref:`scautopick`: Configure the automatic phase detection. You may overwrite global
  binding parameters.


Update Configuration, Start Everything
======================================

To update the configuration when new stations have been added or modified,
:command:`seiscomp update-config` needs to be run. This creates configuration
files of modules that do not use the configuration directly, writes the trunk
bindings to the database and synchronizes the inventory with the database.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp update-config
   [output]

After the configuration has been updated and the inventory has been synchronized,
call :command:`seiscomp start` to start all enabled modules:

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp start
   starting seedlink
   starting slarchive
   starting scautopick
   starting scautoloc
   starting scamp
   starting scmag
   starting scevent

Now the system should run. To check everything again, :command:`seiscomp check`
can be run which should print *is running* for all started modules.
If everything is working, the analysis tools can be started, e.g. MapView.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp exec scmv
