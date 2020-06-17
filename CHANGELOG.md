# 4.0.1

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


# 4.0.0

```SC_API_VERSION 14.0.0```

This is the initial release of SeisComP under a new license and with a new
versioning scheme. Instead of using a release name and a time based version
tag semantic versioning is now being used with a sequence of three digits:
Major.Minor.Patch. The following rules apply for assiging a new digit:

* Major: Libraries introduce binary incompatible changes or there are very
         significant application changes which justify a major version
         bump.
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

