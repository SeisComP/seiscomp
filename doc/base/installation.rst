.. _installation:

*********************
|scname| Installation
*********************

|scname| requires a modern Linux operating system as it is developed and tested
only under Linux. For production systems we recommend Linux distributions with
long-term support (LTS). The Linux flavors under which |scname| has been tested
are given along with the |scname| package names on the download sites of
:cite:t:`seiscomp` and :cite:t:`gempa`.

|scname| can be obtained and installed from

* Officially released packages (TAR files) for different
  :ref:`release versions <installation_versions>`, Linux systems and
  architectures from the download sites of |scname| :cite:p:`seiscomp` or from
  :cite:t:`gempa-download`.,
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

* :program:`Ubuntu`, 64 bit system,
* :program:`RHEL`, 64 bit system.


.. _installation_versions:

SeisComP Versions
=================

|scname| has :ref:`developed over time <history>`. The versions can be
distinguished by the name of the release:

* **SeisComP since version 4.0.0** uses release version numbers such as *5.2.1*
  where

  * 5: major version with changes in API and database schema version, new features,
    bug fixed, optimizations,
  * 2: minor version with new features, bug fixed, optimizations,
  * 1: patch number with bug fixes, optimizations.

* **SeisComP3** uses release versions, names, numbers and patch numbers.

  Full example:  *SeisComP3-jakarta-2020.330.02*

  * 3: release version
  * jakarta: release name
  * 2020.330: release number
  * 02: patch number

  Names are adjusted depending on changes in source code:

  * **Release version:** major changes in module groups, functionality,
    concepts, data model.
    Example: SeisComp3 is SeisComP in version 3.0
    in comparison to version 2.5 the GUIs were introduced.
  * **Release name:** major changes in functionality, concepts, data model.
    Example: with SeisComP3-Seattle the new user friendly configuration GUI
    :ref:`scconfig` was introduced.
  * **Release number:** changes in data model version and/or major changes in
    applications and optimizations.
    The numbers include the year and the day of the year of the software
    release. Example: Jakarta-2018.327
  * **Patch number:** optimizations of applications without changes in the data
    model version.

The version number of the installed |scname| can be obtained by

* This documentation where it printed in the header along with the SeisComP icon
* The running any |scname| module on the command-line using :option:`-V` such as

  .. code-block:: sh

     $ scm -V

     scm
     Framework: 6.8.4 Release
     API version: 16.3.0
     Data schema version: 0.13
     GIT HEAD: c28f6323
     Compiler: c++ (Ubuntu 13.2.0-23ubuntu4) 13.2.0
     Build system: Linux 6.8.12-11-pve
     OS: Ubuntu 24.04 LTS / Linux


.. _installation-os:

Supported Operating Systems
===========================

|scname| is developed and tested on Linux for the latest stable flavors with
long-term support (LTS) and on x86_64 architecture. For |scname| in version
7.*.*. the minimum OS and version are

* Debian: 11
* RHEL: 8
* Ubuntu: 22.04

Higher versions of |scname| will require higher OS versions.
Packages for more flavors and versions may be found on
`the SeisComP website <https://www.seiscomp.de/downloader/>`_.


.. _installation-hw:

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

Installation of Packages
========================

This section describes the initial installation of |scname| from compiled
|scname| packages which ship as :file:`*.tar.gz` files. For installation from
source code follow the instructions outlined in section :ref:`compiling_source`.

You may install the |scname| packages in either way:

* :ref:`gsm<installation-gsm>` (recommended) a package manager provided by
  :cite:t:`gempa`,
* :ref:`manually by extracting packages <installation-manual>`.

For later updates/upgrades read the tutorial :ref:`tutorials_upgrade`.

.. hint::

   We recommend to track any changes in the installation and configuration of
   |scname| except :file:`seiscomp/var`, :file:`seiscomp/share/maps` and large
   binary files or files changing often during |scname| operation
   (e.g. :ref:`global_hypo71`, :ref:`global_nonlinloc` input and output files)
   using :program:`git`.

.. _installation-gsm:

gsm
---

Installation of packages by gsm :cite:p:`gsm` is
recommended allowing to easily update/upgrade or add/remove packages in the
future and in order to maintain a clean file structure also after
updates/upgrades. If you wish to install and maintain |scname|
by :program:`gsm` :cite:p:`gsm`, then read the instruction given in the
:cite:t:`gsm-doc`.

.. note::

   While :program:`gsm` :cite:p:`gsm` allows the installation of software
   packages the OpenSource map package of |scname| must be
   :ref:`installed manually <installation-manual>`.


.. _installation-manual:

Manual unpacking
----------------

A simply installation can be done by simply downloading and unpacking the
packages, but installation and maintenance using :ref:`gsm<installation-gsm>`
is recommended.
For simple unpacking follow a few steps to complete your installation of
|scname|:

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


.. _directory_structure:

Directory Structure
===================

The installation of |scname| creates the |scname|
:ref:`directory structure<directory_structure>`.
All installed files and directories are found below the *seiscomp* directory
unless an alternative directory is given when installing with :program:`gsm` or
:ref:`compiling from source code<compiling_source>`.
The directory structure of the installed system is described in the table below.

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

Software Dependencies
=====================

|scname| depends on a number of additional software packages shipped with each
Linux distribution.
After installation of |scname| these packages can be installed using the
:ref:`seiscomp` script.
:ref:`seiscomp` comes with the command :command:`install-deps` which installs
required packages. For example, to install the dependencies for
using the MariaDB database, give 'mariadb-server' as parameter.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp install-deps base mariadb-server
   Distribution: Ubuntu 24.04
   [sudo] password for sysop:
   Reading package lists... Done
   Building dependency tree
   Reading state information... Done
   ...

More requirements for systems with GUIs, FDSNWS and iLoc are:

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp install-deps gui
   user@host:~$ seiscomp/bin/seiscomp install-deps fdsnws
   user@host:~$ seiscomp/bin/seiscomp install-deps iloc


If your distribution is not supported by :ref:`seiscomp` *install-deps*,
install the above packages manually from the scripts within the OS- and
version-dependent directories:

.. code-block:: sh

   user@host:~$ cd seiscomp/share/deps/[OS]/[version]
   ...

Read the section :ref:`System management<system-management>` for more detailed
options and instructions.

.. warning::

   Either the MariaDB **or** the MySQL server can be installed; **not both at the
   same time**. When replacing one by the other, ensure that all related files are
   removed before installing the alternative server. For MySQL instead of MariaDB
   use:

   .. code-block:: sh

      root@host:~$ sh install-mysql-server.sh

   Preferably use MariaDB instead of MySQL as MariaDB is the default for the
   supported Linux distributions!

.. note::

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

  .. note::

     The location of the configuration file can differ between distributions.

     :program:`Ubuntu`:

     :file:`/etc/mysql/mariadb.conf.d/50-server.cnf`

     :program:`RHEL`:

     :file:`/etc/my.cnf`

  Please read the documentation of your distribution. root privileges may
  be required to make the changes.

* To start MariaDB automatically during boot set

  :program:`Ubuntu`

  .. code-block:: sh

     user@host:~$ sudo systemctl enable mariadb

  :program:`RHEL`

  .. code-block:: sh

     user@host:~$ su root
     root@host:~$ systemctl enable mariadb

* If you make a fresh installation of MariaDB/MySQL, secure the database and set
  a password for the root user

  :program:`Ubuntu`

  .. code-block:: sh

     user@host:~$ sudo mysql_secure_installation

  :program:`RHEL`

  .. code-block:: sh

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

  :program:`RHEL`:

  .. code-block:: sh

     user@host:~$ su root
     root@host:~$ systemctl restart mariadb

.. note::

   Replace mariadb by mysql when using MySQL instead of MariaDB.


.. _database_configuration_postgresql:

PostgreSQL
==========

* When using PostgreSQL, the database server must be initialized and secured.

* By default PostgresSQL does not allow to login with username and password which
  leads to the fact that :program:`scmaster` can not connect to the database
  after |scname| database initialization. Here an example how to enable
  user/password authentication for local and remote connections.
  Note: The following configuration changes are intended for a standard installation
  and may override security concepts. For production systems, we recommend
  coordinating the database configuration with the system administrator.

.. code-block:: sh

   # TYPE  DATABASE        USER            ADDRESS                 METHOD
   # IPv4 local connections:
   host    seiscomp        sysop           0.0.0.0/0               md5
   host    all             all             127.0.0.1/32            ident

.. note::

     The order of the rules matters and the location of the configuration file
     can differ between distributions.

     :program:`Ubuntu`:

     :file:`/etc/postgresql/10/main/pg_hba.conf`

     :program:`RHEL`:

     :file:`/var/lib/pgsql/data/pg_hba.conf`

* By default PostgresSQL accepts local connections only. If the database server
  and clients are on different machines please change the listen address as
  follows.

  .. code-block:: sh

     listen_addresses = *

  .. note::

     The location of the configuration file can differ between distributions.

     :program:`Ubuntu`:

     :file:`/etc/postgresql/10/main/postgresql.conf`

     :program:`RHEL`:

     :file:`/var/lib/pgsql/data/postgresql.conf`


Next Steps
==========

Now everything is installed and the system can be configured. The
:ref:`next chapter<getting-started>` chapter explains the first steps.
