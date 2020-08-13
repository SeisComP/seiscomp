.. _installation:

************
Installation
************

|scname| is distributed in the form of tar files for different releases,
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


Requirements
============

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
A separation of data acquisition, processing and graphical user interfaces is
useful to permit stable performance.

The minimum specifications of the system should be:

Data acquisition system:

+-----+----------------------------------------------------------------+
| CPU | 2                                                              |
+-----+----------------------------------------------------------------+
| RAM | 4 GB                                                           |
+-----+----------------------------------------------------------------+
| HDD | Raid1/5/0+1 with >= 200GB                                      |
+-----+----------------------------------------------------------------+


Processing system:

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


Installation procedure
======================

The next steps describe the installation of |scname| with the prepared
tar.gz files.

* Log in as user (e.g. sysop)
* Copy one of the :file:`seiscomp-[version]-[OS]-[arch].tar.gz` files to
  your home directory. Take care which is the right package (32 or 64-bit) for
  your operating system.

* Go to home directory

  .. code-block:: sh

     user@host:/tmp$ cd

* Un-tar the |scname| binary packagemake

  .. code-block:: sh

     user@host:~$ tar xzf seiscomp-[version]-[OS]-[arch].tar.gz

* Un-tar the |scname| map package into seiscomp/share/maps

  .. code-block:: sh

     user@host:~$ tar xzf seiscomp-[release]-maps.tar.gz

* If desired, un-tar the documentation into seiscomp/share/doc

  .. code-block:: sh

     user@host:~$ tar xzf seiscomp-[version]-doc.tar.gz

Unpacking these file creates the |scname| :ref:`directory structure<directory_structure>`.


Install dependencies
--------------------

|scname| depends on a number of additional packages shipped with each Linux
distribution. The following table gives an overview (the names of packages,
files or commands may differ slightly for other Linux systems):

:program:`Packages`

First the environment has to be set up. The :program:`seiscomp` tool comes with
the command :command:`install-deps` which installs required packages.
Read the section :ref:`System management<system-management>` for more detailed instructions.
For example, to install the dependencies for using the MySQL database,
give 'mysql-server' as parameter.

.. code-block:: sh

   user@host:~$ seiscomp/bin/seiscomp install-deps base mysql-server
   Distribution: Ubuntu 18.04
   [sudo] password for sysop:
   Reading package lists... Done
   Building dependency tree
   Reading state information... Done
   ...


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
   bash install-mysql-server.sh
   bash install-postgresql-server.sh
   bash install-base.sh
   bash install-gui.sh
   bash install-fdsnws.sh
   ...

or contact the |scname| developers to add support for your distribution.


SQL configuration
-----------------

* For better performance with a MySQL database, adjust the memory pool size. Test
  the default of the **buffer\_pool_size** before making the change:

  .. code-block:: sh

    mysql -u sysop -p
    show variables like 'innodb_buffer_pool_size';

  The optimum **buffer\_pool_size** depends on your system (RAM size) and only needs
  to be set if required. Choose your preferred value:

  * Recommended value: 512M
  * Minimum value: 64M

  Additionally, reduce the database hard drive synchronization and make both adjustments
  in the section [mysqld]:

  .. code-block:: sh

    [mysqld]
    innodb_buffer_pool_size = <your value>
    innodb_flush_log_at_trx_commit = 2

  **Note:** The location of the configuration can differ between distributions.
  The locations are given below for different Linux distribution.

  :program:`Ubuntu 16`

  :file:`/etc/mysql/mariadb.conf.d/50-server.cnf`

  :program:`Ubuntu 18`

  :file:`/etc/mysql/my.cnf`

  :file:`/etc/mysql/mariadb.conf.d/50-server.cnf`

  :program:`CentOS`

  :file:`/etc/my.cnf`

  Please read the documentation of your distribution. root privileges may
  be required to make the changes.

*  After adjusting the parameters, MySQL needs to be restarted. One can run

  :program:`Ubuntu`

  .. code-block:: sh

     user@host:~$ sudo systemctl restart mysql

  :program:`CentOS`

  .. code-block:: sh

     user@host:~$ su root
     user@host:~$ systemctl restart mariadb

* To start MySQL automatically during boot set

  :program:`Ubuntu`

  .. code-block:: sh

     user@host:~$ sudo update-rc.d mysql defaults

  :program:`CentOS`

  .. code-block:: sh

     user@host:~$ su root
     user@host:~$ systemctl enable mariadb

Now everything is installed and the system can be configured. The :ref:`next chapter<getting-started>`
chapter explains the first steps.


.. _directory_structure:

Directory structure
===================

The directory structure of the installed system is described with the
following table.

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


References
==========

.. target-notes::

.. _`SeisComP` : https://www.seiscomp.de
