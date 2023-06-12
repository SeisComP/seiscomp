.. _concepts_locators:

Locators
########

Locators receive :term:`phase picks <pick>` from modules such as :ref:`scautoloc`,
:ref:`screloc` or :ref:`scolv` for locating seismic or non-seismic sources. The
solutions may include source time and location with or without uncertainties.
They are used to form new :term:`origins <origin>` which can be treated
further.

|scname| ships with built-in locators:

* :ref:`FixedHypocenter <global_fixedhypocenter>` (FH)
* :ref:`Hypo71 <global_hypo71>`
* :ref:`iLoc <global_iloc>`
* :ref:`LOCSAT <global_locsat>`, the default locator in :ref:`scautoloc` and :ref:`scolv`
* :ref:`NonLinLoc <global_nonlinloc>`
* :ref:`StdLoc <global_stdloc>`

and a none built-in locator:

* :ref:`LocExt <global_locext>`.

While the built-in locators are well defined and documented, any other external
locator routine can be added to |scname| by configuration of the locator
:ref:`LocExt <global_locext>` and custom scripts.
LOCSAT and FixedHypocenter are native to |scname|. All other locators are
implemented as :term:`plugins <plugin>`. A :term:`plugin`
needs to be added to the list of loaded plugins by configuration of the global
parameter :confval:`plugins` for making the corresponding locator available to
|scname| applications.

A comparison of the locators is given in the table below.

.. note::

   The specifications given below may depend on the configuration of the
   respective locator. Please carefully read the documentation of the locators
   for optimizing their performance.

.. csv-table::
   :widths: 30 10 10 10 10 10 10 10
   :header: , FH, Hypo71, iLoc, LocExt, LOCSAT, NonLinLoc, StdLoc
   :align: center

   **Applications**, ,,,,,,
   phases considered by default,                    seismic / infrasound, seismic, seismic / infrasound / hydroacoustic, [3], seismic / infrasound,  seismic, seismic
   distance ranges of application,                  local / regional / teleseismic, local / regional, local / regional / teleseismic, [3], local / regional / teleseismic, local / regional / teleseismic, local / regional [4]
   application with default configuration,          regional / teleseismic,  ❌, regional / global, [3], regional / teleseismic,  ❌,  local / regional [1]
   **Algorithm**, ,,,,,,
   inversion algorithm,                             linear,  iterative, configurable, [3], grid search, probabilistic, configurable
   automatic phase renaming,                        ❌, ❌, ✅, [3], ❌, ❌, ❌
   considers network code,                          ✅, ❌, ✅, [3], ✅, ✅ [1], ✅
   positive station elevation,                      ✅ [2/4], ✅, ✅, [3], ✅ [2], ✅, ✅
   negative station elevation,                      ❌, ✅, ✅, [3], ❌, ✅, ✅
   considers pick time,                             ✅, ✅, ✅, [3], ✅, ✅, ✅
   considers pick slowness,                         ❌, ❌, ✅, [3], ✅, ❌, ❌
   considers pick backazimuth,                      ❌, ❌, ✅, [3], ✅, ❌, ❌
   speed,                                           fast, fast, fast - intermediate, [3], fast, intermediate, fast - intermediate
   **Velocity model**, ,,,,,,
   velocity model,                                  1D [4], 1D, 1D, [3],1D, 1D / 3D, 1D / 3D [4]
   independent Vp and Vs,                           ✅ [4], ❌, ✅, [3], ✅, ✅, ✅ [4]
   default velocity model,                          iasp91 / tab, ❌, iasp91 / ak135, [3], iasp91 / tab, ❌, iasp91 / tab [1]
   applies RSTT,                                    ❌ , ❌, ✅, [3], ❌, ❌, ❌
   **Hypocenter solution**, ,,,,,,
   inverts for hypocenter location,                 ❌, ✅, ✅, [3], ✅, ✅, ✅
   inverts for hypocenter time,                     ✅, ✅, ✅, [3], ✅, ✅, ✅
   supports negative source depth,                  ❌, ✅, ❌, [3], ❌, ✅, ✅
   **Configuration**, ,,,,,,
   native or plugin to load,                        ✅, *hypo71*, *lociloc*, *locext*, ✅, *locnll*, *stdloc*
   |scname| provides locator,                       ✅, ✅, ✅, ❌, ✅, ✅, ✅
   operates without external files,                 ✅, ❌, ❌, ❌, ✅, ❌, ✅
   operates without custom scripts,                 ✅, ✅, ✅, ❌, ✅, ✅, ✅
   **Others**, ,,,,,,
   remarks,                                         intended for ground-truth tests / single-station location / any travel-time interface, ,operational at EMSC and ISC (earlier version), any external locator can be called by a custom script, currently the fastest locator in |scname| and the only one available to :ref:`scautoloc`, considers model uncertainties, uses travel-times from any travel-time interface
   point of contact,                               :cite:t:`seiscomp-forum`, :cite:t:`seiscomp-forum`, `ibondar2014 @gmail.com <ibondar2014@gmail.com>`_, :cite:t:`seiscomp-forum`, :cite:t:`seiscomp-forum`, :cite:t:`seiscomp-forum`, :cite:t:`seiscomp-forum`

* [1]: requires initial or specific configuration
* [2]: requires correction file
* [3]: depends on selected locator
* [4]: depends on selected travel-time interface
