.. _concepts_magnitudes:

Magnitudes
##########

Magnitudes are computed based on amplitudes measured from waveforms. Different
types of amplitudes and magnitudes are available which are listed in
:ref:`scamp` and :ref:`scmag`.


Amplitudes
==========

Amplitudes can be measured automatically from waveforms

* During phase picking by :ref:`scautopick` with generally fixed time windows
  due to the absence of knowledge about source parameters or by,
* :ref:`scamp` as soon as :term:`origins <origin>` are available. Depending
  on the magnitude type, fixed or distance-dependent time windows apply.

and interactively using :ref:`scolv`.


Instrument simulation
---------------------

Amplitude measurements for some magnitude types require or allow the simulation
of instruments such as :py:func:`Wood-Anderson torsion seismometers <WA>`
(:cite:t:`richter-1935,uhrhammer-1990`), :py:func:`WWSSN_SP` or :py:func:`WWSSN_LP`.
The calibration parameters describing the Wood-Anderson seismometer are
configurable in global bindings or global module configuration:
:confval:`amplitudes.WoodAnderson.gain`, :confval:`amplitudes.WoodAnderson.T0`,
:confval:`amplitudes.WoodAnderson.h`. Specifically, the difference in magnitude
due to configuration using original values listed in
:cite:t:`richter-1935` and updated ones given in :cite:t:`uhrhammer-1990`
result in a constant offset of 0.13 in those magnitudes which apply
Wood-Anderson simulation, e.g. :term:`ML <magnitude, local (ML)>`,
:term:`MLv <magnitude, local vertical (MLv)>`, :term:`MLc <magnitude, local custom (MLc)>`.


Station Magnitudes
==================

Station magnitudes are computed automatically by :ref:`scmag` or interactively
by :ref:`scolv` from measured amplitudes based on distance-dependent
calibration curves which depend on magnitude type. When computing a set of
magnitudes in :ref:`scolv` which is different from the set configured in
:ref:`scmag`, then scmag may later add the missing magnitudes automatically.
Magnitude types for which the evaluation status is set to "rejected", e.g., in
scolv, will not be recomputed by scmag.


.. _concepts-magnitudes-correction:

Station corrections
-------------------

Linear station corrections applied to station magnitudes can be configured by
global :ref:`binding parameters <global_bindings_config>`:

#. Add a magnitude type profile where the name of the profile is the name of the
   magnitude itself,
#. Configure the correction parameters.

When using binding profiles, all referencing stations will be affected equally
which is typically not intended. In contrast, applying station bindings requires
to set up many bindings which may not be intended either.

Therefore, you may add lines to the global module configuration in
:file:`global.cfg` where one line corresponds to one station with one magnitude
and the corresponding correction parameter. The groups and the name of the
parameters are identical to the global bindings parameters. All lines start with
"*module.trunk*". Example for an offset correction of
:term:`MLv <magnitude, local vertical (MLv)>` measured station GE.UGM:

.. code-block:: properties

   module.trunk.GE.UGM.magnitudes.MLv.offset = 0.1


.. _concepts-magnitudes-regionalization:

Regionalization
---------------

The computation of station magnitudes can be regionalized. This means that for
a specific region specific conditions apply when computing magnitudes. The
conditions include any parameter available for configuring a magnitude
including global binding parameters such as magnitude calibration, distance
and depth ranges, etc. As an example you may wish to apply different
attenuation curves for computing MLv magnitudes to earthquakes in Eastern and
in Western Canada.

Regionalization is achieved by adding magnitude-type profiles in the magnitudes
section of global module configuration parameters. Regionalization assumes
defaults from global bindings but overrides the values when configured. The
setup procedure including
:ref:`station corrections <concepts-magnitudes-correction>` is outlined in the
:ref:`tutorial on regionalization <tutorials_magnitude-region-aliases>`.


Aliases
-------

New magnitude types (aliases) can be created based on existing magnitude and
amplitude types with specific properties. Such aliases are defined by the
global parameter :confval:`magnitudes.aliases` and configured as any other
amplitude and magnitude in bindings or by regionalization.
The setup procedure is outlined in the
:ref:`tutorial on magnitude aliases <tutorials_magnitude-region-aliases>`.


Network Magnitudes
==================

Network magnitudes are computed automatically by :ref:`scmag` or interactively
by :ref:`scolv` from station magnitudes based on averaging station magnitudes.
The averaging methods applied by :ref:`scmag` are configurable by
:confval:`magnitudes.average`.


Moment Magnitudes
=================

Moment magnitudes can be derived from all other network magnitudes by mapping of
the original network magnitude, e.g., *Mx*, to a new moment magnitude *Mw(Mx)*.
The mapping function can be configured within a magnitude type profile for all
original magnitude types except :term:`mB <magnitude, derived mB (Mw(mB))>` and
:term:`Mwp <magnitude, derived Mwp (Mw(Mwp))>` in the global module configuration.
Any mapping configuration for :term:`mB <magnitude, derived mB (Mw(mB))>` and
:term:`Mwp <magnitude, derived Mwp (Mw(Mwp))>` is ignored since a hard-coded
mapping applied.

In order to avoid that :ref:`summary magnitudes <concepts-magnitudes-summary>`
are computed from original magnitudes and mapped Mw together and biased to both,
the original magnitudes can be blocklisted in :ref:`scmag`
(:confval:`summaryMagnitude.blacklist`).


.. _concepts-magnitudes-summary:

Summary Magnitude
=================

In order to account for different phenomena related to magnitude computation
including magnitude saturation and application of different magnitude types at
specific distance and depth ranges of the sources a summary magnitude can be
computed from network magnitudes by :ref:`scmag`. The summary magnitude is
usually referred to as *M*. The name is configurable.

.. note::

   Station, network and summary magnitudes are contained uniquely in one
   :term:`origin`.


Preferred Magnitude
===================

From the list of computed network magnitudes and the summary magnitude,
:ref:`scevent` can automatically determine the preferred magnitude of the
:term:`event`. This may also be done interactively by operators in the
:ref:`Event tab of scolv <scolv-sec-event-tab>` or by
:ref:`custom commit buttons in scolv <sec-scolv-custom-commit>`.
