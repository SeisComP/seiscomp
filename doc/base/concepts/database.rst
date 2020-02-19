.. _concepts_database:

********
Database
********

Scope
=====

This chapter provides an overview over supported databases.

Overview
========

SeisComP can store and read information from a relational database management
system (RDBMS). Supported are basically all existing RDBMS for which a plugin
can be written. :ref:`Plugins<concepts_plugins>` are provided for

* MySQL / MariaDB
* PostgreSQL
* SQLite3

The database schema used is well defined and respected by all modules which
access the database. It is similar to the SeisComP XML schema and
the C++ / Python class hierarchy of the datamodel namespace / package.

The following information is stored in the database:

* :ref:`Configuration <concepts_configuration>` (station bindings)
* :ref:`Inventory <concepts_inventory>`
* EventParameters
* Availability

The configuration just covers the station bindings. Application/module specific
configurations (all .cfg files) are not stored in the database.
