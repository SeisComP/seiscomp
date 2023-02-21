.. _installation:

*********************
|scname| Installation
*********************

|scname| requires a modern Linux operating system as it is developed and tested
only under Linux. For production systems we recommend Linux distributions with
long-term support (LTS). The Linux flavors under which |scname| has been tested
are given along with the |scname| package names on the download sites of
:cite:t:`seiscomp` and :cite:t:`gempa`.

The software can be obtained and installed from

* Officially released packages (TAR files) for different release versions,
  Linux systems and architectures,
* :ref:`Source code available on GitHub <build>`.

Packages may include

* Software for data acquisition, processing and :term:`GUIs <GUI>` for each
  supported platform,
* Maps. Maps from the |scname| releases Seattle and Zurich also work
  in later releases
* Documentation,
* Station configuration files (optional).

Download these packages from :cite:t:`seiscomp` or :cite:t:`gempa-download`.

The next sections describe the installation of the binary packages of |scname|
on

* :program:`Ubuntu 18`, 64 bit system,
* :program:`CentOS 7`, 64 bit system.


Hardware Requirements
=====================

The hardware requirements for a seismic system depend on the size of the
station network to be operated.

Minimum requirements are:

.. csv-table::
   :widths: 10 90
   :align: left
   :delim: ;

   CPU; 2
   RAM; 4 GB
   HDD; 20 GB
   OS; Ubuntu last 3 major LTS versions, 64bit, Debian 8.0 64bit, RHEL 7, CentOS 7 64bit

In case large networks (>100 stations) are operated, a distributed system is
recommended. Normally a |scname| system is separated in several subsystems.
A separation of data acquisition, processing and graphical user interfaces (GUI) is
useful to permit stable performance.

The minimum specifications of |scname| systems depend on the setup and the
applications.

Data acquisition systems:

+-----+----------------------------------------------------------------+
| CPU | 2                                                              |
+-----+----------------------------------------------------------------+
| RAM | 4 GB                                                           |
+-----+----------------------------------------------------------------+
| HDD | Raid1/5/0+1 with >= 200GB                                      |
+-----+----------------------------------------------------------------+

Processing systems:

+-----+----------------------------------------------------------------+
| CPU | 4                                                              |
+-----+----------------------------------------------------------------+
| RAM | 8 GB                                                           |
+-----+----------------------------------------------------------------+
| HDD | Raid1/5/0+1 with >= 100GB                                      |
+-----+----------------------------------------------------------------+

GUI system:

+-----+----------------------------------------------------------------+
| CPU | 2                                                              |
+-----+----------------------------------------------------------------+
| RAM | 4 GB                                                           |
+-----+----------------------------------------------------------------+
| HDD | > 50 GB                                                        |
+-----+----------------------------------------------------------------+


.. _installation-packages:

Installation from Packages
==========================

This section describes the installation of |scname| from compiled |scname|
packages which ship as :file:`*.tar.gz` files.


Steps to take
-------------

Simply follow a few steps to complete your installation of |scname|:

#. Log in to your Linux system as user, e.g. sysop, the standard user in this
   documentation.
#. Download the installation packages, e.g. from :cite:t:`seiscomp` or
   :cite:t:`gempa-download`:

   * :file:`seiscomp-[version]-[OS]-[arch].tar.gz`: main |scname| package with binaries, etc.
     Ensure to download the right package matching your operating system (OS) and
     hardware architecture (arch: 32 or 64-bit).
   * :file:`seiscomp-[version]-doc.tar.gz`: |scname| documentation.

     .. note::

        When receiving the packages from :cite:t:`gempa-download`, the documentation is already
        included in the main |scname| package to match the installed version. In this
        case, the documentation does not need to be downloaded and installed separately.

   * :file:`seiscomp-maps.tar.gz`: standard |scname| maps available on the
     download site of :cite:t:`seiscomp`.

#. Copy the downloaded files to your $HOME directory.

#. Navigate to the $HOME directory or any other place where to install |scname|

   .. code-block:: sh

      user@host:$ cd

#. Install the main |scname| package into :file:`seiscomp`

   .. code-block:: sh

      user@host:~$ tar xzf seiscomp-[version]-[OS]-[arch].tar.gz

#. Install the |scname| map package into :file:`seiscomp/share/maps`

   .. code-block:: sh

      user@host:~$ tar xzf seiscomp-[release]-maps.tar.gz

#. Optional: Install the documentation package into :file:`seiscomp/share/doc`

   .. code-block:: sh

      user@host:~$ tar xzf seiscomp-[version]-doc.tar.gz

Unpacking these files creates the |scname| :ref:`directory structure<directory_structure>`.


.. _directory_structure:

Directory structure
-------------------

All installed files and directories are found below the *seiscomp* directory.
The directory structure of the installed system is described the table below.

.. csv-table::
   :widths: 10 90
   :header: Directory, Description
   :align: left
   :delim: ;

   *bin*;              The user module binaries.
   *lib*;              The base library directory used by all modules.
   *lib/python*;       The Python library directory.
   *man*;              The manual pages.
   *sbin*;             The system/service/server binaries such as :ref:`seedlink`.
   *var*;              Variable files whose content is expected to continually change.
   *var/log*;          Log files of started modules. Usually modules log either to syslog or ~/.seiscomp/log. This directory contains the logs of the start of each module.
   *var/lib*;          Default directory for files created by modules such as the waveform ringbuffer of :ref:`seedlink` or the waveform archive created by :ref:`slarchive`.
   *var/run*;          Contains the .run and .pid files of modules started by :program:`seiscomp`.
   *include*;          SDK header files for all libraries.
   *share*;            Application data such as maps, cities.xml and others.
   *share/templates*;  Template files used by e.g. :ref:`seedlink` to create its native configuration.
   *etc*;              Configuration directory.
   *etc/descriptions*; Contains all XML module descriptions.
   *etc/defaults*;     The default configuration files. This directory is read as first when a module starts.
   *etc/init*;         Module init scripts called by :program:`seiscomp`.
   *etc/key*;          Station configurations and module bindings.


.. _software_dependencies:

Software dependencies
---------------------

|scname| depends on a number of additional software packages shipped with each
Linux distribution.
After installation of |scname| these packages can be installed using the
:program:`seiscomp`.
The :program:`seiscomp` tool comes with
the command :command:`install-deps` which installs required packages.
Read the section :ref:`System management<system-management>` for more detailed
instructions. For example, to install the dependencies for using the MariaDB
database, give 'mariadb-server' as parameter.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp install-deps base mariadb-server
   Distribution: Ubuntu 18.04
   [sudo] password for sysop:
   Reading package lists... Done
   Building dependency tree
   Reading state information... Done
   ...

More options for systems with GUIs and FDSNWS are: ::

   user@host:~$ seiscomp/bin/seiscomp install-deps gui fdsnws


If your distribution is not supported by :command:`install-deps`,
install the above packages manually:

:program:`Ubuntu` `version`

.. code-block:: sh

   user@host:~$ cd seiscomp/share/deps/ubuntu/[version]
   ...

:program:`CentOS` `version`

.. code-block:: sh

   user@host:~$ cd seiscomp/share/deps/centos/[version]
   ...

.. code-block:: sh

   su root
   bash install-mariadb-server.sh
   bash install-postgresql-server.sh
   bash install-base.sh
   bash install-gui.sh
   bash install-fdsnws.sh
   ...

or contact the |scname| developers to add support for your distribution.

.. warning::

   Either the MariaDB **or** the MySQL server can be installed; not both at the
   same time. When replacing on by the other, ensure that all related files are
   removed before installing the alternative server. For MySQL instead of MariaDB
   use: ::

      root@host:~$ sh install-mysql-server.sh

   Preferably use MariaDB instead of MySQL as MariaDB is the default for the
   supported Linux distributions!

.. note ::

   Linux systems develop dynamically and the installation of the dependencies
   may be incomplete. |scname| modules will stop and indicate the missing software.
   They can be installed manually.


.. _database_configuration:

*****************************
Database Server Configuration
*****************************

|scname| is typically operated with a :ref:`database <concepts_database>` which
should be optimized. This section describes how to setup and optimize the
database server. For the setup of the database itself read the section
:ref:`getting-started`.


.. _database_configuration_mysql:

MariaDB / MySQL
===============

* For better performance with a MariaDB/MySQL database, adjust the memory pool size. Test
  the default of the **buffer\_pool_size** before making the change:

  .. code-block:: sh

    $ mysql -u root -p
    show variables like 'innodb_buffer_pool_size';

  The optimum **buffer\_pool_size** depends on your system (RAM size) and only needs
  to be set if required. Choose your preferred value:

  * Recommended value: 512M or more
  * Minimum value: 64M

  Additionally, reduce the database hard drive synchronization and make both adjustments
  in the section [mysqld]:

  .. code-block:: sh

    [mysqld]
    innodb_buffer_pool_size = <your value>
    innodb_flush_log_at_trx_commit = 2

  .. note ::

     The location of the configuration file can differ between distributions.

     :program:`Ubuntu`:

     :file:`/etc/mysql/mariadb.conf.d/50-server.cnf`

     :program:`CentOS`:

     :file:`/etc/my.cnf`

  Please read the documentation of your distribution. root privileges may
  be required to make the changes.

* To start MariaDB automatically during boot set

  :program:`Ubuntu`

  .. code-block:: sh

     user@host:~$ sudo systemctl enable mariadb

  :program:`CentOS`

  .. code-block:: sh

     user@host:~$ su root
     root@host:~$ systemctl enable mariadb

* If you make a fresh installation of MariaDB/MySQL, secure the database and set
  a password for the root user

  :program:`Ubuntu` ::

     user@host:~$ sudo mysql_secure_installation

  :program:`CentOS` ::

     user@host:~$ su root
     root@host:~$ mysql_secure_installation

  .. warning ::

     This step overrides database settings. Only execute the command

     * After a fresh installation or
     * If you are sure about the procedure.

* After adjusting the parameters, MariaDB needs to be restarted. One can run

  :program:`Ubuntu`:

  .. code-block:: sh

     user@host:~$ sudo systemctl restart mariadb

  :program:`CentOS`:

  .. code-block:: sh

     user@host:~$ su root
     root@host:~$ systemctl restart mariadb

.. note ::

   Replace mariadb by mysql when using MySQL instead of MariaDB.


.. _database_configuration_postgresql:

PostgreSQL
==========

* When using PostgreSQL, the database server must be initialized and secured.

* By default PostgresSQL does not allow to login with username and password which
  leads to the fact that :program:`scmaster` can not connect to the database
  after |scname| database initialization. Here an example how to enable
  user/password authentication for local and remote connections.


.. code-block:: sh

     # TYPE  DATABASE        USER            ADDRESS                 METHOD
      # IPv4 local connections:
      host    seiscomp        sysop           0.0.0.0/0               md5
      host    all             all             127.0.0.1/32            ident

.. note ::

     The order of the rules matters and the location of the configuration file
     can differ between distributions.

     :program:`Ubuntu`:

     :file:`/etc/postgresql/10/main/pg_hba.conf`

     :program:`CentOS`:

     :file:`/var/lib/pgsql/data/pg_hba.conf`

* By default PostgresSQL accepts local connections only. If the database server
  and clients are on different machines please change the listen address as
  follows.

  .. code-block:: sh

     listen_addresses = 0.0.0.0/0

  .. note ::

     The location of the configuration file can differ between distributions.

     :program:`Ubuntu`:

     :file:`/etc/postgresql/10/main/postgresql.conf`

     :program:`CentOS`:

     :file:`/var/lib/pgsql/data/postgresql.conf`


Next Steps
==========

Now everything is installed and the system can be configured. The
:ref:`next chapter<getting-started>` chapter explains the first steps.
