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

Command-Line Tools
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

Daemon Tools
============

Daemon tools can run in the background, e.g. for automatic data acquisition or
processing. The names of all daemon modules are listed when executing

.. code-block:: sh

   seiscomp list modules

Daemon modules can be started to run in the background:

.. code-block:: sh

   seiscomp start scautopick

When starting a daemon module all verbosity output is stored in @LOGDIR@ or
$SEISCOMP_ROOT/var/log. Daemon modules can also be executed as
:ref:`command-line tools <concepts_modules_commandline>`.


.. _concepts_modules_config:

Configuration
=============

Each :term:`standalone module` tries to read from three configuration files
whereas :term:`trunk` modules try to read the six files. Note that configuration
parameters defined earlier are overwritten if defined in files read in later:

+-----------------------------------------+------------+----------------+
| File                                    | Standalone | Trunk          |
+=========================================+============+================+
| $SEISCOMP_ROOT/etc/defaults/global.cfg  |            |    X           |
+-----------------------------------------+------------+----------------+
| $SEISCOMP_ROOT/etc/defaults/module.cfg  |  X         |    X           |
+-----------------------------------------+------------+----------------+
| $SEISCOMP_ROOT/etc/global.cfg           |            |    X           |
+-----------------------------------------+------------+----------------+
| $SEISCOMP_ROOT/etc/module.cfg           |  X         |    X           |
+-----------------------------------------+------------+----------------+
|        ~/.seiscomp/global.cfg           |            |    X           |
+-----------------------------------------+------------+----------------+
|        ~/.seiscomp/module.cfg           |  X         |    X           |
+-----------------------------------------+------------+----------------+

The :ref:`configuration section<global-configuration>` describes all available
configuration parameters for a trunk module. Not all modules make use of all
available parameters because they may be disabled, e.g., the messaging component.
So the configuration of the messaging server is disabled too.

The concept section :ref:`Configuration <concepts_configuration>` provides more
details about configurations.


.. _concepts_modules_aliaes:

Alias Modules
=============

Many :term:`trunk` and :term:`standalone modules` allow generating aliases as
symbolic links to another module.
These aliases are useful for running multiple instances of the same module with
different configuration.

Alias modules can be created using the :ref:`seiscomp` script by providing the 
options :option:`alias create` along with the name of the alias and the
corresponding module. Example:

.. code-block:: sh

   seiscomp alias create l1autopick scautopick
   
where *l1autopick* is the alias name and :ref:`scautopick` is the name of the
corresponding linked module.

.. warning::

   The length of alias names for modules considering
   :ref:`bindings<global_bindings_config>` is strictly limited to 20 characters.

Alias modules provide the same
:ref:`module and bindings configuration <concepts_configuration-configs>`
parameters as the linked module and they must be configured separately.

Alias modules can be removed along with generated links. Example:

.. code-block:: sh

   seiscomp alias remove l1autopick

Without further options, module and bindings configurations will be preserved.
These configurations can be interactively removed using :option:`--interactive`.
Example:

.. code-block:: sh

   seiscomp --interactive alias remove l1autopick

