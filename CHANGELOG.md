# Change Log

All notable changes to SeisComP are documented here.

## 4.10.0

**IMPORTANT**: Please check if your are affected by the bug concerning the scmaster
               configuration (see below).

-   system
    -   Change Linux distribution detection which does not require the presence
        of `lsb_release` anymore. Instead it looks in `/etc/os-release` which is
        way more portable. Furthermore the RHEL based distribution directories
        have been renamed from `centos` to `rhel`.
    -   Count started/stopped modules correctly.
-   scolv
    -   Fix lat/lon order of modify origin dialog opened from zoomtrace of
        the picker.
-   scmaster
    -   Fix saving location of the generated configuration file with `seiscomp setup`.
        Due to a bug the file was generated in `~/.seiscomp/scmaster.cfg` whereas it
        should have been generated in `etc/scmaster.cfg`. As this is fixed now, please
        remove `~/.seiscomp/scmaster.cfg` if you were affected by the bug otherwise
        this old configuration will take precedence and new configurations will not
        have any effect. This bug has been introduced with version 4.9.0.

## 4.9.3

-   trunk
    -   Fix default messaging URL from `localhost/productive` to
        `localhost/production`.

## 4.9.2

-   scolv
    -   Fix magnitude tab header update if the represented magnitude updates.
        It prints the current station magnitude counts rather than "0/0".
-   scmaster
    -   Get rid of distutils in setup script
-   scqcv
    -   Allow unordered stream list
-   screloc
    -   Optionally keep track of the triggering origin ID of a relocation storing
        it as comment in the relocated origin.

## 4.9.1

-   scmaster
    -   Fix setup stage if a database port has been specified explicitly

## 4.9.0

-   Documentation
    -   Use a single BibTex file and a References section for most external
        references
-   Magnitudes
    -   Mwp: Fix correction for radiation pattern. The change systematically
        reduces Mwp by 0.28
-   scquery
    -   Add command-line option `--print-column-name` for printing column names
        as a header of the output
-   scolv
    -   Select locator type and profile from loaded origin if possible and if
        enabled with option `olv.locator.presetFromOrigin` (default: false)
-   scdbstrip
    -   Fix compatibility with latest PostgreSQL versions. Thanks to
        Luca Scarabello for the fix.
-   trunk
    -   Fix crash if a spatial map layer has no configured legend items but
        wants to show a legend

## 4.8.4

-   scautoloc
    -   Fix picklog configuration.

## 4.8.3

-   seiscomp shell
    -   Remove unimplemented "add" and "edit" commands
-   seiscomp setup
    -   In newer versions (at least >=13) of PostgreSQL, some of the commands
        that are run to initiate the seiscomp database need to be run as the
        database owner. Thanks to Morten Sickel for fixing it.
-   Documentation
    -   Fix Datamodel diagrams
    -   Add object cross references
-   trunk
    -   Fix XML encoding issue with text in CDATA, e.g. `Pick.phaseHint`. This
        only affects strings which contain special XML characters such as
        ampersand.
    -   Report correct module name with messaging for Python applications.
        Previous versions only reported `python` or `python3.8`.
-   scsohlog
    -   Port to Python3
-   sh2proc
    -   Port to Python3

## 4.8.2

-   scart
    -   Fix date in error output

## 4.8.1

-   fdsnws
    -   Fix return of empty event publicID in event service when a
        PostgreSQL database is being used

## 4.8.0

```SC_API_VERSION 14.4.0```

-   scolv
    -   Change text "(Un)fix" buttons to be more explicit
        -   Unfix -> Unfix type
        -   Fix -> Fix FM
        -   Fix Mw -> Fix Mw type
    -   Use configured magnitude digits to display Mw magnitude value
    -   Only enable creation of artificial origin in zoom trace if picking
        is disabled
    -   Fix committing of manual amplitudes in the amplitude picker
-   scmag
    -   Fix bug that caused multiple occurrences of magnitudes of the same
        type when a new set of manually computed amplitudes has been received
-   trunk
    -   Fix segmentation fault when reading malformed GeoJSON features
-   scorgls
    -   Add option to filter for author (thanks to Fred Massin / ETHZ)
-   sdmssort
-   Fix error when two or more files are passed
-   seedlink
    -   Fix typo in setup script
    -   Add misc plugin

## 4.7.3

-   trunk
    -   Fix MYSQL database setup script to create
        ro and rw user accounts correctly

## 4.7.2

-   trunk
    -   Update changelog
    -   Fix `seiscomp setup trunk` with respect to database initialization
-   scart
    -   Do not require archive directory when writing records to stdout
-   iLoc
    -   Allow configuration of local models
    -   Add comprehensive documentation on iLoc and integration / configuration
        in SeisComP

## 4.7.1

-   trunk
    -   Fix test compilation for some distributions
    -   Update changelog

## 4.7.0

```SC_API_VERSION 14.3.0```

-   Documentation
    -   Update SDK Python examples
-   seiscomp
    -   Add --wait parameter to set the timeout when acquiring
        the seiscomp lock
    -   Add dialog for removing obsolete configuration after
        removing alias modules
    -   Add support for additional host environment which is sourced from
        `$SEISCOMP_ROOT/etc/env/$(hostname)` if present
-   trunk
    -   Add HTTP proxy support for FDSNWS recordstream. `http_proxy`,
        `https_proxy` and `no_proxy` environment are being read and
        evaluated. Only proxy servers available with http are supported
        currently.
    -   Add new geo feature directory  `@DATADIR@/spatial/vector` or
        `@CONFIGDIR@/spatial/vector`. Load  BNA files from new geo
        feature directory. The old BNA directories are still
        supported but cause a warning which is logged.
    -   Add support for GeoJSON files (*.geojson) in the new geo
        feature directory.
    -   Add data scheme version information to output when starting
        a module with the option `-V`
    -   Add MEDIAN() filter
-   scolv
    -   Fix display of tooltips in origin map and magnitude map
    -   Fix loading configured streams from either scolv or global
        bindings instead of the first bindings found
    -   Allow modifying origins and creating artificial origins on zoom trace
        in picker window
-   scquery
    -   Add `--print-header` option for generating information on the query as a
        header of the output
    -   Add examples for PostgreSQL
-   GUI
    -   Add azimuthal gap column to event list which is initially hidden. To
        activate it, add `AzGap"` to `eventlist.visibleColumns`
    -   Add units to columns of tables: Events, Events, Magnitudes
    -   Remove number of origins column in event list if origins should not be
        listed
    -   Correct issue with magnitude view map which does not show symbols
        for stations which have a magnitude but no arrival
-   scesv
    -   Add azimuthal gap to hypocenter panel
-   scqcv
    -   Make many configuration parameters available in scconfig and documentation
-   scautoloc
    -   Disable pick logging by default to optimize disk space consumption.
        Can be enabled by new option `autoloc.pickLogEnable`.
    -   Added documentation of parameters
    -   Send a journal message when setting the origin evaluation status
    -   Add IM network to default station.conf
-   iLoc
    -   Update iLoc code to version 3.3
-   scdispatch
    -   Add command-line option `-e` as a wrapper for removing the EVENT group from
        routing table

## 4.6.1

-   scolv
    -   Add number of used / unused station magnitudes to Magnitudes tab (missing
        from 4.6.0)

## 4.6.0

-   Dependencies
    -   Change Debian 10 dependencies to Python3 and Qt5
-   scevent
    -   Use application name for processing-info log
    -   Add new journal action EvRefresh: Select the preferred origin, the preferred
        magnitude, update the region, call processors loaded with plugins.
-   scmssort
    -   Add new `list` option to filter miniSEED data by stream lists
    -   Add some statistics to stderr output in verbosity mode
-   scart
    -   Do not crash when requesting data for non-existing networks from SDS archive
    -   Add error output when attempting retrieve non-existing data from SDS archive
-   GUI
    -   Add number of origins per event to event list
    -   Add copy cell operation to context menu to all tables in event editor
-   scmv
    -   Report erroneous configuration of `stations.groundMotionFilter` and stop
        smoothly
-   scolv
    -   Add number of used / unused station magnitudes to Magnitudes tab
-   scheli
    -   Allow scaling of traces per maximum row amplitude
-   trunk
    -   Add support for permanent redirects to fdsnws RecordStream
    -   Fix MiniSEED reader for records without blockette 1000 and
        for records with blockette 1000 at an offset beyond the
        first 128 bytes
-   seiscomp
    -   Create aliases even if some links already exist
    -   List remaining configuration files after removing aliases
    -   Support requesting status of enabled and of started modules
    -   Support requesting list of started modules
-   scconfig
    -   Add search for parameters in bindings panel: Ctrl + f
-   sccnv
    -   Include moment tensor derived origins into output document for
        QuakeML 1.2
-   scxmldump
    -   Add -J, --journal option allowing to export the journal

## 4.5.0

```SC_API_VERSION 14.2.0```

-   Magnitudes
    -   mb and mB: add configurable distance ranges in global bindings
    -   ML, MLv, MLh, md, MLr, Ms_20: unify the configuration in the magnitudes and
        amplitudes sections of global bindings. The number of magnitude types has
        grown over time and each magnitude had its own flavor of configuration.
        This made configurations increasingly difficult. By this change the
        configuration becomes homogeneous and easier. The corresponding parameters
        are deprecated and must be replaced by new ones either pre-pending
        `magnitudes.` or `amplitudes.` to the respective parameter.
        Warnings will be written to module logs if deprecated values are found.
    -   deprecated bindings parameter values -> new values:

        ```
        MLh.maxavg            -> amplitudes.MLh.params
        MLh.ClippingThreshold -> amplitudes.MLh.ClippingThreshold
        MLh.params            -> magnitudes.MLh.params

        md.maxavg             -> magnitudes.md.seismo
        md.taper              -> magnitudes.md.taper
        md.signal_length      -> magnitudes.md.signal_length
        md.butterworth        -> magnitudes.md.butterworth
        md.depthmax           -> magnitudes.md.depthmax
        md.deltamax           -> magnitudes.md.deltamax
        md.snrmin             -> magnitudes.md.snrmin
        md.mdmax              -> magnitudes.md.mdmax
        md.fma                -> magnitudes.md.fma
        md.fmb                -> magnitudes.md.fmb
        md.fmd                -> magnitudes.md.fmd
        md.fmf                -> magnitudes.md.fmf
        md.fmz                -> magnitudes.md.fmz
        md.linearcorrection   -> magnitudes.md.linearcorrection
        md.offset             -> magnitudes.md.offset
        md.stacor             -> magnitudes.md.stacor

        MLr.maxavg            ->  magnitudes.MLr.params

        Ms_20.lowerPeriod     ->  magnitudes.Ms_20.lowerPeriod
        Ms_20.upperPeriod     ->  magnitudes.Ms_20.upperPeriod
        Ms_20.minDist         ->  magnitudes.Ms_20.minDist
        Ms_20.maxDist         ->  magnitudes.Ms_20.maxDist
        Ms_20.maxDepth        ->  magnitudes.Ms_20.maxDepth

        MLv.logA0             ->  magnitudes.MLv.logA0
        MLv.maxDistanceKm     ->  magnitudes.MLv.maxDistanceKm

        ML.logA0              ->  magnitudes.ML.logA0
        ML.maxDistanceKm      ->  magnitudes.ML.maxDistanceKm
        ```

-   scinv
    -   Allow a configurable distance between station and location coordinate
        when calling scinv check
    -   Test existence of stations, locations and streams when calling scinv check
-   trunk
    -   Add CAPS RecordStream implementation with service "caps" and "capss".
        The later establishes an SSL connection.
    -   Fix crash of distance computation if distance is close to zero
    -   Add RecordStream to retrieve data from a CAPS server, e.g. `caps://localhost`
    -   Set Ms_20 minimum distance to 20 degree
    -   Fix SQLite3 database schema
-   GUI
    -   Make eventedit columns of origin and fm tables configurable

        ```
        eventedit.origin.visibleColumns = Phases, Lat, Lon, Depth, DType, RMS,\
                                          Stat, Method, Agency, Author, Region
        eventedit.fm.visibleColumns = Depth, M, Count, Misfit, STDR, Azi.\
                                      Gap(°), Stat, DC(%), CLVD(%), ISO(%),\
                                      S1(°), D1(°), R1(°), S2(°), D2(°), R2(°),\
                                      Agency, Author
        ```

-   scbulletin
    -   Allow to flag depth as fixed (thanks to Anthony Carapetis)

## 4.4.0

-   hypo71
    -   Redirect locator output to SeisComP info output instead of stdout
-   seiscomp
    -   Fix inventory, trunk and access setup file to get the
        configured local scmaster connection correctly especially
        with encrypted connections.
-   GUI
    -   Add config support for color names according to
        <https://www.w3.org/TR/SVG11/types.html#ColorKeywords>, e.g.
       `scheme.colors.records.foreground = blue`
-   scrttv
    -   Add `streams.sort.mode` to set up the initial sort mode
    -   Add grouping of streams for sorting and coloring

## 4.3.0

-   scheli
    -   Add configuration parameters to description XML allowing configuration in
        scconfig
-   scrttv
    -   Adjust default filter to filter below the Nyquist frequency of most BH?
        streams
    -   Add default values for streams configurations
-   scautoloc
    -   Adjust configuration and parameters. The legacy parameters can still be used
        but an error message will be printed:
        -   Added parameters to description:

            ```
            buffer.originKeep
            autoloc.useManualPicks
            autoloc.adoptManualDepth
            autoloc.tryDefaultDepth
            autoloc.stationLocations
            ```

        -   Renamed parameters (old -> new):

            ```
            autoloc.maxAge          -> buffer.pickKeep
            autoloc.cleanupInterval -> buffer.cleanupInterval
            autoloc.locator.profile -> locator.profile
            ```

        -   Removed parameters from description:

            ```
            autoloc.wakeupInterval
            ```

-   slarchive
    -   Allow creation of aliases
-   scmag
    -   Add medianTrimmedMean average method
    -   Remove internally cached objects if an objects has been removed
      via messaging
-   scolv
    -   Add median trimmed mean to magnitude average method
    -   Sort event types alphabetically and status by priority
-   scart
    -   Fix loading of plugins

## 4.2.1

-   Documentation
    -   Update installation and database procedures
-   Event list in GUIs
    -   Add RMS column by default
-   scolv
    -   Relabel strike/dip/rake columns in focal mechanism table
        and resize content after loading
-   scolv
    -   Relabel strike/dip/rake columns in focal mechanism table
        and resize content after loading
-   evrc plugin
    -   Fix reading origin which have no depth
    -   Fix setting no event type for region `world`

## 4.2.0

-   scalert
    -   Add option to listen to picks
    -   Fix configuration of agency filter
-   scevent
    -   Sort configuration of event association parameters by topic
-   scolv
    -   Expose picker phase profiles to scconfig
    -   Adjust description of uncertainty profiles
-   fdsnxml2inv
    -   Fix conversion of polynomial responses with respect to
        `approximationType`.
-   scolv
    -   Reorder FM tab columns and allow switching visibility state

## 4.1.2

-   Processing
    -   Fix crashing of processing modules such as scautopick if filter
        parameters are out of range

## 4.1.1

-   scmaster
    -   Fix reading the default configuration file in update-config
-   ew2sc
    -   Correct module name in description. E.g. scconfig has still displayed it
        as `ew2sc3`.
-   GUI
    -   Add nodal planes and some more quality parameters to event edit focal
        mechanism table
    -   Fix setting the depth type in the origin locator panel

## 4.1.0

```SC_API_VERSION 14.1.0```

-   scmaster
    -   Add IMPORT_GROUP to default group set
-   screloc
    -   Add option to allow processing of origins with mode MANUAL in daemon mode
    -   When using `--ep` playbacks with origins defined by -O, then the processing
        is limited to the defined origins.
-   scevent
    -   Update event agencyID and author on event update if it has
        changed. This is important if scevent has been reconfigured
        with a different agencyID or author.
-   trunk
    -   The application class resets its locale to the initial
        state at exit. Not doing so could have caused encoding
        errors with init scripts
    -   Add fixed hypocenter locator
    -   Add external locator plugin (locext)
    -   Fix combined recordstream for slinkMax|rtMax|1stMax units `s` and `h`
    -   Fix LOCSAT travel time computation for phases which do not provide
        a table file or with zero depth layers. Sometimes LOCSAT produced
        fake travel times for non existing phases after switching tables.
-   scevtstreams
    -   Add `--fdsnws` command line option to export list of
        channels in FDSNWS dataselect POST format
-   GUI
    -   Add option to define symbol images for layer points defined in
        either BNA or FEP
-   seedlink
    -   Fix parsing of global `backfill_buffer` variable. Up to this
        fix the variable was always considered out of bounds and apart from using
        backfill buffer settings in the bindings the global value had no effect.
-   scolv
    -   Fixed several segmentation faults in combination with offline
        mode
    -   Add origin location method column to event origin table
    -   Add shortcuts (Ctrl+pgdown, Ctrl+pgup) to select the previous and
        next event of the event list from within the locator view

## 4.0.4

-   trunk
    -   Fix ML/MLv default magnitude calibration
-   GUI
    -   Quit application if an error occurred during initialization
        and if the setup dialog is cancelled or closed by hitting
        the X icon
    -   Also accept `TP` for parameter `eventlist.visibleColumns`
        but print a warning
-   scmm
    -   Fix client disconnect handling
-   scimport
    -   Log error message if parameter `msggroups` is not defined

## 4.0.3

-   slmod
    -   Fix Python2 support
-   scolv
    -   Add origin depth type to event list and origins list
-   base
    -   Fix bug with decimation record stream which caused that
        just a subset of input data was forwarded to the client
    -   Populate SNR values of Ms(BB) and ML amplitudes
-   GUI
    -   Replace splash screen with latest logo and render text flat
    -   Rename item `TP` to `MType` of parameter
        `eventlist.visibleColumns`

## 4.0.2

-   scautoloc
    -   Correct station.conf
-   trunk
    -   Add ML/MLv magnitude calibration at 100 km
-   dlsv2inv
    -   Fix crash for debug builds if a token is empty,
        e.g. empty end time

## 4.0.1

-   LOCSAT
    -   Allow to override the tables directory with the environment
        variable `SEISCOMP_LOCSAT_TABLE_DIR`
-   scconfig
    -   Add application icon
-   scolv
    -   Fix bug when a magnitude is recalculated with a subset of
        station magnitudes
-   fdsnws
    -   Parse query filter parameters strictly. Thanks to Daniel
        Armbruster for providing the patch.

## 4.0.0

```SC_API_VERSION 14.0.0```

This is the initial release of SeisComP under a new license and with a new
versioning scheme. Instead of using a release name and a time based version
tag semantic versioning is now being used with a sequence of three digits:
Major.Minor.Patch. The following rules apply for assigning a new digit:

-   Major: Libraries introduce binary incompatible changes or there are very
    significant application changes which justify a major version bump.
-   Minor: Libraries add new functionality and methods but binary
    compatibility within the same major release is still maintained
    with application built against a lower minor version. Significant
    application changes can also justify a minor version bump.
-   Patch: No changes in functionality but error corrections of existing
    codes.

Breaking changes:

-   Spread has been replaced as messaging system with our own implementation
    of a messaging broker. That means that connections between SeisComP3 and
    SeisComP >= 4.0.0 are not possible until a driver has been developed
    which implements Spread in SeisComP or scmp in SeisComP3.
-   Qt5 and Python3 are now supported preferred.
-   The SeisComP Python packages have been renamed to `seiscomp` but a
    compatibility layer for `seiscomp3` has been added.
-   Arclink is no longer supported and has been removed completely.
-   arclinkproxy has been removed as well and is superseded by scwfas.
-   The installation directory is now `seiscomp` and not `seiscomp3`.
-   The user configuration directory is now `.seiscomp` and not `.seiscomp3`.
-   C++ compilation requires a compiler that supports at least the C++11
    standard.
