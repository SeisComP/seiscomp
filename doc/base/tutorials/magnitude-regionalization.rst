.. _tutorials_magnitude-region-aliases:

***************************************
Magnitudes: Regionalization and Aliases
***************************************

You will ...

* Regionalize magnitude
* Create new magnitudes as aliases from other magnitude and amplitude types.


:Pre-requisites for this tutorial:

  * Read the :ref:`concepts section on magnitudes <concepts_magnitudes>`.
  * Real-time data for the station must be available locally.
    See :ref:`tutorials_waveforms` or :ref:`tutorials_geofon_waveforms`.
  * Inventory must be loaded locally.


:Afterwards/Results/Outcomes:

  * Regionalized magnitudes,
  * New magnitude types as aliases.


:Time range estimate:

  * 30 minutes


-----------


.. _tutorials_magnitude-region:

Regionalize Magnitudes
======================

#. Create one file which contains the polygons surrounding the regions within
   which magnitude parameters shall apply. The polygon files are provided in
   :ref:`BNA <sec-gui_layers-vector-format-bna>` or
   :ref:`GeoJSON format <sec-gui_layers-vector-format-geojson>` and located as
   set out in the :ref:`documentation of map layers <sec-gui_layers>`. The file
   can be created from any |scname| GUI application providing maps, e.g.,
   :ref:`scmv`.
#. For the desired magnitude type create a magnitude-type profile in global
   module configuration. The name of the profile matches the name of the
   magnitude, e.g., *MLc* for the :ref:`MLc magnitude <global_mlc>`.
#. Configure the :confval:`m̀agnitudes.MLc.regionFile` parameter with the full
   path and name of the polygon file created above.
#. Within the magnitude-type profile create one or more magnitude-region
   profile(s) for defining the regionalized parameters applied to the region(s).
   The name of a profile corresponds to the name of the polygon contained in the
   polygon file to which the parameters shall apply.
#. Configure the regionalized magnitude parameters of the magnitude-region
   profile. Activate the *enable* parameter if you wish to apply this profile.
#. Restart the data processing:

   .. code-block:: sh

      seiscomp restart

   or execute a gui module.

.. important::

   * Parameters which can be configured along with regionalization assume
     defaults from global binding parameters but override global bindings
     parameters when configured.
   * Once regionalization is active, magnitudes for events outside the
     defined region(s) will not be computed. For considering such events add
     another magnitude-region profile with the name "*world*".
     Magnitudes for events outside any other magnitude-region profile will then
     be computed according to this profile.


Station corrections
-------------------

:ref:`Magnitude station corrections <concepts-magnitudes-correction>` can also
be applied in case of regionalization. Simply add the names of the
magnitude-region profile along with the correction parameter to the original
parameter in global module configuration, :file:`global.cfg`, for the respective
magnitude type and station. Use comma separation for multiple regions and colon
for separating the region name from the value.

Example for correcting MLv computed at station GE.UGM:

.. code-block:: properties

   module.trunk.GE.UGM.magnitudes.MLv.offset = 0.1, europe:0.2, asia:-0.1


Magnitude Aliases
=================

#. Create a magnitude alias in :file:`global.cfg` by configuring
   :confval:`magnitudes.aliases`.
#. Configure the alias magnitudes in global bindings or set up
   :ref:`regionalization <tutorials_magnitude-region>`:

   **Bindings:**

   #. create new amplitude- and magnitude-type profiles in global bindings. The
      names of the profiles correspond to the names of the alias.
   #. configure these new profiles.
   #. update bindings configuration and restart the data processing
      or execute a gui module:

      .. code-block:: sh

         seiscomp update trunk
         seiscomp restart

   **Regionalization:**

   * consider the tutorial on regionalization above,
   * for the name of the new magnitude-type profile now use the alias name.

     .. hint::

        When adding the magnitude-region profile in
        :ref:`scconfig`, scconfig does not know about the referenced original
        magnitude. Therefore, not all possible configuration parameters are
        listed. For getting the full list, first create and configure a
        magnitude-region profile for the referenced magnitude. Then you may

        #. Close scconfig
        #. Open the configuration file :file:`global.cfg`
        #. Rename the name of the referenced magnitude in the parameters to the name
           of the alias.


.. _tutorials_mags_regionalize_testing:

Final Tests
===========

* Regionalization:

  #. Start :ref:`scolv` with the option :option:`--debug` and load an event of
     interest.
  #. Relocate the event for generating a new origin.
  #. Compute magnitudes selecting the magnitude of interest.
  #. Inspect the computed magnitudes in the
     :ref:`Magnitude tab of scolv <scolv-sec-magnitude-tab>` or read the
     debug output listing the considered magnitudes and stations along with
     the regionalized parameters.

* Magnitude aliases:

  #. Start :ref:`scolv` with the option :option:`--debug` and load an event of
     interest.
  #. Relocate the event for generating a new origin.
  #. Compute magnitudes selecting the magnitude of interest including the new
     alias.
  #. Inspect the computed magnitudes in the
     :ref:`Magnitude tab of scolv <scolv-sec-magnitude-tab>` or read the
     debug output listing the considered magnitude names and aliases.
