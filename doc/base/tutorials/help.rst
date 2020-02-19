.. _tutorials_help:

**************************
Help! I'm stuck! Now what?
**************************

This tutorial gives some ways to resolve problems with SeisComP.

:Pre-requisites for this tutorial:
* None

:Afterwards/Results/Outcomes:
* Improved understanding of ways to solve SeisComP problems.

:Time range estimate:
* 5 minutes.

----------

Outline
=======

Inevitably you will encounter difficulties using SeisComP.
This tutorial reviews a few ways to diagnose your problems and
get help to resolve them.

* Documentation
* The SeisComP Forum
* Reviewing logs
* The debug options


Documentation
=============

In addition to this document, many SeisComP commands have manual
pages.

There is documentation of configuration options available from `scconfig`.
Look under Modules, and choose the relevant module.
For each parameter, the first few lines of description are shown;
hovering over these reveals the full text.

[Advanced:
The text for these is taken from the XML files in `$SEISCOMP_ROOT/etc/descriptions`.]

The Forum
=========

.. figure:: media/help_forum.png
   :width: 16cm
   :align: center

   The SeisComP Forum (https://forum.seiscomp.org).

The `Forum <https://forum.seiscomp.org>`_ is the place to
discuss SeisComP.
Anouncements about updates, training courses and more are posted
here by the developers, and users can post questions or discuss
new developments.
Anyone can browse the forum, while registration is required to post there.

Logging
=======

Most SeisComP applications use a standard logging approach.
By default, they log to files in your `~/.seiscomp` directory,
such as `scamp.log`.

You can control how often these are rotated
(old log files are closed, and moved to a new file name, such as scamp.log.1, e.g. daily).
Alternatively you can use the system-wide logging facility `syslog`
and send logs to /var/log or another "standard" place.

There are four levels of severity of SeisComP log messages,
and applications can be configured to show only those which
are more severe than a given threshold.

* 1=ERROR
* 2=WARNING
* 3=INFO
* 4=DEBUG.

Default is 2.
Setting `logging.level = 4` results in the most messages.

Debugging options
=================

Most SeisComP applications support two important command line options:

* Use ` --console` to send output to the terminal instead of the usual
  log location.

* `-v` for increased verbosity, or use `--verbosity=` *n* where *n*
  is one of the four severity levels above.

In addition:

* `--debug` sets logging.level (see above) to 4 (DEBUG),
  and sends logging output to the console (terminal) instead of the usual
  log location.
  (This is just an easlier way of specifying `--verbosity=4 --console=1`)

In :ref:`scconfig`, logging can be set globally

Modules > System > global (see "logging")
or per module.

e.g. set "logging.level = 3" in $SEISCOMP_ROOT/etc/scamp.log
to set level XXXX only for `scamp`.


Next time you have a problem
============================

* Try some of the above techniques
* If you find a solution, don't forget to share it at the Forum.
