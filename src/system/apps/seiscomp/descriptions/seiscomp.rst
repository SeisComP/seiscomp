The tool :program:`seiscomp` allows controlling your |scname| system on the
command line. As other |scname| modules it provides
options and commands, e.g., the command :command:`help`. Apply
:program:`seiscomp` to

* Install software dependencies,
* Print

  * environment variables of the installed |scname| system,
  * internal |scname| variables which can be used in configurations,
  * suggestions for timed automatic actions, i.e. "*conjobs*",

* Make a basic setup including the |scname| database,
* List daemon modules by categories,
* Enable or disable modules in order to start them by default,
* Start, stop, restart or reload single or multiple modules or all default
  modules,
* Check the status of module,
* Execute single or multiple modules or all default modules
* Print the run status of modules,
* Manage modules aliases,
* Update inventory or bindings configurations,
* Manage :ref:`bindings <binding>` by a specific shell.

.. note::

   When executing :program:`seiscomp`, all actions refer to the |scname|
   installation from within which :program:`seiscomp` is called. This allows
   to refer to a default but also to any other installed |scname| system and to
   operate multiple |scname| systems in parallel, e.g., for testing different
   versions or for running different projects. Then give the full path to the
   :program:`seiscomp` tools. Example:

   .. code-block:: sh

      $HOME/seiscomp-test/bin/seiscomp

Many of these actions are used by :ref:`scconfig`


.. _sec_seiscomp_help:

Help
====

Use the command :command:`help` for learning about the full set of options and
other commands including examples:

.. code-block:: sh

   seiscomp help


.. _sec_seiscomp_applications:

Applications
============


.. _sec_seiscomp_sw_deps:

Software dependencies
---------------------

Software dependencies should be installed after installation or updates of
|scname|. You may install dependencies on different levels, e.g., *base*,
*gui*, *fdswnws*, *[database]-server*. Examples:

.. code-block:: sh

   seiscomp install-deps base
   seiscomp install-deps base gui mariadb-server

Alternatively run the shell scripts for your Linux flavor and version located in
:file:`seiscomp/share/deps/`.

.. note::

   For making a full installation and setup follow the instructions starting
   with section :ref:`installation`.


.. _sec_seiscomp_print:

Print
-----

You may print the environment variables related to your considered |scname|
installation, internal |scname| variables or suggestions for timed automatic
procedures. Examples:

.. code-block:: sh

   seiscomp print env
   $HOME/seiscomp-test/bin/seiscomp print env
   seiscomp print variables
   seiscomp print crontab

Add the environment variables to your shell configuration for making them known
user wide. Internal variables are resolved when applying them in user
configurations. For adjusting, adding or removing :program:`crontab` listings
execute:

.. code-block:: sh

   man crontab
   crontab -e


.. _sec_seiscomp_setup:

Basic setup
-----------

Make a basic setup of your |scname| system interactively after installation.
This will also allow you to generate a database or to configure the connection
to an existing one. Run, e.g.

.. code-block:: sh

   seiscomp setup
   $HOME/seiscomp-test/bin/seiscomp setup


.. _sec_seiscomp_list:

List
----

List modules which can be started to run as background daemon modules by
categories. Examples:

.. code-block:: sh

   seiscomp list modules
   seiscomp list enabled
   seiscomp list started


.. _sec_seiscomp_enable:

Enable/disable
--------------

Enabled modules will be started to run as a background daemon module.
You may enable or disable one or multiple modules. Examples:

.. code-block:: sh

   seiscomp enable scautopick
   seiscomp enable scautopick scautoloc
   seiscomp disable scautopick scautoloc


.. _sec_seiscomp_start:

Start/stop/restart/reload
-------------------------

Start all enabled modules:

.. code-block:: sh

   seiscomp start

Stop all modules and start all enabled modules:

.. code-block:: sh

   seiscomp restart

Start/stop/restart specific modules

.. code-block:: sh

   seiscomp start scautopick scautoloc
   seiscomp stop scautopick scautoloc
   seiscomp restart scautopick scautoloc

In order to apply configurations, a module must be (re)started since it reads
any configuration only during startup. Restarts will create downtimes and should
be avoided as much as possible. In order to minimize downtimes, some modules
may apply changes in configuration by reloading during runtime without
restarting. For reloading you may use the command :command:`seiscomp reload`.
The application of reloading is therefore restricted to a limited range of
modules and parameters.

.. note::

   Graphical modules such as :ref:`scolv` cannot be operated as background
   daemon modules. Therefore, they cannot be started but they can
   be :ref:`executed <sec_seiscomp_execute>`.


.. _sec_seiscomp_check:

Check
-----

When modules stop unexpectedly, they are not stopped in a clean way. Such
stopped modules may be detected and started again in order to minimize
downtimes. Apply the :command:`check` command to all or specific modules.
Examples:

.. code-block:: sh

   seiscomp check
   seiscomp check scautopick


.. _sec_seiscomp_execute:

Execute
-------

Instead of running daemon modules you may execute modules in a terminal and
observe the output, e.g., for debugging or for applying command-line options.
Examples:

.. code-block:: sh

   seiscomp exec scolv --debug
   seiscomp exec scautopick --debug

.. note::

   When all relevant system environment variables point to the same |scname|
   installation from where seiscomp is executed, then it is enough to execute
   modules by their names replacing the above:

   .. code-block:: sh

      scolv --debug
      scautopick --debug


.. _sec_seiscomp_status:

Status
------

List the status of all, enabled, disabled, started, or specific modules.
Examples:

.. code-block:: sh

   seiscomp status
   seiscomp status enabled
   seiscomp status disabled
   seiscomp status started
   seiscomp status scautopick

:command:status` will report modules which terminated due to errors.


.. _sec_seiscomp_aliases:

Module Aliases
--------------

For some |scname| modules aliases can be generated allowing the separate
execution with specific configurations in parallel the original module
and even in separate pipeline with specific message groups.
Using the :command:`alias` command aliases modules can be created or removed.
Examples for creating or removing the alias :program:`l1autopick` to
:ref:`scautopick`:

.. code-block:: sh

   seiscomp alias create l1autopick scautopick
   seiscomp alias remove l1autopick

When creating aliases, soft links to the original module executable files, the
default configuration and the init files are created. The alias itself is
registered in :file:`SEISCOMP_ROOT/etc/descriptions/aliases`. If a module does
not allow creating aliases a notification is printed. Example:

.. code-block:: sh

   seiscomp alias create scolv1 scolv
   error: module 'scolv' not found

After creating aliases, they may be configured and operated in the same way as
the original module.

.. warning::

   The length of alias names for modules considering
   :ref:`bindings<global_bindings_config>` is strictly limited to 20 characters.

When removing aliases, all links and the alias registration are removed but
possibly existing module or binding configurations remained unchanged. The
option :option:`--interactive` allows removing these configurations
interactively.

.. code-block:: sh

   seiscomp --interactive alias remove l1autopick


.. _sec_seiscomp_update:

Update configuration
--------------------

The command :command:`update-config` allows reading bindings configurations from
the standard :file:`@KEYDIR@` directory as well as inventory from
:file:`@SYSTEMCONFIGDIR@/inventory` and sending them to the messaging for
storing in the database or for generating the configuration of
:term:`standalone modules <standalone module>`:

.. code-block:: sh

   seiscomp update-config

Executing :command:`seiscomp update-config` involves:

* Merging inventory,
* Sending inventory updates to the messaging,
* Synchronisation of inventory, key files and bindings,
* Sending any updates of bindings to the messaging,
* Generation of configuration for :term:`standalone modules <standalone
  module>`.

The command can therefore be rater time consuming. For speeding up you may be
more specific:

* Only update global bindings and all :term:`trunk` modules without inventory

  .. code-block:: sh

     seiscomp update-config trunk

* Update only inventory

  .. code-block:: sh

     seiscomp update-config inventory

* Update bindings of :ref:`scautopick` only

  .. code-block:: sh

     seiscomp update-config scautopick

  The command may be similarly applied to any other  module considering
  bindings.

.. note::

   Instead of reading bindings configurations from the standard @KEYDIR@
   directory, the module :ref:`bindings2cfg` can read bindings from any key
   directory and write the Config parameters to :term:`SCML` or send them to
   the messaging.


.. _sec_seiscomp_shell:

seiscomp Shell
==============

The seiscomp shell is a special environment, e.g., allowing to control
:term:`bindings <binding>` of :term:`modules <module>` to stations.

Applications are:

* Create or remove station bindings,
* Create or remove binding profiles,
* Remove binding profiles.

Invoke :program:`seiscomp` along with the  :command:`shell` command to start the
shell:

.. code-block:: sh

   seiscomp shell


     ================================================================================
     SeisComP shell
     ================================================================================

     Welcome to the SeisComP interactive shell. You can get help about
     available commands with 'help'. 'exit' leaves the shell.

     $


The full list of shell control commands are printed along with the help of the
seiscomp shell:

.. code-block:: sh

   ================================================================================
   SeisComP shell
   ================================================================================

   Welcome to the SeisComP interactive shell. You can get help about
   available commands with 'help'. 'exit' leaves the shell.

   $ help
   Commands:
     list stations
       Lists all available stations keys.

     list profiles {mod}
       Lists all available profiles of a module.

   ...
