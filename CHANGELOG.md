# Change Log

All notable changes to SeisComP are documented here.

## 6.3.1

-   trunk
    -   Fix MYSQL reconnect when server went away.

## 6.3.0

-   seedlink
    -   Add OptoDAS plugin.
-   trunk
    -   Add new filter BPENV() for approximating envelopes.
    -   Add new filters RUD() and RND() for generating random signals with
        uniform and normal distribution, respectively. When apply to data, the
        data samples are replaced by the random signal. For adding noise use the
        '+' operator. Example: self+RUD(-10,10)>>BW(3,0.7,2).
    -   New time grammar operator, OT, for configuring amplitude-time windows.
    -   Handle negative channel gain: amplitude processors always return
        positive amplitudes.
-   scolv
    -   Add time and publicID to pick tool tip in picker
    -   Handle single component positive dip. Traces will be flipped when transforming
        int ZNE.
-   GUI
    -   Handle negative gains. Traces will be flipped if values should be shown
        in gain units.
-   scdumpcfg
    -   The option `-P` supports lists, allowing to request the values for
        multiple parameters instead of only one.
-   scevtls
    -   Include created events in output without modified date using `--modified-after`.
-   scinv
    -   Report missing values for channel dip and azimuth,
    -   Report when both channel dip and gain are negative as this may be
        accomplished by positive values.
-   scevent
    -   The evrc (RegionCheck) plugin ignores but reports missing polygons
        instead of dropping the region check entirely.
-   iLoc
    -   Update iLoc code to version 4.2
-   doc
    -   Add more details to amplitude time window configuration grammar
    -   Add BPENV, RND and RUD filter
    -   More details on magnitude average methods
-   system
    -   Add libqt5printsupport5 dependency to Debian bases distributions.

## 6.2.1

-   scalert
    -   Fix crash on exit
    -   Fix handling of `agencyIDs`: an empty string in the
        configuration file will allow any agencyID.
-   trunk
    -   Fix ML/MLc amplitude time window computation to raise an error
        if one component fails.
-   GUI
    -   Fix map legend generation from feature directories.
-   scolv
    -   Fix crash if an MT solution does not contain a derived origin.
-   hypo71
    -   Fix writing the correct number of stations and phases to new origins.

## 6.2.0

-   trunk
    -   Fix magnitude aliases for ML's in combination with
        different amplitude types. E.g. `MLderived:MLc:MLv`
        should work now.
    -   3C component detection by checking mutual perpendicular
        sensor orientations increased the tolerance from 1 degree
        to 5 degrees.
-   scconfig
    -   Allow checking individual inventory files in Inventory panel.
    -   Fix white space rendering in tooltips.
-   scolv
    -   Fix crash in amplitude review window under CentOS7
        caused by the measure type preselection introduced
        in 6.1.2.
-   scrttv
    -   Disable "Show picks/arrivals" actions if `showPicks`
        is set to `false`.
-   scardac
    -   Fix segfault triggered by stream filter
    -   Use value of `0` in `maxSegment` parameter to disable segment limits
-   scinv
    -   Fix reporting stream groups with other than 1 or 3 channels.
-   fdsnws
    -   Output full precision in event text format
    -   Fix exception in availablity access test
    -   Fix authorization error
    -   Add configuration option `inventoryCoordinatePrecision` allowing
        to obfuscate inventory geo coordinates

## 6.1.2

-   trunk
    -   Populate SNR value of ML and MLc amplitudes.
    -   Fix reading amplitude regionalization regions,
        use `magnitudes.[type].regionFile` instead of
        `magnitudes.[type].regions` as in v4.
-   scolv
    -   Preselect measure type and combiner dropdown based on
        station bindings.
-   scesv
    -   Fix regression which prevented showing the current
        magnitudes when `showLastAutomaticSolution = true`.

## 6.1.1

-   scolv
    -   Fix station count update of Mw magnitude if a magnitudes
        has been recalculated in the magnitude view. Furthermore
        the Mw tab header updates correctly and shows the number
        of stations.

## 6.1.0

```SC_API_VERSION 16.1.0```

-   ql2sc
    -   Add configurable event synchronization delay parameter to avoid
        race conditions in cross connected setups.
-   scautoloc
    -   Consider configuration of LOCSAT locator interface, supporting
        deactivation of slowness, backazimuth parameters which may be obtained
        during phase picking.
-   seedlink
    -   Fix crash in chain plugin if mseed records with
        invalid header data are transmitted.
    -   Fix network code mapping in `sock_plugin`.
    -   Fix fifo path resolve in `mseedfifo_plugin`.
-   scesv
    -   Fix crash in combination with latest automatic
        origin display.
-   scdispatch
    -   Log if an object already exists in database so that
        a user can understand why nothing was dispatched.
    -   Remove all event objects from the list of objects when applying
        `--no-events` instead of removing the routing.
-   scardac
    -   Add `--nslc` option allowing to skip initial archive scan for
        available waveform stream IDs.
-   scinv
    -   Add test for stream orthogonality to the check command:
        -   The test is limited to streams with sensor type code G, H, L or N
            (second letter of channel code).
        -   Any 3-component stream group of the same epoch stream code being not
            orthogonal is reported. Deviations of up to 1 degree are tolerated.
            The test is diagnostic since data processing made on horizontal or 3
            components, e.g., for picking S phases or measuring ML amplitudes
            will rely on orthogonality and will deny any streams groups
            violating orthogonality.
        -   If 3-component streams exist for a sensor location, any epoch
            having 2 or more than 3 components for the same sensor location will
            be reported.
-   trunk
    -   Prevent RMHP() from crashing when time span is below sample interval.
    -   Magnitude regionalization for profile "world" can work without
        specifying a region file.
    -   Magnitude region check also includes minimum and maximum depth,
        transforming the 2D region test into a 3D region test.
    -   Expose parameter `amplitudes.iaspei` in global module configuration of
        scconfig.
-   magnitudes
    -   Add depth check to regionalization.
    -   Update documentation of concepts and tutorial.
    -   Update MLc documentation.
    -   MLv, ML, MLc: Test regionalized `logA0` parameters for old-style values.
-   seiscomp
    -   Remove support for Ubuntu 18.04 with `install-deps`.
    -   Switch `install-deps` to Qt5 with RHEL7.
    -   Resolve fifo path in `mseedfifo` plugin configuration to support
        `@ROOTDIR@` and other SeisComP directories.

## 6.0.5

-   seedlink
    -   Revert previous fix as it fixes one configuration but breaks
        another. Future versions will address this issue.
    -   Fix mseedfifo plugin setup that it can be used as regular plugin.

## 6.0.4

-   seiscomp
    -   Fix an issue with special characters in db password, etc.
-   scconfig
    -   Set red background also for checkboxes if the parameter
        is overridden.
-   GUI
    -   Fix spectrogram rendering with time normalization.
-   trunk
    -   Fix internal timer exceptions in combination with OSX.
    -   Remove duplicate CLI parameter `--shutdown-master-username`.
-   seedlink
    -   Add more channels and increase sample rate to 1Hz for vaisala
        protocol.
    -   Fix plugin update-config if global parameters are modified,
        e.g. mseeedfifo plugin.

## 6.0.3

-   GUI
    -   Fix spectrogram update rendering w.r.t. time
        normalization.
    -   Fix zoom record time range display in amplitude view.
        When a new time range has been selected, e.g. via
        the time scale, then not the full time range has been
        set but only < 100% depending on the window size and
        screen resolution.

## 6.0.2

-   trunk
    -   Remove logging of database connection to not expose user
        accounts in log files.
-   scmaster
    -   Remove logging of of database connection in dbstore plugin
        to not expose user accounts in log files.

## 6.0.1

-   scmaster
    -   Fix database migration detection

## 6.0.0

```SC_API_VERSION 16.0.0```

With this version we drop Qt 4 support for all GUI applications.

The database schema receives a small update and will increase the schema version
to 0.13. In particular some new event types have been introduced:

-   volcano tectonic
-   volcanic long period
-   volcanic very long period
-   volcanic hybrid
-   volcanic rockfall
-   volcanic tremor
-   pyroclastic flow
-   lahar

SeisComP3 API support is deprecated and will be removed in the next
major version of SeisComP. This affects C++ includes like

```c++
#include <seiscomp3/core/datetime.h>
```

and Python imports like

```python
import seiscomp3.Core
```

They must be replaced with their SeisComP counterparts:

```c++
#include <seiscomp/core/datetime.h>
```

and

```python
import seiscomp.core
```

Changes:

-   trunk
    -   Configuration schema files (`@SYSTEMCONFIGDIR@/descriptions/[module].xml`)
        support extending available structures with plugins including selective
        name matching:

        ```xml
        <extend-struct type="Amplitude">
            <parameter name="param1" type="string"/>
        </extent-struct>
        ```

        or with matching structure names (here ML* including regular expressions):

        ```xml
        <extend-struct type="Amplitude" match-name="ML.*">
            <parameter name="param1" type="string"/>
        </extent-struct>
        ```

    -   Artificial origins: Allow pasting of hypocenter coordinates with high
        precision.
    -   Changed KM_OF_DEGREE constant according to WGS84 mean radius definition.
    -   Changed default values of Wood-Anderson instrument filter to
        recommendations by IASPEI magnitude group, 2011 and Uhrhammer et al., 1990.
        The change systematically reduces magnitudes by 0.13 when making
        use of amplitudes measured on waveforms corrected for Wood-Anderson
        seismometers with default.
    -   Remove `MYSQL_OPT_RECONNECT` option from MYSQL database driver to get
        rid of the deprecation warning by newer MYSQL client library versions.
        The automatic reconnect has been added to the driver code instead.
    -   Update `cities.xml`.
-   amplitudes
    -   Compute ML peak-to-trough and mb amplitudes according to IASPEI
        recommendations if configured with `amplitudes.iaspei = true`.
    -   Allow configuration of time windows based on time grammar.
-   magnitudes
    -   Simplify configuration of magnitude regionalization by global
        module configuration in scconfig.
    -   Allow creating magnitude aliases by configuration of `magnitudes.aliases`
        in global module configuration and magnitude type profiles in global
        bindings.
    -   Add a Magnitudes section to the documentation of concepts.
-   documentation
    -   Add subsection on locators to Concepts section.
    -   Add a tutorial on regionalization of magnitudes and aliases.
    -   Add section on time grammar for configuring time windows, e.g. for
        measuring amplitudes for magnitudes.
-   scesv
    -   Show event type information.
-   scquery
    -   Add option `--print-query-only`.
-   scdumpcfg
    -   Fix reading bindings from database without requiring a messaging system.
-   scevtstreams
    -   Add option `--nslc` for filtering the read phase picks by stream IDs.
-   Hypo71
    -   Add file rotator for log file defined by global parameter
        `hypo71.logFile`.
    -   Use `hypo71.logFile` consistently with @LOGDIR@/HYPO71.LOG.
-   seiscomp tool
    -   Add command `print variables` for printing internal SeisComP variables.
    -   Add documentation in section Utilities.
-   scolv
    -   Add restoring default amplitude-time windows in amplitude picker
        (Shift + W).
    -   Add resetting the length of the zoom window to the trace overview in
        amplitude picker.
    -   Preserve arrival definition flags (backazimuth, h-slowness) when committing
        from picker if a pick is not enabled.
-   scrttv
    -   Add spectrogram view
-   scmapcut
    -   Plot multiple events if given.
-   scart
    -   Fix reading miniSEED from stdin without -I as default.
-   scconfig
    -   Fix rendering of parameter tooltips and evaluation info boxes. This bug
        prevented special strings, e.g. "A < 12", to be displayed correctly.
-   scdbstrip
    -   Add option `--time-window`.
    -   Do not delete anything by default.
    -   Add daterange option `--daterange`.
-   scdispatch
    -   Add `--create-notifier` option.
-   GUI
    -   Fix removal of map legend
    -   Reset legends if geo feature layer is reloaded
    -   Add additional legend alignment options
    -   Support rendering of geo feature name next to symbols
    -   Drop Qt4 support
-   invextr
    -   Add option `--nslc`.
-   scevtls
    -   Add option `--input` loading XML and printing IDs of contained events.
-   scorgls
    -   Add option `--input` loading XML and printing IDs of contained origins.
-   scardac
    -   Rescan only those chunks modified since last scan.
    -   Add `--deep-scan` paramater to force rescan.
    -   Add `--to` and `--from` parameter to limit scan by record time.
    -   Add `--modified-since` and `--modified-until` parameter to rescan
        chunks modified in particular time window.
    -   Add options `--include` and `--exclude` for filtering waveforms by ID.
    -   Modernize code.
    -   Add test cases.
    -   Increase collector API version to 2.
-   screpick
    -   Add as new module.

## 5.5.15

-   seedlink
    -   Fix crash in chain plugin if mseed records with
        invalid header data are transmitted.
    -   Fix network code mapping in `sock_plugin`.
    -   Fix fifo path resolve in `mseedfifo_plugin`.

## 5.5.14

-   seedlink
    -   Revert previous fix as it fixes one configuration but breaks
        another.
    -   Fix mseedfifo plugin setup that it can be used as regular plugin.

## 5.5.13

-   seedlink
    -   Fix plugin update-config if global parameters are modified,
        e.g. mseeedfifo plugin. 

## 5.5.12

-   seiscomp
    -   Fix an issue with special characters in db password, etc.
-   trunk
    -   Remove duplicate CLI parameter `--shutdown-master-username`.

## 5.5.11

-   scmapcut
    -   Fix crash in combination with `-h`.

## 5.5.10

-   scrttv
    -   Fix associator locator solution update with Qt4 if either locator profile
        or depth has changed. This mainly affects RHEL7 builds. All other builds
        which are using Qt4 are affected as well.

## 5.5.9

-   scconfig
    -   Fix evaluated parameter value rendering if it contains characters
        like < or >.
-   scolv
    -   Fix setting the preferred magnitude from the magnitude view by selecting
        the magnitude tab and committing. Fix / release / fix did not work as
        expected with some database backends.

## 5.5.8

-   GUI
    -   Fix setting first enabled event in event list. This has caused application,
        e.g. scesv, to not update the current event if the type has changed to
        "not existing" or "other".
-   scolv
    -   Preserve arrival definition flags (backazimuth, h-slowness) when committing
        from picker if a pick is not enabled.

## 5.5.7

-   scolv
    -   Fix width of calculate amplitude window in combination with
        large recordstream URIs.
-   trunk
    -   Fix deadlock in concurrent recordstream which affected
        `balanced://` and `routing://`.

## 5.5.6

-   scbulletin
    -   Fix KML output which did not produce complete XML documents.

## 5.5.5

**IMPORTANT**: This fixes a regression of scamp introduced with version 5.5.0 which
               caused scamp to always compute new amplitudes for origin and their
               arrivals.

-   doc
    -   Update templates to build with latest Sphinx version. We tested against
        Sphinx 7.2.2 and required the following packages installed with pip:

        -   sphinx
        -   m2r2
        -   sphinxcontrib.bibtex

        The doctulils package must be installed in  version 0.20 or later in order
        to render the bib index correctly.
-   scart
    -   Run in import mode by default.
-   scamp
    -   Fix re-computation of amplitudes anytime a new origin is received. This restores
        the behaviour of version < 5.5.0.
-   scevtls
    -   Support date format %F, e.g. `scevtls --begin 2023-09-13`.
-   scmapcut
    -   Plot all events from a given XML and not just the first one unless filtered
        with `--event-id`.
    -   Add `--without-arrivals` to plot only the origin symbol without stations.
-   trunk
    -   Fix computation of stdloc residuals.
    -   Allow stdloc LeastSquares to locate even with less iterations.
    -   Fix regression in MLc magnitude to correctly compute the hypocentral
            distance taking the sensor location elevation into account and also
            supporting negative source depths. In versions < 5.5.3 the source
            depth was clipped to 0 and the sensor location elevation did not
            contribute. In version 5.5.3 and 5.5.4 all depths were considered
            but without the sensor location elevation.

## 5.5.4

-   scamp
    -   Fix bug which prevented passing the origin information to
        the amplitude computation.
-   MYSQL
    -   Fix deprecation warning of the libmysqlclient w.r.t. `MYSQL_OPT_RECONNECT`.
-   trunk
    -   Output full database schema version including patch version
    -   Fix logging memory leak when the application class is initialized multiple
        times, usually in code implementing tests.
    -   Minor documentation fixes for stdloc.
-   scrttv
    -   Fix mouse selection of mode drop down menu.

## 5.5.3

-   trunk
    -   Add more debug output to magnitudes ML, MLv and MLc.
    -   Fix crash if distance for MLv.logA0 is out of range.
    -   Fix reading of MLc magnitude correction factors of
        regionalization profiles.
    -   Fix messaging re-connection deadlock that causes applications
        to hang forever after the messaging connection has been
        re-established.
-   GUI
    -   Show surface wave onsets in amplitude view.
-   scmag
    -   Fix description of `minimumArrivalWeight` for scconfig.
-   scdumpcfg
    -   Fix loading of shadowed application plugins, e.g. scqc, which
        caused issues when loading application specific plugins.
-   bindings2cfg
    -   Fix help text.
    -   Add commandline option `--create-notifier`. The notifiers can be added
        to the database using scdb allowing to import bindings while bypassing
        the messaging system.

## 5.5.2

```SC_API_VERSION 15.6.0```

-   documentation
    -   Add subsection on locators to Concepts section.
    -   Add a concepts section on magnitudes.
-   trunk
    -   Fix concurrent recordstream termination when data still available.
    -   Fix invalid ResourceUri for QuakeML arrival export.
-   scolv
    -   Announced feature of auxiliary channels from version 5.5.0 has been
        added which was left out accidentally.
    -   Select previous and next event buttons now consider only visible events
        in the event list. This is now similar to switching to the event list
        and selecting the event previous or next to the current event.
-   screloc
    -   Be more informative at INFO log level (`--ep` option).

## 5.5.1

-   scxmldump
    -   Stop warning about empty amplitude ID in station magnitude.
-   scrttv
    -   Fix `--start-at-now` and disable time window load actions with `--rt`.
    -   Fix crash if removed picks are associated with incoming origins.

## 5.5.0

```SC_API_VERSION 15.5.0```

-   deps
    -   Add Debian 12 support
-   seedlink
    -   Fix bug of win plugin which caused log entries 'invalid time' and did
        not forward data.
    -   Update libq330 for the q330 plugin.
-   trunk
    -   Add ML(IDC) and mb(IDC) magnitude implementation (ported from SeisComP3).
    -   Fix deadlock in messaging reconnect (scmp + scmps).
    -   Limit alias names to 20 characters if the module provides bindings.
-   GUI
    -   Fix bad performance of reading events into the event list in combination
        with Qt4.
-   scautoloc
    -   Do not consider picks with evaluationMode = rejected. Can be overruled
        by `--allow-rejected-picks`.
-   scamp
    -   Add option `--picks` for processing picks in playbacks with `--ep` while
        ignoring origins.
-   scbulletin
    -   Fix output of event type used in fdsnws format.
    -   Add option `--kml` for output in KML format.
    -   Add option `-o` for direct output to file.
-   scart
    -   Do not require an output archive when executing with `--test`.
-   scolv
    -   Add notion of auxilliary channels (configurable). Auxilliary channels can
        be skipped while adding stations in range because a minimum or maximum
        distance has not been reached.
        ```
        picker.auxilliary.channels = AB.*.*.*
        picker.auxilliary.minimumDistance = 0 # Optional, default 0
        picker.auxilliary.maximumDistance = 1 # Optional, default 1000
        ```
    -   Read journal entries also from offline XML files
    -   Fix regression in 5.4 which prevents the picker from resetting the
        amplitude scaling of the zoom trace when scaling to visible amplitudes
        with, e.g. 's'.
-   scrttv
    -   Add command-line option `--channels` for selecting channels to load
    -   Fix restoring the default display when loading files or reloading a
        new time range. Only the initially configured buffer size (e.g. 30 minutes)
        was used.
-   scqcv
    -   Remove unused parameters from descriptions, hence scconfig.
    -   Allow sorting by stream ID.
    -   Rename menu "Options" to "Settings".

## 5.4.0

```SC_API_VERSION 15.4.0```

-   deps
    -   Add RHEL 9 support
-   scconfig
    -   Preserve escaped characters when writing the configuration
    -   Fix reading variables when using includes
-   trunk
    -   Fix crash of SDSArchive in combination with e.g. `routing` recordstream,
        thanks to Luca Scarabello (SED/ETHZ).
    -   Fix fdsnws:// recordstream which caused the connection to hang and to
        not terminate.
    -   Improve GeoJSON parsing:
        -   Fix GeoJSON Point and MultiPoint parsing,
        -   Fix parsing of rank,
        -   Support for GeometryCollection,
        -   Support empty geometry definitions according to standard.
    -   Compute dtdd/dtdh values in LOCSAT travel time table implementation (Luca
        Scarabello (SED/ETHZ))
    -   Revert resolving all path variables with configuration files introduced
        with version 5.3. It caused to much conflicts and inconsistencies that we
        have decided to revert the "feature".
    -   Simplify the configuration of the travel-time interface homogeneous:
        Deprecated global configuration parameter -> new parameter, dropped
        '.profile':
        ```
        ttt.homogeneous.profile.[profile].[parameters]  -> ttt.homogeneous.[profile].[parameters]
        ```
    -   Add stdloc locator plugin which implements a new locator called StdLoc.
        It has been contributed by Luca Scarabello / ETH. The algorithms 
        implemented in StdLoc are standard methods described in
        "Routine Data Processing in Earthquake Seismology" by Jens Havskov
        and Lars Ottemoller.

-   amplitudes
    -   Allow configuration of Wood-Anderson instrument parameters in amplitudes
        global section of module configuration.
        ```
        amplitudes.WoodAnderson.gain = ...
        amplitudes.WoodAnderson.T0 = ...
        amplitudes.WoodAnderson.h = ...
        ```
-   GUI
    -   Fix tooltip display of MapWidget under some circumstances
    -   Add View and Settings menus consistently to all GUIs.
-   scolv
    -   Show Pick.onset attribute (impulsive, emergent, ...) in the arrival table
        and in picker window. Allow editing/setting it in the picker.
    -   Preserve used attribute states when committing from picker
    -   Load associated picks of temporary origins
    -   Support small values in diagram widget
    -   Add residual to pick tooltip of arrival plot
    -   Add option to define origin comment profiles to populate
        arbitrary comments when committing an origin.
    -   Add option to define magnitude comment profiles to populate
        arbitrary comments when reviewing a network magnitude
    -   Make `olv.arrivalPlot.showUncertainties` configurable in scconfig
    -   Change picker behaviour when hovering another component when pick mode
        is active: only the component of the zoom trace is changed and not the
        overall component. The old behaviour can be restored with
        `picker.componentFollowsMouse = true`.
-   scart
    -   Allow to rename net, sta, loc, ch codes in dump and import modes,
        thanks to Luca Scarabello (SED/ETHZ).
    -   Unify `-t`, `-n`, `-c`, `--list`, `--nscl` options for Dump and Import
        mode, thanks to Luca Scarabello (SED/ETHZ).
    -   Add command-line option `--ignore` for ignoring empty records.
    -   Add command-line option `-o` for writing miniSEED records to file in
        import mode.
    -   Allow filtering records from files by time (`-t`) in import mode.
    -   Allow filtering records from files by stream lists (`--nslc`) in import
        mode.
    -   Report empty records whenever found.
    -   Print stream information whenever requested by `--print-streams`.
    -   Report errors even without verbose option (Luca Scarabello (SED/ETHZ))
    -   When using `--print-streams` option in import mode the data
        is written instead of just printing information. This has
        been fixed (Luca Scarabello (SED/ETHZ)) and can be deactivated with
        `--test`.
    -   Add summary for `--print-streams`.
    -   Update documentation.
-   scmssort
    -   Fix reading miniSEED from stdin which was not the default anymore due to
        recent code changes.
    -   Add command-line option `--ignore` for ignoring empty records.
    -   Report empty records whenever found.
    -   Support verbosity at different levels using `-v`, `-vv`, `-vvv`.
    -   Add command-line option `-o` for explicitely writing miniSEED records to
        file instead of stdout.
-   scsendjournal
    -   Add `-i` to read journal parameter data from file.
-   scbulletin
    -   Do not crash when reading origins with magnitudes but without
        corresponding picks.
    -   Guess missing arrival weight from use of measurements.
-   ql2sc
    -   Update filter documentation.
-   scautopick
    -   Fix segmentation fault if being used in playback mode without
        inventory
    -   Remove fixed noise margin of 60s for any picker which is optionally
        created for each detection, e.g., if configured with `picker = AIC`.
-   scmv
    -   Add tooltip to station layer with station annotation.
-   scrttv
    -   Update documentation.
    -   Show different colour scheme for picks and arrivals (associated with a
        non-rejected origin).
    -   Allow to collect picks to create a preliminary location which can be
        sent to the messaging as regular origin object.
    -   Add reload action which reloads data and picks at the current visible
        time range.
    -   Add action to switch to real-time with configured buffer size.
    -   Re-organize menus and actions.
    -   New option `--map-picks` allows to show picks on visible streams even
        when they were created on invisible streams, e.g., S picks created on
        horizontal components are shown verticals.
    -   Add `--input-file` to load an XML pick file at startup.
-   scmapcut
    -   Fix segmentation fault at exit if a tilestore plugin is used.
-   scqc
    -   Fix default configuration timeout value for Rms plugin from 60 back to 0
        reflecting the documented default value. A value greater than 0 results
        in warning messages such as "TimeOut specified, but no timeoutTask was
        defined for this QcPlugin".
-   scinv
    -   Add gain=0 check to documentation.
-   invextr
    -   Correct command-line help.
-   scwfparam
    -   Use organization configuration parameter for ShakeMap version >= 4
    -   Populate ShakeMap commtype attribute from bindings
    -   Allow to output any spectral values with ShakeMap version >= 4
-   LOCSAT
    -   Add Iw phase.
    -   Apply strict limit of 210 distance samples to travel time tables.
    -   Reduce memory consumption to the bare minimum required by the
        provided travel-time tables.
    -   Update documentation.
-   iLoc
    -   Fix crash in local travel-time computation and if local model is enabled
        but not configured.
    -   Make parameter `auxDir` and `MaxLocalTTDelta` configurable in scconfig.
    -   Fix reading `LocalVModel` and `DoNotRenamePhases` from configuration.
-   diskmon
    -   Improve Python3 support.
-   FDSN StationXML
    -   Fix generating of -nan values for clock drift caused by sample rates
        of 0.

## 5.3.0

```SC_API_VERSION 15.3.0```

-   trunk
    -   Fix reading `logging.syslog` from configuration file in any application.
    -   Fix JSON archive with respect to serialization of polymorphic objects
    -   Resolve all path variables defined with @ when reading configuration
        strings. This affects in particular the author configuration which now
        needs 6 @ characters for correct escaping, e.g. `@appname@@@@@@hostname`.
    -   Figuring out the three components of a sensor location or the vertical
        component of the sensor location from the inventory does not require the
        Stream.azimuth to be set if the dip is defined -90 or 90 degrees. This
        relaxes the requirement of a well defined inventory for vertical channels.
-   sccnv
    -   Add conversion from QuakeML to SCML documentation.
-   scrttv
    -   Allow configuration of stream decorations using scconfig.
    -   Allow `streams.codes` to contain stream group profiles, e.g.
        `streams.codes = GE.UGM..*, MyStreamsProfile`
-   GUI
    -   Add tooltips to all column headers of event list.
    -   Fix filter issue with transformed 3C traces
    -   Fix event and origin count in EventList if objects are removed
-   XML
    -   Improve performance in scml to quakeml XSLT parser (thanks to Anthony Carapetis)
-   apps
    -   Remove author settings from default configuration files.
-   scmssort
    -   Remove listed streams from input
    -   Update documentation
-   scinv
    -   Add nslc option for more compact output which is also compatible
        with e.g. scmssort or scart.
    -   Update documentation
-   invextr
    -   Add region filter
    -   Update documentation
-   scart
    -   Add `--print-streams` option
-   scconfig
    -   Allow renaming files in Inventory panel by right-click on module.
    -   Allow opening module log files in system panel by right-click on module.
-   scolv
    -   Add `-i` to load an XML file on start up
    -   Make ID column selectable in arrival table of Location tab for showing
        the pick ID.
    -   Allow copying cells in arrival table of Location tab.

## 5.2.2

-   scevtlog
    -   Fix segmentation fault on exit

## 5.2.1

-   Amplitudes ML*
    -   Fix bug which prevented `signalEnd`, `minSNR` and `maxDist` from being
        configurable

## 5.2.0

```SC_API_VERSION 15.2.0```

-   fdsnxml2inv
    -   Add support for "subject" attribute in FDSNXML::Comment
    -   Add support for instrument identifiers
-   GUI
    -   Allow theoretical arrivals with negative depth in picker/amplitude view
    -   Add support for GeoJSON to export of map drawings
    -   Fix FM event list loading with filters
    -   Fix segmentation fault in trace widget in combination with empty
        records
-   scalert
    -   Add more configurable constraints to scripts started up reception of
        picks (thanks to Luca Scarabello, ETH Zurich, for this contribution).
-   scautoloc
    -   Fix a bug occasionally resulting in two associated picks of the same
        station and phase.
-   scardac
    -   Support plugins for scanning other than miniSEED SDS archives.
-   scautopick
    -   Make phase hint configurable for primary picker.
-   scbulletin
    -   Add support for event and origin lists with options `-E` and `-O`.
-   scconfig
    -   Add used SeisComP version number to GUI header.
-   scchkcfg
    -   Increase verbosity
-   scevent
    -   Make eventID slot margin configurable (`eventIDLookupMargin`). The default
        value was 5 which meant that only 5 event slots in the future and 5 event
        slots in the past were checked for availability in case of eventID conflicts.
        This could lead to allocation errors in case of earthquake swarms. Now the
        number of slots to look back and to look ahead is determined based on the
        event association time window (+/- 30 minutes) by default.
-   scevtls
    -   Add option `--hours` for searching the database within given hours before
        now.
-   scolv
    -   Fix mapping of map station symbols and arrival table rows. This mapping
        was unfortunately out of sync in previous 5.x versions.
    -   Preset fixed depth and depth type if `olv.locator.presetFromOrigin` is enabled
-   scorgls
    -   Add command-line option `-D` for a custom delimiter.
-   scqcv
    -   Update default configuration parameters and description for evaluating
        score in QcOverview.
-   scqueryqc
    -   Use 1970-01-01 for default begin if begin is not set.
    -   Fix option `-i`.
-   travel-time interface
    -   Add interface 'homogeneous' for velocity models with just one P- and one
        S-wave velocity (thanks to Luca Scarabello, ETH Zurich, for this
        contribution).
-   XML
    -   Install 0.12 schema and XSLT files

## 5.1.1

-   The release did not contain the latest advertised changes of the main
    repository. This version does not introduce any new features or bugfixes.

## 5.1.0

```SC_API_VERSION 15.1.0```

-   scbulletin
    -   Add option `--fdsnws` for printing event parameters on just one line in
        FDSN event text format supporting to generate catalogs from event XML
        files.
    -   Correct output string of creation time from first origin time to event.
-   scdbstrip
    -   Fix reading `--days`.
    -   Add options `-E` and `-Q` as well as module configuration for limiting
        stripping to event parameters and waveforms quality control parameters,
        respectively.
-   scmssort
    -   Report duplicate records whenever found.
-   scquery
    -   Do not require a database when using `--showqueries`.
-   ql2sc
    -   Add publicID prefix white- and blacklist configuration as alternative
        to the already available agencyID filter.
    -   Add option to ignore object removals during import.
    -   Add more stable algorithm to synchronize the imported event with the
        target system. This reduces the likelihood of infinite loops (re-imports)
        on cross connected systems tremendously (note: it does not prevent that!).
-   scinv
    -   Add more tests to inventory check.
    -   Add command-line options for tolerances: `max-elevation-difference` and
        `max-sensor-depth` and corresponding module configuration parameters.
    -   Add a test matrix to documentation reporting tests and consequences.
-   FixedHypocenter
    -   Set uncertainties in location to 0 km if entered manually.
-   scrttv
    -   Show number of traces in tab header

## 5.0.1

-   trunk
    -   Fix bug in application which causes `processing.blacklist.agencies`
        and `processing.whitelist.agencies` to be switched.

## 5.0.0

```SC_API_VERSION 15.0.0```

With this version we drop Python 2 support for the maintained Python wrappers
as well as for all modules. Most of the modules are still Python 2 compatible
but we won't maintain that compatibility over the next versions and will only
support Python versions >= 3.3.

Furthermore the detection of the installed Linux distribution
(`seiscomp install-deps`) does not require `lsb_release` anymore. Instead we
check `/etc/os-release`. All RHEL based dependencies are now located in the
folder `rhel` instead of `centos`.

The database schema receives an update and will increase the schema version
to 0.12.

-   VS(SC), Virtual Seismologist for SeisComP has been removed from the SeisComP
    and is now available from a separate repository as an addon module. Read
    the section "Addon Modules" of the seiscomp documentation for the details.
-   fdsnws
    -   Fix broken unicode XML responses.
    -   Fix invalid request logging when HUP signal received.
-   scart
    -   New command-line parameter `--check` for new check mode checking
        miniSEED files in directories for out-of-order records.
    -   New command-line parameter `--with-filecheck` for checking generated
        miniSEED files for out-of-order records after writing them.
    -   New command-line parameter `--nslc` for filtering streams in dump mode
        by a list of streams.
-   scautopick
    -   When configuring `sendDetections = true` and `picker`, initial picks
        made by the trigger receive the evaluation status `rejected` allowing
        discrimination from picks by the re-picker. Use evaluation mode
        `automatic` for both.
    -   Add support for an additional processing stage called FX which means
        feature extraction and is applied on top of an existing pick. A
        first implementation ported from CTBTO/IDC's DFX code has been added
        to extract back azimuth and slowness for three-component stations.

        ```
        fx = DFX
        ```

-   scbulletin
    -   Filter events in XML files by event ID if provided with option `-E`.
-   scdbstrip
    -   Do no add a default number of days to time span if any other time value
        is given.
-   scevent
    -   evrc plugin provides more control options for setting and overwriting
        event types.
    -   Add option to populate Flinn-Engdahl region name event description.
-   scevtls
    -   Add option `-p` allowing to print the ID of the preferred origin along
        with the event ID.
-   scevtstreams
    -   New command-line parameter `--net-sta` for filtering streams by network
        and station codes.
-   scqcquery
    -   Removed module. It is replaced by new module scqueryqc.
-   scqueryqc
    -   Added as new module including HTML documentation for querying the data
        base for waveform quality control (QC) parameters.
    -   Allows filtering by QC parameter, stream and time.
-   scesv
    -   Add number of listed / loaded events in title of Events tab.
-   scmv
    -   Improve visibility of station annotations.
-   scolv
    -   Add pick uncertainty bars to residual plots in Location tab
    -   Add number of shown / loaded events in title of Events tab
    -   Allow showing station annotations in maps of Location tab
    -   Show time window of re-picker on traces after re-picking
    -   Add "Fix FM + Mw" button to fix the focal mechanism and the Mw
        with one click
    -   Show predicted phase arrival times in amplitude picker.
-   Magnitudes
    -   Add new magnitude type MLc - like ML with customization:
        -   Amplitude pre-filtering
        -   Optional Wood-Anderson instrument simulation
        -   Configurable scaling for input unit conversion
        -   Parametric calibration, optional non-parametric
        -   Optional regionalization of calibration
        -   Configurable distance measure.
    -   ML, MLv, MLc: logA0 parameters take the new value format:
        dist1:correction1,dist2:correction2,...
    -   Add ability to configure magnitudes with region-dependent
        parameters in global module configuration.
    -   Add amplitude pre-filtering to ML, MLv and MLc
-   LOCSAT
    -   Add global configuration parameters for using backazimuth and slowness,
        `LOCSAT.usePickBackazimuth` and `LOCSAT.usePickSlowness`.
-   FixedHypocenter
    -   Allow adjusting the hypocenter coordinates interactively in the locator
        settings of scolv.
-   hypo71
    -   Do not crash when Hypo71 cannot compute the arrival time for a given
        phaseHint.
-   GUI
    -   Use triangles as station symbols on all maps.
    -   Allow configuration of precision of origin time.
    -   Add to events list interactive filtering of events inside or outside
        defined regions.
    -   Clean up event list and event edit parameters in global configuration.
        A warning is printed when using deprecated parameters.
        Deprecated global configuration parameter -> new parameter:

        ```
        eventlist.customColumn                 -> eventlist.customColumn.name
        eventlist.regions                      -> eventlist.filter.regions.profiles
        eventlist.region.$name.name            -> eventlist.filter.regions.region.$name.name
        eventlist.region.$name.rect            -> eventlist.filter.regions.region.$name.rect

        eventedit.customColumn                 -> eventedit.origin.customColumn.name
        eventedit.customColumn.default         -> eventedit.origin.customColumn.default
        eventedit.customColumn.originCommentID -> eventedit.origin.customColumn.originCommentID
        eventedit.customColumn.pos             -> eventedit.origin.customColumn.pos
        eventedit.customColumn.colors          -> eventedit.origin.customColumn.colors
        ```
    -   Add support for event list filters based on polygons defined in either
        the fep or bna/geojson directories.
        ```
        eventlist.filter.regions.region.Test.poly = "my polygon"
        ```

-   trunk
    -   Remove application configuration support for `recordstream.service` and
        `recordstream.source` which has been completely replaced with
        `recordstream`.
    -   Remove application configuration support for `database.type` and
        `database.parameters` which has been completely replaced with
        `database`.
    -   Add event certainties "felt", "damaging" in line with IASPEI event type
        leading character.
    -   Add non-QuakeML event types "calving", "frost quake", "tremor pulse",
        "submarine landslide", "rocket launch", "rocket", "rocket impact",
        "artillery strike", "bomb detonation", "moving aircraft",
        "atmospheric meteor explosion".
    -   Add new routing RecordStream which allows to route specific network,
        station, location or channel codes to fixed proxy streams (thanks to
        Luca Scarabello / ETH for this contribution)
    -   Add usage and examples to command-line help for many Python utilities.
    -   Update Flinn-Engdahl region names to match Wikipedia.

-   seedlink
    -   Add GFZ meteo protocol support (serial_plugin).
    -   Add GDRT (GFZ Displacement Real-Time) protocol support (gdrt_plugin).
    -   Fix using invalid memory with script arguments (serial_plugin, miscScript).
    -   Check for invalid message (serial_plugin, Vaisala ASCII protocol).
    -   Improve seisplotjs compatibility by adding Sec-WebSocket-Protocol header.

## 4.10.1

-   trunk
    -   Fix reading `logging.syslog` from configuration file in any application.
        This is a backport from version 5 and is not fixed in version <= 5.2.2.

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
    -   Fix saving location of the generated configuration file with
        `seiscomp setup`. Due to a bug the file was generated in
        `~/.seiscomp/scmaster.cfg` whereas it should have been generated in
        `etc/scmaster.cfg`. As this is fixed now, please remove
        `~/.seiscomp/scmaster.cfg` if you were affected by the bug otherwise
        this old configuration will take precedence and new configurations will
        not have any effect. This bug has been introduced with version 4.9.0.

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
    -   Add option `--delimiter` for defining the field delimiter
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
    -   Use configured magnitude digits to display Mw magnitude value.
    -   Only enable creation of artificial origin in zoom trace if picking
        is disabled.
    -   Fix committing of manual amplitudes in the amplitude picker.
-   scmag
    -   Fix bug that caused multiple occurrences of magnitudes of the same
        type when a new set of manually computed amplitudes has been received.
-   trunk
    -   Fix segmentation fault when reading malformed GeoJSON features.
-   scorgls
    -   Add option to filter for author (thanks to Fred Massin / ETHZ).
-   scmssort
    -   Fix error when two or more files are passed.
-   seedlink
    -   Fix typo in setup script.
    -   Add misc plugin.

## 4.7.3

-   trunk
    -   Fix MYSQL database setup script to create
        ro and rw user accounts correctly.

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
    -   Add `--wait` parameter to set the timeout when acquiring
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
    -   Add new `--list` option to filter miniSEED data by stream lists
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
    -   Add `-J`, `--journal` option allowing to export the journal

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
    -   When using `--ep` playbacks with origins defined by `-O`, then the
        processing is limited to the defined origins.
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
    -   Fix combined RecordStream for slinkMax|rtMax|1stMax units `s` and `h`
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
