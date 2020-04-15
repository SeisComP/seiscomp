.. _history:

**********************
Historical information
**********************

The first version of SeisComP was developed for the `GEOFON`_ network operated by `GFZ`_.

Originally, SeisComP was designed as a high-standard, fully automatic data acquisition and (near-)real-time
data processing tool including quality control, event detection and location as well as dissemination
of event alerts.

SeisComP was further extended within the MEREDIAN project under the lead of GEOFON and `ORFEUS`_.

Following the devastating 2004 Indian Ocean earthquake and tsunami, the `GITEWS`_ (German Indian Ocean
Tsunami Early Warning System) project led to additional functionality being implemented to fulfill the
requirements of 24/7 early warning control centers. Major changes in the architecture of SeisComP
were necessary and many new features resulted in the upgrade of SeisComP to version 3.

Since 2008 SeisComP has been jointly developed by `gempa GmbH`_, a spin-off company of GFZ and GFZ.
Nowadays, gempa GmbH is the main SeisComP developing and service company.

Important SeisComP releases are shown below.


+---------+--------------------------------+-----------------------------------------------------+
| Version | Time                           |                                                     |
+=========+================================+=====================================================+
| 1.0     | February 2001                  | SeedLink 2.0 (plugin interface) Plugins for         |
|         |                                | EarthData PS2400 and Lennartz M24                   |
+---------+--------------------------------+-----------------------------------------------------+
| 1.1     | August 2001                    | SeedLink 2.1 (streams.xml, improved buffer          |
|         |                                | structure); make conf/make key scripts LISS         |
|         |                                | plugin, SeedLink-Antelope connectivity              |
+---------+--------------------------------+-----------------------------------------------------+
| 1.1.5   | January 2002                   | SeedLink 2.5 (multi-station mode)                   |
+---------+--------------------------------+-----------------------------------------------------+
| 1.16    | March 2002                     | GIF live seismograms                                |
+---------+--------------------------------+-----------------------------------------------------+
| 2.0     | October 2003                   | SeedLink 3.0 (INFO request, time window extraction) |
|         |                                | libslink, chain plugin, Comserv-independence        |
+---------+--------------------------------+-----------------------------------------------------+
| 2.1     | June 2004                      | Python add-on package (SeisPy) incl. AutoLoc2 chain |
|         |                                | plugin extension interface, triggered streams       |
+---------+--------------------------------+-----------------------------------------------------+
| 2.5     | March 2006                     | Integration of add-on packages, modular config      |
|         |                                | script                                              |
+---------+--------------------------------+-----------------------------------------------------+
| 3.0     | alpha May 2007                 | new architecture, new magnitude types, GUI          |
+---------+--------------------------------+-----------------------------------------------------+
| 3.0     | Barcelona release May 2008     | Stability and performance improvements, improved    |
|         |                                | GUI functionality                                   |
+---------+--------------------------------+-----------------------------------------------------+
| 3.0     | Erice release May 2009         | New Earthquake Schema and performance improvements, |
|         |                                | improved GUI functionality                          |
+---------+--------------------------------+-----------------------------------------------------+
| 3.0     | Potsdam release September 2010 | New Inventory Schema and performance improvements,  |
|         |                                | improved GUI functionality                          |
+---------+--------------------------------+-----------------------------------------------------+
| 3.0     | Seattle release 2012           | New user friendly configuration GUI scconfig        |
+---------+--------------------------------+-----------------------------------------------------+
| 3.0     | Jakarta release 2014           | Completely Open Source, including all GUIs          |
+---------+--------------------------------+-----------------------------------------------------+
| 4.0     | AGPL release 2020              | Adopts the GNU Affero General Public License v. 3.0,|
|         |                                | support for Python3 and QT5                         |
+---------+--------------------------------+-----------------------------------------------------+

References
==========

.. target-notes::

.. _`GEOFON`: https://geofon.gfz-potsdam.de
.. _`GFZ`: https://www.gfz-potsdam.de
.. _`GITEWS`: https://www.gitews.org
.. _`ORFEUS`: https://www.orfeus-eu.org
.. _`gempa GmbH`: https://www.gempa.de
