.. _concepts_database:

********
Database
********


Scope
=====

This chapter provides an overview over supported databases.


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
   SQLite3, *dbsqlite*

The database used by the messaging for reading and writing is configured with
:ref:`scmaster`. The read connection by :ref:`modules <concepts_modules>` may be
additionally set with :confval:`database` in
:ref:`global configuration <global-configuration>`.
Read the sections :ref:`installation` and :ref:`getting-started` on the
installation and the configuration of the database backend and the initial setup
of the database itself, respectively.

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
   DataAvailability; information on continuous data records
   EventParameters; derived objects like picks, amplitudes, magnitudes origins, events, etc.
   :ref:`Inventory <concepts_inventory>`; station meta data
   Journaling; information on commands and actions e.g. by :ref:`scevent <scevent-journals>`
   QualityControl; waveform quality control parameters

.. note::

   The Config parameters just cover station bindings. Application/module specific
   configurations (all .cfg files) are not stored in the database and only kept
   in files.

The currently supported version of the database schema can be queried by any
module connecting to the data base using the option ``-V``, e.g.: ::

   $ scolv -V

     Framework: 5.0.0 Development
     API version: 15.0.0
     Data schema version: 0.12
     GIT HEAD: 9f5c26cc4
     Compiler: c++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
     Build system: Linux 4.15.0-163-generic
     OS: Ubuntu 18.04.6 LTS / Linux


Related Modules
===============

* :ref:`scardac`
* :ref:`scdb`
* :ref:`scdbstrip`
* :ref:`scdispatch`
* :ref:`scquery`
* :ref:`scqueryqc`
* :ref:`scxmldump`
