# Change Log

All notable changes to SeisComP are documented here.

## x.y.z

* ew2sc

  * Correct module name in description. E.g. scconfig has still displayed it
    as `ew2sc3`.

## 4.1.0

```SC_API_VERSION 14.1.0```

* scmaster

  * Add IMPORT_GROUP to default group set

* screloc

  * Add option to allow processing of origins with mode MANUAL in daemon mode
  * When using --ep playbacks with origins defined by -O, then the processing
    is limited to the defined origins.

* scevent

  * Update event agencyID and author on event update if it has
    changed. This is important if scevent has been reconfigured
    with a different agencyID or author.

* trunk

  * The application class resets its locale to the initial
    state at exit. Not doing so could have caused encoding
    errors with init scripts
  * Add fixed hypocenter locator
  * Add external locator plugin (locext)
  * Fix combined recordstream for slinkMax|rtMax|1stMax units `s` and `h`
  * Fix LOCSAT travel time computation for phases which do not provide
    a table file or with zero depth layers. Sometimes LOCSAT produced
    fake travel times for non existing phases after switching tables.

* scevtstreams

  * Add `--fdsnws` command line option to export list of
    channels in FDSNWS dataselect POST format

* gui

  * Add option to define symbol images for layer points defined in
    either BNA or FEP

* seedlink

  * Fix parsing of global `backfill_buffer` variable. Up to this
    fix the variable was always considered out of bounds and apart from using
    backfill buffer settings in the bindings the global value had no effect.

* scolv

  * Fixed several segmentation faults in combination with offline
    mode
  * Add origin location method column to event origin table
  * Add shortcuts (ctrl+pgdown, ctrl+pgup) to select the previous and
    next event of the event list from within the locator view

## 4.0.4

* trunk

  * Fix ML/MLv default magnitude calibration

* gui

  * Quit application if an error occurred during initialization
    and if the setup dialog is cancelled or closed by hitting
    the X icon
  * Also accept `TP` for parameter `eventlist.visibleColumns`
    but print a warning

* scmm

  * Fix client disconnect handling

* scimport

  * Log error message if parameter `msggroups` is not defined

## 4.0.3

* slmod

  * Fix Python2 support

* scolv

  * Add origin depth type to event list and origins list

* base

  * Fix bug with decimation record stream which caused that
    just a subset of input data was forwarded to the client
  * Populate SNR values of Ms(BB) and ML amplitudes

* gui

  * Replace splash screen with latest logo and render text flat
  * Rename item `TP` to `MType` of parameter
    `eventlist.visibleColumns`

## 4.0.2

* autoloc

  * Correct station.conf

* trunk

  * Add ML/MLv magnitude calibration at 100km

* dlsv2inv

  * Fix crash for debug builds if a token is empty,
    e.g. empty end time

## 4.0.1

* LOCSAT

  * Allow to override the tables directory with the environment
    variable `SEISCOMP_LOCSAT_TABLE_DIR`

* scconfig

  * Add application icon

* scolv

  * Fix bug when a magnitude is recalculated with a subset of
    station magnitudes

* fdsnws

  * Parse query filter parameters strictly. Thanks to Daniel
    Armbruster for providing the patch.


## 4.0.0

```SC_API_VERSION 14.0.0```

This is the initial release of SeisComP under a new license and with a new
versioning scheme. Instead of using a release name and a time based version
tag semantic versioning is now being used with a sequence of three digits:
Major.Minor.Patch. The following rules apply for assigning a new digit:

* Major: Libraries introduce binary incompatible changes or there are very
  significant application changes which justify a major version bump.
* Minor: Libraries add new functionality and methods but binary
  compatibility within the same major release is still maintained
  with application built against a lower minor version. Significant
  application changes can also justify a minor version bump.
* Patch: No changes in functionality but error corrections of existing
  codes.

Breaking changes:

* Spread has been replaced as messaging system with our own implementation
  of a messaging broker. That means that connections between SeisComP3 and
  SeisComP >= 4.0.0 are not possible until a driver has been developed
  which implements Spread in SeisComP or scmp in SeisComP3.
* Qt5 and Python3 are now supported preferred.
* The SeisComP Python packages have been renamed to `seiscomp` but a
  compatibility layer for `seiscomp3` has been added.
* Arclink is no longer supported and has been removed completely.
* arclinkproxy has been removed as well and is superseded by scwfas.
* The installation directory is now `seiscomp` and not `seiscomp3`.
* The user configuration directory is now `.seiscomp` and not `.seiscomp3`.
* C++ compilation requires a compiler that supports at least the C++11
  standard.
