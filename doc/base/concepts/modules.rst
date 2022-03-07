.. _concepts_modules:

****************
SeisComP modules
****************


Scope
=====

This document describes the difference between command-line and daemon modules.


Overview
========

SeisComP is not a single executable but it provides a set of modules which
can be

* :ref:`Command-line modules <concepts_modules_commandline>`
* :ref:`Daemon modules <concepts_modules_daemon>`.

A :term:`module` is :ref:`configured by its configuration files <concepts_modules_config>` either to be used directly or to
generate its native configuration. Modules that need to convert the configuration or do not
use the default configuration options (see below) are called :term:`standalone modules <standalone module>`.
All other modules are called :term:`trunk` modules.

Examples for standalone modules are :ref:`seedlink`, :ref:`slarchive` and :ref:`slmon`.


.. _concepts_modules_commandline:

Command-line tools
==================

Command-line modules can be executed on demand from the SHELL command-line. These
modules can be utilities or :term:`GUIs <GUI>`, e.g.

.. code-block:: sh

   seiscomp exec scolv [options]
   scolv [options]

Command-line modules are found in $SEISCOMP_ROOT/bin but they are **NOT** listed
when executing

.. code-block:: sh

   seiscomp list modules

Using options like *-h* the list of available command-line options can be learned.
Debugging information can be obtained during runtime using the --debug option:


.. code-block:: sh

   scbulletin -h
   scbulletin --debug [more options]

.. note::

   In order to execute modules without *seiscomp exec*, the SeisComP environment
   variable must be known to the system. The environment variables and their values
   can be printed giving the full path to the *seiscomp* script:, e.g.

   .. code-block:: sh

      /home/sysop/seiscomp/bin/seiscomp print env


.. _concepts_modules_daemon:

Daemon tools
============

Daemon tools can run in the background, e.g. for automatic data acquisition or
processing. The names of all daemon modules are listed when executing

.. code-block:: sh

   seiscomp list modules

Daemon modules can be started to run in the background:

.. code-block:: sh

   seiscomp start scautopick

When starting a daemon module all verbosity output is stored in @LOGDIR@ or $SEISCOMP_ROOT/var/log.
Daemon modules can also be executed as :ref:`command-line tools <concepts_modules_commandline>`.


.. _concepts_modules_config:

Configuration
=============

Each :term:`standalone module` tries to read from three configuration files whereas :term:`trunk` modules
try to read the six files. Note that configuration parameters defined earlier are overwritten
if defined in files read in later:

+---------------------------------+------------+----------------+
| File                            | Standalone | Trunk          |
+=================================+============+================+
|        etc/defaults/global.cfg  |            |    X           |
+---------------------------------+------------+----------------+
|        etc/defaults/module.cfg  |  X         |    X           |
+---------------------------------+------------+----------------+
|        etc/global.cfg           |            |    X           |
+---------------------------------+------------+----------------+
|        etc/module.cfg           |  X         |    X           |
+---------------------------------+------------+----------------+
|        ~/.seiscomp/global.cfg   |            |    X           |
+---------------------------------+------------+----------------+
|        ~/.seiscomp/module.cfg   |  X         |    X           |
+---------------------------------+------------+----------------+

The :ref:`configuration section<global-configuration>` describes all available configuration parameters for a trunk module.
Not all modules make use of all available parameters because they may be disabled, e.g. the
messaging component. So the configuration of the messaging server is disabled too.

The concept section :ref:`Configuration <concepts_configuration>` provides more details
about configurations.
