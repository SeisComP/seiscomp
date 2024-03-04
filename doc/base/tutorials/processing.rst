.. _tutorials_processing:

******************************
Configure real-time processing
******************************

You will enable processing by your existing local SeisComP system.


:Pre-requisites for this tutorial:

  * Real-time data for the station must be available locally.
    See :ref:`tutorials_waveforms` or :ref:`tutorials_geofon_waveforms`.
  * Inventory must be loaded locally.

:Afterwards/Results/Outcomes:

  * The new station is available for visualization and general data processing.
  * The new station is used for automatic real-time phase picking.

:Time range estimate:

  * 10 minutes.

:Related tutorial(s):

  * :ref:`tutorials_addstation`

-----------


Create bindings
===============

In SeisComP terminology, *bindings* are the connection between modules
and individual stations.
See the "Bindings" section of :ref:`concepts_configuration` for full details.

You can create the necessary bindings for your new station
using :ref:`scconfig`.
Go to the "Bindings" tab on the left side bar of :ref:`scconfig`.

* You will need to add  "global" and "scautopick" bindings.

  * Create a global profile named "BH" by clicking with the right button on "global"
    in the top right panel. Double click on it and set BH as *detectStream* and
    empty location code as *detecLocID* information.
    Adjust these as appropriate for your station.

  * Create a *scautopick* profile named "default" (no changes necessary).

  * Drag and drop all profiles from the right side to the network icon on the
    left side (you may do that also at the station level).

  * Press :kbd:`Ctrl`+:kbd:`S` to save the configuration.
    This writes configuration files in :file:`~/seiscomp/etc/key`.

* Alternatively, you can add the scautopick and global bindings
  by editing the relevant top-level key file.
  (For station CLL of the GR network, this would be :file:`etc/key/station_GR_CLL`.)
  It would contain:

  .. code::

      # Binding references
      global
      scautopick:default

  in addition to any other bindings that might be defined for this station.

Then execute:

.. code-block:: sh

   $ seiscomp update-config
   $ seiscomp restart scautopick

or use :ref:`scconfig` for these actions.

.. note::

   * Station inventory must be available at least on channel level and the global
     bindings must match the inventory and the available waveforms.
   * Global bindings are required for data visualization and general data
     processing.
   * Enable :ref:`scautopick` for running it by default.
   * Generated picks may be used by other modules, such as :ref:`scautoloc`
     which must be set up independently.
   * The default parameters for :ref:`scautopick` have been optimized for
     monitoring earthquakes at teleseismic distances and the must be adjusted
     for other types.


Check the station is used for processing
========================================

If you have correctly configured the station for processing, then:

* On restarting :program:`scautopick`, the station appears in the
  :file:`scautopick.log` log
  file in :file:`~/.seiscomp/log`::

    2020/03/01 18:01:00 [info/Autopick] Adding detection channel GR.CLL..BHZ

  After some time, a nearby event will occur and phases recorded on this station
  should be picked. If :ref:`scautoloc` was running at the time and
  :confval:`autoloc.pickLogEnable` was activated, the pick should appear in the
  latest :file:`autoloc-picklog` file in :file:`~/.seiscomp/log`:

  .. code-block:: sh

     $ grep "CLL" .seiscomp/log/autoloc-picklog.2020-03-01
     2020-03-01 18:31:47.1 GR CLL    BHZ __   40.9    177.433  1.1 A 20200301.183147.13-AIC-GR.CLL..BHZ

* The station should now also appear in the GUIs.
  After reopening them,

  * The station should now show up in :program:`scmv`
    (as a new triangle at the expected location on the map,
    which is not black if the station is active).

  * In :program:`scrttv` a trace or at least the line for the configured stream
    should be visible.

  * In :program:`scolv`, the new station is either already included
    in automatic locations, or can be added manually.

In case of problems, check that :confval:`detecStream` and
:confval:`detecLocid` are set correctly.
They must match both what is in inventory and the waveforms provided
from the upstream server.
