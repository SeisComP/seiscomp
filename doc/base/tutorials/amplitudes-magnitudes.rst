.. _tutorials_magnitude-region-aliases:

***************************************************
Amplitudes/Magnitudes: Regionalization, Aliases, Mw
***************************************************

You will ...

* Regionalize magnitudes.
* Create new amplitude and magnitude types as aliases from other amplitudes and
  magnitudes.
* Map magnitudes to the moment magnitude, Mw.


:Pre-requisites for this tutorial:

  * Read the :ref:`concepts section on magnitudes <concepts_magnitudes>`.
  * Real-time data for the station must be available locally.
    See :ref:`tutorials_waveforms` or :ref:`tutorials_geofon_waveforms`.
  * Inventory must be loaded locally.


:Afterwards/Results/Outcomes:

  * Regionalized amplitudes and magnitudes
  * New amplitude and magnitude types as aliases
  * Moment magnitudes


:Time range estimate:

  * 60 minutes


-----------


Regionalization
===============


By regionalization, amplitudes and magnitudes can be computed depending on the
region of the source or source-receiver pairs.
Regions are defined by polygons in BNA or GeoJSON files which must be known to
|scname|.


.. _tutorials_amplitudes-region:

Amplitudes
----------

Measuring amplitudes only for sources or pairs of sources and stations in
specific regions is possible by regionalization. The region polygons are defined
by :ref:`magnitude regionalization <tutorials_magnitude-region>`. In
order to use the feature, regionalized amplitudes and magnitudes must have the
same type (name) and regionalization must be activated per amplitude type in
amplitude-type profiles of global bindings.


.. _tutorials_magnitude-region:

Magnitudes
----------

With regionalization magnitudes can be computed with region-dependent parameters.
If magnitude regionalization is configured but a source or source-station pairs
are not considered, no magnitude of the corresponding type is computed.


Setup
~~~~~

The procedure to set up magnitude regionalization is:

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
#. Configure the :confval:`magnitudes.MLc.regionFile` parameter with the full
   path and name of the polygon file created above.
#. Within the magnitude-type profile create one or more magnitude-region
   profile(s) for defining the regionalized parameters applied to the region(s).
   The name of a profile corresponds to the name of the polygon contained in the
   polygon file to which the parameters shall apply. Use *world* for all regions
   not covered by any polygon.
#. Configure the regionalized magnitude parameters of the magnitude-region
   profile. Activate the *enable* parameter if you wish to apply this profile.
#. Restart the data processing:

   .. code-block:: sh

      seiscomp restart

   or execute a GUI module.

.. important::

   * Parameters which can be configured along with regionalization assume
     defaults from global binding parameters but override global bindings
     parameters when configured.
   * Once regionalization is active, magnitudes for events outside the
     defined region(s) will not be computed. For considering such events add
     another magnitude-region profile with the name "*world*".
     Magnitudes for events outside any other magnitude-region profile will then
     be computed according to this profile.


Setup: station corrections
~~~~~~~~~~~~~~~~~~~~~~~~~~

:ref:`Magnitude station corrections <concepts-magnitudes-correction>` can also
be applied in case of reBy regionalization, magnitudes can be computed with region-dependent properties.
Regions are defined by polygons in BNA or GeoJSON files which must be known to
|scname|.gionalization. Simply add the names of the
magnitude-region profile along with the correction parameter to the original
parameter in global module configuration, :file:`global.cfg`, for the respective
magnitude type and station. Use comma separation for multiple regions and colon
for separating the region name from the value.

Example for correcting MLv computed at station GE.UGM:

.. code-block:: properties

   module.trunk.GE.UGM.magnitudes.MLv.offset = 0.1, europe:0.2, asia:-0.1

.. note::

   The configuration of parameters starting with *module.trunk.* is not
   supported by :ref:`scconfig`. All corresponding configurations must be done
   by directly editing the configuration file, e.g.,
   :file:`seiscomp/etc/global.cfg`.


Application
~~~~~~~~~~~

When configured, regionalization is automatically applied when computing
magnitudes in :ref:`scmag` or :ref:`scolv`.


.. _tutorials_mags_regionalize_testing:

Testing
~~~~~~~

* Regionalization:

  #. Start :ref:`scolv` with the option :option:`--debug` and load an event of
     interest

     .. code-block:: sh

        scolv --debug

  #. Relocate the event for generating a new origin.
  #. Compute magnitudes selecting the magnitude of interest.
  #. Inspect the computed magnitudes in the
     :ref:`Magnitude tab of scolv <scolv-sec-magnitude-tab>` or read the
     debug output listing the considered magnitudes and stations along with
     the regionalized parameters.


.. _tutorials_amplitude-aliases:

Amplitude Aliases
=================

Amplitude aliases are new amplitude types based original ones. Such aliases
allow their specific configuration and computation. They can be created and
independent of magnitudes by :ref:`scautopick` and :ref:`scamp` and used for
:ref:`magnitude aliases <tutorials_magnitude-aliases>`.

.. note::

   Amplitude aliases make use of the same parameter structure as the initial
   amplitude but the parameters must be configured independently.


Setup
-----

#. Global module configuration: Define the alias name in :confval:`amplitudes.aliases`.

   Format and example:

   .. code-block:: properties

      amplitudes.aliases = alias:original amplitude type
      amplitudes.aliases = MLc01:MLc

#. Configure the amplitude bindings parameters. The parameters are identical to
   those of the original amplitude type except that the name of the original
   magnitude must be replaced by the name of the alias. You may thus first
   configure the original amplitude and then replace the name.

   **Example binding configuration** for MLc01 derived from MLc:

   .. code-block:: properties

      amplitudes.MLc01.preFilter = BW(3,0.5,12)
      amplitudes.MLc01.applyWoodAnderson = true
      ...
      amplitudes.MLc01.enable = true
      amplitudes.MLc01.enableResponses = false
      amplitudes.MLc01.minSNR = 1.5
      amplitudes.MLc01.signalBegin = -1
      amplitudes.MLc01.signalEnd = min(tt(S) + 10, 150)
      ...
      amplitudes.MLc01.maxDepth = 50

   Repeat the action for all applicable binding profiles.

   Instead of adjusting the bindings profiles you may add the configuration to
   global or any other module configuration by prepending
   *module.trunk.[module]* where *[module]* is to be replaced by the name of the
   module including *global*.

   **Example global module configuration** in :file:`global.cfg`:

   .. code-block:: properties

      module.trunk.global.amplitudes.MLc01.preFilter = BW(3,0.5,12)
      module.trunk.global.amplitudes.MLc01.applyWoodAnderson = true
      ...
      module.trunk.global.amplitudes.MLc01.enable = true
      module.trunk.global.amplitudes.MLc01.enableResponses = false
      module.trunk.global.amplitudes.MLc01.minSNR = 1.5
      module.trunk.global.amplitudes.MLc01.signalBegin = -1
      module.trunk.global.amplitudes.MLc01.signalEnd = min(tt(S) + 10, 150)
      ...
      module.trunk.global.amplitudes.MLc01.maxDepth = 50

   Configuration of bindings profiles has the advantage that the parameters are
   available on any client connected to the messaging including external
   SeisComP systems. Writing to global module configuration may be more simple
   than maintaining multiple bindings profiles but the configuration is not
   available to clients in external computers/SeisComP systems.


Application
-----------

* For automatic measurement by :ref:`scautopick` or :ref:`scamp` add the alias
  name to the list of measured amplitudes in the corresponding module
  configuration.
* For using the measured amplitude value with magnitudes, create a
  :ref:`magnitude alias <tutorials_magnitude-aliases>`.


Testing
-------

Compute amplitudes with :ref:`scamp` or by magnitude aliases in :ref:`scolv` and
read the debug log output as when testing
:ref:`magnitude aliases <tutorials_mags_aliases_testing>`.


.. _tutorials_magnitude-aliases:

Magnitude Aliases
=================

Magnitude aliases are new magnitude types based original ones. Such aliases
allow their specific configuration and computation. They can be created from
magnitude and amplitude types native in |scname| or from
:ref:`amplitude aliases <tutorials_amplitude-aliases>` which must be defined
first. Unless specified explicitly, the amplitude type
is the base amplitude of the original magnitude.
Other amplitude types or amplitude aliases must be defined first and given
explicitly.

.. note::

   Magnitude aliases make use of the same parameter structure as the initial
   magnitude but the parameters must be configured independently.


Setup
-----

#. Create a magnitude alias in :file:`global.cfg` by configuring
   :confval:`magnitudes.aliases`.

   Format:

   .. code-block:: properties

      magnitudes.aliases = alias:original magnitude type[:amplitude type]

   The amplitude type is optional and can be omitted when equal to the type of
   the original magnitude.

   Example for an alias magnitude, MLc1, derived from the MLc magnitude and
   amplitude. Since initial amplitudes and magnitudes are identical, the
   amplitude type can be dropped:

   .. code-block:: properties

      magnitudes.aliases = MLc01:MLc:MLc
      magnitudes.aliases = MLc01:MLc

   Example for an alias magnitude, MLc1, derived from the MLc magnitude and
   amplitude. Since initial amplitudes and magnitudes are different, the
   amplitude type must be given and
   :ref:`configured independently <tutorials_amplitude-aliases>`

   .. code-block:: properties

      magnitudes.aliases = MLc01:MLc:MLc01

#. Configure the alias amplitude if any is used.
#. Configure the alias magnitude in **either** way:

   * **Adjust binding profiles:** Configure global bindings parameters by
     directly adjusting binding profiles.

     Parameters of original magnitudes which are supported by magnitude-type
     profiles can be set for the magnitude alias in :ref:`scconfig` by creating
     a new magnitude-type profile having the name of the magnitude alias.

     All other parameters must be written to the binding parameter files using
     an external text editor:

     #. Read the relevant parameter names of the original magnitude from global
        binding, e.g., in :ref:`scconfig` or the binding parameter file.
        Parameter names must include the full hierarchy including all sections.
        Example for parameter name of original magnitude:

        .. code-block:: properties

           magnitudes.MLc.parametric.c1

     #. Edit all relevant binding parameter files, e.g.,
        :file:`seiscomp/etc/key/global/profile_HHZ` in a text editor and set the
        values for the alias magnitude. For default values, the parameters do not
        need to be set.

        Example of resulting parameter for alias magnitude MLc01:

        .. code-block:: properties

           magnitudes.MLc01.parametric.c1 = 0.6


   * **Regionalization:** Set up by :ref:`regionalization <tutorials_magnitude-region>`.

     * Consider the tutorial above on
       :ref:`magnitude regionalization <tutorials_magnitude-region>`.
     * For the name of new magnitude-type profiles now use the new alias name.

   .. hint::

      When initially configuring amplitude and magnitude aliases, :ref:`scconfig`
      does not know which original amplitude and magnitude types are considered and
      the corresponding parameters may not be accessible.
      The full list of parameters of the alias can, however, be derived from
      original types:

      #. Open scconfig and configure the original amplitude and magnitude
         referenced by the alias.
      #. Close scconfig.
      #. Open the binding or module configuration file, e.g.,
         :file:`seiscomp/etc/key/global/profile_HHZ` or :file:`global.cfg`.
      #. Copy or rename the name of the referenced amplitude or magnitude in the
         parameters to the name of the alias.
      #. Open scconfig. The new parameters are now visible along with the
         original one and can be adjusted. You may now remove all
         irrelevant parameters of the original magnitude.

      This procedure applies to the adjustment of binding profiles and to
      regionalization except that regionalization only supports magnitudes.

   * **Write bindings parameters to global module configuration:** Manually
     adjust the module configuration file, e.g., :file:`global.cfg`. The
     operation is not supported by :ref:`scconfig`.

     #. Read the relevant parameter names of the original magnitude from global
        binding, e.g., in :ref:`scconfig`. The names must include the full
        hierarchy including all sections. Example:

        .. code-block:: properties

           magnitudes.MLc01.parametric.c1

     #. Open the module configuration file, e.g.,
        :file:`seiscomp/etc/global.cfg` in a text editor.

     #. Prepend *module.trunk.global.* to the parameter name and add it along with
        its value to the configuration file for all networks and stations.
        Example:

        .. code-block:: properties

           module.trunk.global.magnitudes.MLc01.parametric.c1 = 0.7

        For a given network or network and station replace *global* by the
        *network* or the *network* and the *station* code. Example for network
        CX and station PB01:

        .. code-block:: properties

           module.trunk.CX.PB01.magnitudes.MLc01.parametric.c1 = 0.7
           module.trunk.CX.magnitudes.MLc01.parametric.c1 = 0.7

     #. Add the new magnitude name to the configuration of all relevant modules,
        e.g., :ref:`scamp`, :ref:`scmag`, :ref:`scevent`, :ref:`scolv`.

     .. note::

        The parameters starting with *module.trunk.* are not available for
        configuration in :ref:`scconfig`.

     .. warning::

        Binding parameters configured in global module configuration should only
        be considered exceptionally. These parameters will

        * Override the corresponding parameters configured by regionalization
          using the region *world*.
        * Not be written to the database and cannot be accessed by SeisComP
          modules running on other computers.


Application
-----------

* For automatic computation by :ref:`scmag` add the alias name to the list of
  measured magnitudes in the corresponding module configuration.
* For interactive computation choose the magnitude alias name in :ref:`scolv`
  when computing magnitudes. The alias may be added to the default magnitudes in
  the scolv module configuration.


.. _tutorials_mags_aliases_testing:

Testing
-------

#. Start :ref:`scolv` with the option :option:`--debug` and load an event of
   interest

   .. code-block:: sh

      scolv --debug

#. Relocate the event for generating a new origin.
#. Compute magnitudes selecting the magnitude of interest including the new
   alias.
#. Inspect the computed magnitudes in the
   :ref:`Magnitude tab of scolv <scolv-sec-magnitude-tab>` or read the
   debug output listing the considered magnitude names and aliases along with
   the considered parameters and their values. Example where MLc1 is derived
   from MLc with a modified maximum depth:

   .. code-block:: sh

      ...
      13:30:46 [debug] GE.UGM: MLc1: effective correction (no locale) = 1.00:0.00
      13:30:46 [debug] Parameters for magnitude MLc1
      13:30:46 [debug]   + maximum depth: 50.000 km
      13:30:46 [debug]   + distance mode: hypocentral
      13:30:46 [debug]   + minimum distance: -1.000 km
      13:30:46 [debug]   + maximum distance: 889.561 km
      ...


.. _tutorials_mags_moment:

Moment Magnitudes
=================

All magnitudes, Mx, can be mapped to a moment magnitude, Mw(Mx) by piecewise
linear interpolation.

.. warning::

   Do not map :term:`mB <magnitude, broadband body-wave (mB)>`
   or :term:`Mwp <magnitude, broadband P-wave moment (Mwp)>` to Mw since
   this is hardcoded already and done automatically by :ref:`scmag`.


Setup
-----

The configuration procedure is:

#. Set up a magnitude-type profile for the original magnitude type in global
   module configuration. Use :ref:`scconfig` for creating the profile.
#. Configure the parameter *MwMapping*, which will become available along with
   the new profile, e.g., :confval:`magnitudes.MLc.MwMapping`. Alternatively,
   add the parameter to :file:`seiscomp/etc/global.cfg`. The parameter is
   configured as a list of sample points of a piecewise linear function mapping
   from the original magnitude, Mx, to Mw(Mx).
   Example for Mw(MLc) based on MLc:


   .. code-block:: properties

      magnitudes.MLc.MwMapping = MLc_0:Mw(MLc)_0,MLc_1:Mw(MLc)_1,...,MLc_N:Mw(MLc)_N

   Any magnitude value outside the configured range is ignored.

The new moment magnitudes will be available along with the original magnitudes
and can be viewed in :ref:`scolv` or :ref:`scesv` and considered by :ref:`scmag`
or :ref:`scevent`.

In order to avoid that :ref:`summary magnitudes <concepts-magnitudes-summary>`
are computed from original magnitudes and mapped Mw together and biased to both,
the original magnitudes can be blocklisted in :ref:`scmag`
(:confval:`summaryMagnitude.blacklist`).


Application
-----------

* Mapped Mw() magnitudes are automatically computed when configured.
* For consideration in summary magnitudes configure and run :ref:`scmag`.
* For consideration in preferred magnitudes configure and run :ref:`scevent` or
  select in :ref:`scolv`.
* For interactive computation choose the original magnitude name in :ref:`scolv`
  when computing magnitudes.
