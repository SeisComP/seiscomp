.. _installation:

*************************
Installation and Database
*************************

|scname| is distributed in the form of packages (tar files) for different releases,
Linux systems and architectures:

* Acquisition, processing and GUIs (for each supported platform)
* Maps (maps from the |scname| releases Seattle and Zurich also work
  in later releases)
* Documentation
* Station configuration files (optional)

Download these from `SeisComP`_.
This section describes the installation of the binary packages of |scname| on
an

* :program:`Ubuntu 18`, 64 bit system
* :program:`CentOS 7`, 64 bit system


Hardware requirements
=====================

The hardware requirements for a seismic system depend on the size of the
station network to be operated.

Minimum requirements are:

+-----+----------------------------------------------------------------------------------------+
| CPU | 2                                                                                      |
+-----+----------------------------------------------------------------------------------------+
| RAM | 4 GB                                                                                   |
+-----+----------------------------------------------------------------------------------------+
| HDD | 20 GB                                                                                  |
+-----+----------------------------------------------------------------------------------------+
| OS  | Ubuntu 16 64bit, Debian 8.0 64bit, CentOS 7 64bit                                      |
+-----+----------------------------------------------------------------------------------------+

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


|scname| Installation
=====================

|scname| can be installed from source code or from packages. While the source code
can be found on `GitHub`_, this documentation focuses on packages. For compilation
from source code read the section :ref:`build`.


Installation from packages
--------------------------

The next steps describe the installation of |scname| with the compiled |scname|
packages which ship as :file:`*.tar.gz` files.

#. Log in as user, e.g. sysop (the standard user in this documentation)
#. Download the installation packages, e.g. from `SeisComP`_ or get the packages from |gempa|:

   * :file:`seiscomp-[version]-[OS]-[arch].tar.gz`: main |scname| package with binaries, etc.
     Ensure to download the right package matching your operating system (OS) and
     hardware architecture (arch: 32 or 64-bit).
   * :file:`seiscomp-[version]-doc.tar.gz`: |scname| documentation.

     .. note::

        When receiving the packages from |gempa|, the documentation is already
        included in the main |scname| package to match the installed version. In this
        case, the documentation does not need to be downloaded and installed separately.

   * :file:`seiscomp-maps.tar.gz`: standard |scname| maps.

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

+---------------------+--------------------------------------------------------------------+
| Directory           | Description                                                        |
+=====================+====================================================================+
| *bin*               | The user module binaries.                                          |
+---------------------+--------------------------------------------------------------------+
| *lib*               | The base library directory used by all modules.                    |
+---------------------+--------------------------------------------------------------------+
| *lib/python*        | The Python library directory.                                      |
+---------------------+--------------------------------------------------------------------+
| *man*               | The manual pages.                                                  |
+---------------------+--------------------------------------------------------------------+
| *sbin*              | The system/service/server binaries such as seedlink.               |
+---------------------+--------------------------------------------------------------------+
| *var*               | Variable files whose content is expected to continually change.    |
+---------------------+--------------------------------------------------------------------+
| *var/log*           | Log files of started modules. Usually modules log either to syslog |
|                     | or ~/.seiscomp/log. This directory contains the logs of the start  |
|                     | of each module.                                                    |
+---------------------+--------------------------------------------------------------------+
| *var/lib*           | Default directory for files created by modules such as the         |
|                     | waveform ringbuffer of SeedLink or the waveform archive created    |
|                     | by slarchive.                                                      |
+---------------------+--------------------------------------------------------------------+
| *var/run*           | Contains the .run and .pid files of modules started by             |
|                     | :program:`seiscomp`.                                               |
+---------------------+--------------------------------------------------------------------+
| *include*           | SDK header files for all libraries.                                |
+---------------------+--------------------------------------------------------------------+
| *share*             | Application data such as maps, cities.xml and others.              |
+---------------------+--------------------------------------------------------------------+
| *share/templates*   | Template files used by e.g. SeedLink to create its native          |
|                     | configuration.                                                     |
+---------------------+--------------------------------------------------------------------+
| *etc*               | Configuration directory.                                           |
+---------------------+--------------------------------------------------------------------+
| *etc/descriptions*  | Contains all XML module descriptions.                              |
+---------------------+--------------------------------------------------------------------+
| *etc/defaults*      | The default configuration files. This directory is read as first   |
|                     | when a module starts.                                              |
+---------------------+--------------------------------------------------------------------+
| *etc/init*          | Module init scripts called by :program:`seiscomp`.                 |
+---------------------+--------------------------------------------------------------------+
| *etc/key*           | Station configurations and module bindings.                        |
+---------------------+--------------------------------------------------------------------+


.. _software_dependencies:

Software dependencies
---------------------

|scname| depends on a number of additional packages shipped with each Linux
distribution. The :program:`seiscomp` tool comes with
the command :command:`install-deps` which installs required packages.
Read the section :ref:`System management<system-management>` for more detailed instructions.
For example, to install the dependencies for using the MariaDB database,
give 'mariadb-server' as parameter.

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

      bash install-mysql-server.sh

.. note ::

   Linux systems develop dynamically and the installation of the dependencies
   may be incomplete. |scname| modules will stop and indicate the missing software.
   They can be installed manually.

.. _database_configuration:

Database configuration
======================

* For better performance with a MySQL/MariaDB database, adjust the memory pool size. Test
  the default of the **buffer\_pool_size** before making the change:

  .. code-block:: sh

    mysql -u sysop -p
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

* After adjusting the parameters, MariaDB needs to be restarted. One can run

  :program:`Ubuntu`:

  .. code-block:: sh

     user@host:~$ sudo systemctl restart mariadb

  :program:`CentOS`:

  .. code-block:: sh

     user@host:~$ su root
     user@host:~$ systemctl restart mariadb

* To start MariaDB automatically during boot set

  :program:`Ubuntu`

  .. code-block:: sh

     user@host:~$ sudo systemctl enable mariadb

  :program:`CentOS`

  .. code-block:: sh

     user@host:~$ su root
     user@host:~$ systemctl enable mariadb

.. note ::

   Replace mariadb by mysql when using MySQL instead of MariaDB.

Now everything is installed and the system can be configured. The :ref:`next chapter<getting-started>`
chapter explains the first steps.

References
==========

.. target-notes::

.. _`SeisComP` : https://www.seiscomp.de
.. _`GitHub` : https://github.com/SeisComP
