.. _concepts_plugins:

****************
SeisComP plugins
****************


Scope
=====

This chapter describes the general use of plugins in SeisComP.


Overview
========

Plugins expand the functionality of :ref:`applications <concepts_modules>`.
They are C++ shared object libraries which are dynamically loaded at runtime
into an application.

Typical plugins provide access to:

* Databases
* :ref:`Recordstream implementations <global_recordstream>`
* :ref:`Locator routines <sec_index_extensions>`
* :ref:`Magnitude types <sec_index_extensions>`.

By just loading a plugin an application does not change
it's way to function magically. Common plugins just implement a certain
interface (see e.g. messaging or RecordStream) and exhibit that functionality
by adding a new entry to the internal interface factory. As an example an
application makes use of interface ``DatabaseInterface``. Technically it
creates a new object implementing a certain interface by calling the C++
method:

.. code-block:: sh

   db = DatabaseInterface::Create("mysql");

Without having a plugin loaded the returned object will be NULL or to put it
in other words, there is not implementation for mysql available.

Once the plugin ``dbmysql`` is loaded into the application, an implementation
for type mysql is added and will be available to the application. It is
still required for the application to explicitly ask for a particular
interface. That is most likely left to the user by adding a corresponding
configuration option to the configuration file.

That means, if an application loads two plugins, e.g. ``dbmysql`` and
``dbpostgresql`` that does not mean that it will not read from two database
at a time. It means the user has now the option to either use a MySQL database
or a PostgreSQL database. He still needs to make his choice in the
configuration file.

Trunk plugins are only supported as shared object libraries and therefore are
required to be written in C++. Implementations for all available interfaces
can be added. An incomplete list of SeisComP C++ interfaces:

* :ref:`Messaging <concepts_messaging>`
* :ref:`Database <concepts_database>`
* :ref:`RecordStream <concepts_recordstream>`
* Record formats
* Map projections
* :ref:`Time domain filters <filter-grammar>`
* Importer
* Exporter
* **Amplitude processors**
* **Magnitude processors**

This is just a subset of available extensible interface factories. The
emphasized entries refer to the factories which are most commonly extended.


Location and Configuration
==========================

Plugins are located in :file:`$SEISCOMP_ROOT/share/pugins`. In order to make a
plugins available for a module it must be added to the configuration of
:confval:`plugins` of the global parameters of a module or in
:ref:`global_configuration`.

Configuring :confval:`plugins` with the name of a plugin will let the exclusively
use this plugin and no other ones, e.g. default plugins. Example: ::

   plugins = evrc

In order to add a plugin to the default plugins or plugins loaded by before, e.g.
by the global configuration, load these 
