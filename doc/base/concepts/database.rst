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


.. _concepts_database_tls:

Encrypted connections
---------------------

The *dbmysql* and *dbpostgresql* plugins can encrypt the connection to the
database server with TLS. It is configured by the following parameters of the
database URL.

.. csv-table::
   :widths: 1 3
   :header: Parameter, Description
   :align: left

   ssl_mode, "One of

   * *disabled*: do not use TLS.
   * *preferred*: use TLS if the server supports it, otherwise connect unencrypted.
   * *required*: use TLS, fail if the server does not support it.
   * *verify_ca*: like *required*, and verify the server certificate against
     the CA certificate(s) given with *ssl_ca* (or *ssl_capath*).
   * *verify_identity*: like *verify_ca*, and verify that the host name of the
     database URL matches the server certificate.

   The value is case-insensitive. The default is the client library default,
   or *required* if any other ``ssl_*`` parameter is set."
   ssl_ca, "File with the certificate(s) of the certificate authority (PEM)."
   ssl_capath, "Directory with certificates of trusted certificate authorities
   (PEM). MySQL / MariaDB only."
   ssl_cert, "Client certificate (PEM), e.g. for MySQL / MariaDB users created
   with ``REQUIRE X509`` or PostgreSQL *cert* authentication."
   ssl_key, "Private key of the client certificate (PEM)."
   ssl_cipher, "List of permissible ciphers for TLS 1.2 and earlier. MySQL /
   MariaDB only."

Example connecting to a database which requires secure transport and verifying
the server certificate:

.. code-block:: sh

   scolv -d "mysql://sysop:sysop@db.example.org/seiscomp?ssl_mode=verify_identity&ssl_ca=/etc/ssl/certs/db-ca.pem"

File names containing special characters like space or ``&`` must be
percent-encoded, e.g. ``%20`` and ``%26``.

.. note::

   * *verify_ca* and *verify_identity* require *ssl_ca* (or *ssl_capath* for
     MySQL / MariaDB). With MySQL / MariaDB use ``ssl_capath=/etc/ssl/certs``
     to verify against the certificate authorities trusted by the system.
   * With *required*, *verify_ca* and *verify_identity* the connection is
     refused if it is not encrypted, also when reconnecting.
   * The host name *localhost* makes the MySQL / MariaDB client libraries use
     a Unix socket instead of TCP. Unix socket connections are not encrypted.
   * The database URL configured in :ref:`scmaster` is passed to the connected
     modules. The certificate and key files must be available at the same
     location on all hosts running these modules.

MySQL / MariaDB
~~~~~~~~~~~~~~~

Whether the *dbmysql* plugin encrypts the connection without *ssl_mode*
depends on the client library it is linked against. The MySQL client library
(libmysqlclient) uses TLS if the server supports it. The MariaDB client
library (libmariadb) before version 3.4 does not. A server configured with
``require_secure_transport=ON`` therefore rejects connections from the latter
unless *ssl_mode* is set.

The MariaDB client library also verifies the host name with *verify_ca*. Use a
host name in the database URL which is listed in the server certificate.

PostgreSQL
~~~~~~~~~~

The parameters are passed to libpq as *sslmode* (*disable*, *prefer*,
*require*, *verify-ca*, *verify-full*), *sslrootcert*, *sslcert* and *sslkey*.
Without *ssl_mode* libpq uses TLS if the server supports it (*prefer*). The
libpq environment variables, e.g. ``PGSSLMODE``, apply to parameters which
are not given in the database URL.

With *required* and *ssl_ca* libpq also verifies the server certificate
against the CA, like *verify_ca*. The private key file given with *ssl_key*
must not be readable by other users.


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
