.. _history:

**********************
Historical Information
**********************

The first version of SeisComP was developed for the
:term:`GEOFON` program operated by :term:`GFZ`.

Originally, |scname| was designed as a high-standard, fully automatic data
acquisition and (near-)real-time data processing tool including quality control,
event detection and location as well as dissemination of event alerts.

SeisComP was further extended within the MEREDIAN project under the lead of
GEOFON and :cite:t:`orfeus`.

Following the devastating 2004 Indian Ocean earthquake and tsunami, the
:cite:t:`gitews` (German Indian Ocean Tsunami Early Warning System) project led
to additional functionality being implemented to fulfill the requirements of
24/7 early warning control centers. Major changes in the architecture of SeisComP
were necessary and many new features resulted in the upgrade of SeisComP to 
version 3.

Since 2008 SeisComP has been jointly developed by :term:`gempa GmbH`, a spin-off
company of GFZ and GFZ. Nowadays, gempa GmbH is the main SeisComP developing and
service company.

Major SeisComP releases are shown below. The important changes as of version 4.0
are documented in the :ref:`changelog <sc-changelog>`.

+---------+-----------+--------------------+-----------------------------------------------------+
| Version | Name      |  Time              |                                                     |
+=========+===========+====================+=====================================================+
| 1.0     |           | February 2001      | SeedLink 2.0 (plugin interface) Plugins for         |
|         |           |                    | EarthData PS2400 and Lennartz M24                   |
+---------+-----------+--------------------+-----------------------------------------------------+
| 1.1     |           | August 2001        | SeedLink 2.1 (streams.xml, improved buffer          |
|         |           |                    | structure); make conf/make key scripts LISS         |
|         |           |                    | plugin, SeedLink-Antelope connectivity              |
+---------+-----------+--------------------+-----------------------------------------------------+
| 1.1.5   |           | January 2002       | SeedLink 2.5 (multi-station mode)                   |
+---------+-----------+--------------------+-----------------------------------------------------+
| 1.16    |           | March 2002         | GIF live seismograms                                |
+---------+-----------+--------------------+-----------------------------------------------------+
| 2.0     |           | October 2003       | SeedLink 3.0 (INFO request, time window extraction) |
|         |           |                    | libslink, chain plugin, Comserv-independence        |
+---------+-----------+--------------------+-----------------------------------------------------+
| 2.1     |           | June 2004          | Python add-on package (SeisPy) incl. AutoLoc2 chain |
|         |           |                    | plugin extension interface, triggered streams       |
+---------+-----------+--------------------+-----------------------------------------------------+
| 2.5     |           | March 2006         | Integration of add-on packages, modular config      |
|         |           |                    | script                                              |
+---------+-----------+--------------------+-----------------------------------------------------+
| 3.0     | alpha     | May 2007           | new architecture, new magnitude types, GUI          |
+---------+-----------+--------------------+-----------------------------------------------------+
| 3.0     | Barcelona | May 2008           | Stability and performance improvements, improved    |
|         |           |                    | GUI functionality                                   |
+---------+-----------+--------------------+-----------------------------------------------------+
| 3.0     | Erice     | May 2009           | New Earthquake Schema and performance improvements, |
|         |           |                    | improved GUI functionality                          |
+---------+-----------+--------------------+-----------------------------------------------------+
| 3.0     | Potsdam   | September 2010     | New Inventory Schema and performance improvements,  |
|         |           |                    | improved GUI functionality                          |
+---------+-----------+--------------------+-----------------------------------------------------+
| 3.0     | Seattle   | 2012               | New user friendly configuration GUI scconfig        |
+---------+-----------+--------------------+-----------------------------------------------------+
| 3.0     | Jakarta   | 2014               | Completely Open Source, including all GUIs          |
+---------+-----------+--------------------+-----------------------------------------------------+
| 4.0.0   |           | May 2020           | Adopts the GNU Affero General Public License v. 3.0,|
|         |           |                    | (AGPL), support for Python3 and QT5                 |
+---------+-----------+--------------------+-----------------------------------------------------+
