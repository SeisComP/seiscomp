.. _concepts_modules:

****************
SeisComP modules
****************


Scope
=====

This document describes the difference between command-line and daemon modules.


Overview
========

SeisComP is not a single executable but it provides a set of :term:`trunk` and
:term:`standalone <standalone module>` :term:`modules <module>`. Trunk modules
can be

* :ref:`Command-line modules <concepts_modules_commandline>`,
* :ref:`Daemon modules <concepts_modules_daemon>`.

Modules are :ref:`configured by configuration files <concepts_modules_config>`
either to be used directly or to generate its native configuration. Modules that
need to convert the configuration or do not use the default configuration
options (see below) are called :term:`standalone modules <standalone module>`.
All other modules are called :term:`trunk` modules.

Examples for standalone modules are :ref:`seedlink`, :ref:`slarchive` and :ref:`slmon`.

.. note::

   In order to start or execute modules without :command:`seiscomp exec`
   (see below), the |scname| SHELL environment variables must be known to the
   system. The variables and their values can be printed giving the full path to
   the :ref:`seiscomp` tool. Example:

   .. code-block:: sh

      /home/sysop/seiscomp/bin/seiscomp print env


.. _concepts_modules_daemon:

Daemon Tools
============

Daemon tools are |scname| modules that can run automatically in the background
without user interaction, e.g., for automatic data acquisition or data
processing. The names of all daemon modules are listed when executing the
:ref:`seiscomp` tool with :command:`list modules`:

.. code-block:: sh

   seiscomp list modules

Daemon modules can be started to run in the background:

.. code-block:: sh

   seiscomp start scautopick

When starting a daemon module, all verbosity output is logged to
:ref:`log files <concepts_modules_logging>`. Daemon modules can also be executed
as :ref:`command-line tools <concepts_modules_commandline>`.


.. _concepts_modules_commandline:

Command-Line Tools
==================

All non-daemon modules are command-line modules. These command-line modules
and most :ref:`daemon modules <concepts_modules_daemon>` can be executed on
demand from the SHELL command-line. These modules can also be
utilities or :term:`graphical user interfaces (GUIs) <GUI>`.
For executing use the full path to the :ref:`seiscomp` tool or, when the
|scname| environment is known, just call the module name along with command-line
options, e.g.

.. code-block:: sh

   seiscomp exec scolv [options]
   scolv [options]

Command-line modules are found in :file:`@ROOTDIR@/bin/` but they are **NOT**
listed when executing

.. code-block:: sh

   seiscomp list modules

Using options like :option:`-h` the list of available command-line options can
be learned.

.. code-block:: sh

   scbulletin -h

In addition, any module configuration parameter can be specified on
the command line overriding the configured parameter. For indicating that a
module configuration parameter is set on the command line separate the value
from the parameter by '=' and provide the full set of sections separated by '.'.
Example:

.. code-block:: sh

   scolv --picker.loadAllPicks=true

When executing a module, all verbosity output is logged to
:ref:`log files <concepts_modules_logging>`. The logging level can be controlled
by configuration or by the command-line option :option:`-v`.

.. code-block:: sh

   scbulletin -vvvv

Detailed debugging information can also be printed on the command line during
runtime using the :option:`--debug` option:

.. code-block:: sh

   scbulletin --debug

When starting a daemon module all verbosity output is stored in :file:`@LOGDIR@`
or :file:`$SEISCOMP_ROOT/var/log`. Daemon modules can also be executed as
:ref:`command-line tools <concepts_modules_commandline>`.


.. _concepts_modules_config:

Configuration
=============

Each :term:`standalone module` tries to read from three module configuration
files whereas :term:`trunk` modules try to read the six files. Note that
configuration parameters defined earlier are overwritten if defined in files
read in later:

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

In addition to the module configuration files some modules such as
:ref:`seedlink` or :ref:`scautopick` consider :term:`bindings <binding>`.
Bindings provide parameters specific to stations. They are configured as
per-station bindings or profiles used for multiple stations.

The :ref:`global configuration section <global-configuration>` describes all
available global configuration parameters for a trunk module. Modules typically
do not make use of all available global parameters because they may be disabled,
e.g., the messaging component. So the configuration of the messaging server is
disabled, too.

The concept section :ref:`Configuration <concepts_configuration>` provides more
details about configurations.


.. _concepts_modules_logging:

Logging
=======

Whenever operated, modules report the state of operation to log files. Trunk
modules report the module and the start up log to :file:`@LOGDIR@/[module].log` and
:file:`@ROOTDIR@/var/log/[module].log`, respectively. Standalone modules log to
:file:`@ROOTDIR@/var/log/[module].log` only. The log files are rotated and the
level of detail can be configured by :confval:`logging.level`. More parameters
in :confval:`logging.*` provide more control over logging, e.g., the log file
rotation.


.. _concepts_modules_aliaes:

Alias Modules
=============

Many :term:`trunk` and :term:`standalone modules <standalone module>` allow
generating aliases as symbolic links to another module.
These aliases are useful for running multiple instances of the same module with
different configuration.

Alias modules can be created or removed using the :ref:`seiscomp` tool by
providing the commands :command:`alias create` or :command:`alias remove`,
respectively. Read the documentation of :ref:`seiscomp <sec_seiscomp_aliases>`
for the details.
