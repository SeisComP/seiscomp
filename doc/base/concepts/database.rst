.. _concepts_database:

********
Database
********


Scope
=====

This chapter provides an overview over databases supported by |scname|.


Overview
========

|scname| can store and read information from a relational database management
system (RDBMS). Supported are basically all existing RDBMS for which a plugin
can be written. Currently, :ref:`database plugins <concepts_plugins>` are
provided for

.. csv-table::
   :widths: 1 1
   :header: Database, Plugin Name
   :align: left

   MySQL / MariaDB, *dbmysql*
   PostgreSQL, *dbpostgresql*
   SQLite3, *dbsqlite3*


Database access
---------------

Typically, the database is accessed by the messaging (:ref:`scmaster`) for
reading and writing.
Most other modules can only read from the database but do not write into it.
Among the few exceptions which can also directly write to the database are
:ref:`scdb` and :ref:`scardac`.

The database connection provided by the messaging is configured by the
:ref:`scmaster module configuration <scmaster>`. :ref:`Modules <concepts_modules>`
connected to the messaging receive the read connection parameters through the
messaging connection. However, the default read connection by these and all
other modules may be set with :confval:`database` in
:ref:`global configuration <global-configuration>` or set on the command line
using :option:`--database` or simply :option:`-d`.
Read the sections :ref:`installation` and :ref:`getting-started` on the
installation and the configuration of the database backend and the initial setup
of the database itself, respectively.

The database connection may be used together with the *debug* option to print
the database commands along with debug log output. Example for using
:ref:`scolv` in offline mode with database debug output:

.. code-block:: sh

   scolv -d localhost?debug --offline --debug


Database schema
---------------

The used database schema is well defined and respected by all modules which
access the database. It is similar to the SeisComML schema (:term:`SCML`,
a version of XML) and the C++ / Python class hierarchy of the datamodel
namespace / package.

Information of the following objects can be stored in the database as set out in
the :ref:`documentation of the data model <api-datamodel-python>`.

.. csv-table::
   :widths: 25, 75
   :header: Object, Description
   :align: left
   :delim: ;

   :ref:`Config <concepts_configuration>`; station bindings
   :ref:`DataAvailability <api-datamodel-python>`; information on continuous data records
   :ref:`EventParameters <api-datamodel-python>`; derived objects like picks, amplitudes, magnitudes origins, events, etc.
   :ref:`Inventory <concepts_inventory>`; station meta data
   :ref:`Journaling <api-datamodel-python>`; information on commands and actions, e.g., by :ref:`scevent <scevent-journals>`
   :ref:`QualityControl <api-datamodel-python>`; waveform quality control parameters

.. note::

   The Config parameters just cover station bindings. Application/module specific
   configurations (all .cfg files) are not stored in the database and only kept
   in files.

The currently supported version of the database schema can be queried by any
module connecting to the data base using the option :option:`-V`. Example:

.. code-block:: sh

   $ scm -V

     scm
     Framework: 6.0.0 Development
     API version: 16.0.0
     Data schema version: 0.12
     GIT HEAD: 5e16580cc
     Compiler: c++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
     Build system: Linux 6.2.0-26-generic
     OS: Ubuntu 22.04.3 LTS / Linux


Related Modules
===============

* :ref:`scardac`
* :ref:`scdb`
* :ref:`scdbstrip`
* :ref:`scdispatch`
* :ref:`scquery`
* :ref:`scqueryqc`
* :ref:`scxmldump`
