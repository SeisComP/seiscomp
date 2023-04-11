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


Stations Magnitudes
===================

Station magnitudes are computed automatically by :ref:`scmag` or interactively
by :ref:`scolv` from measured amplitudes based on distance-dependent
calibration curves which depend on magnitude type.


Regionalization
---------------

The computation of station magnitudes can be regionalized. This means that for a
specific region different conditions apply for computing magnitudes. The conditions
include calibration curves, distance and depth ranges, etc. Regionalization
is achieved by adding magnitude-type profiles in the magnitudes section of
global module configuration parameters.


Aliases
-------

New magnitude types (aliases) can be created based on existing magnitude and
amplitude types with specific properties. Such aliases are defined by the
global parameter :confval:`magnitudes.aliases` and configured as any other
amplitude and magnitude in bindings or by regionalization.


Network Magnitudes
==================

Network magnitudes are computed automatically by :ref:`scmag` or interactively
by :ref:`scolv` from station magnitudes based on averaging station magnitudes.
The averaging methods applied by :ref:`scmag` are configurable by
:ref:`magnitudes.average`.


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
:term:`event`. This may also be done interactively by operators in :ref:`scolv`.
