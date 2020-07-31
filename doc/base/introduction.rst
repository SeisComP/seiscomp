.. _introduction:

**********************
Introduction and Scope
**********************

SeisComP is likely the most widely distributed software package for real-time monitoring
of earthquakes and other seismic events. It provides automatic and interactive
seismological data acquisition, processing and data exchange over the internet. Its
data transmission protocol SeedLink has become a de facto world standard.

SeisComP convinces many seismologists and earthquake specialists at data and
research centers, companies and governmental agencies world-wide by:

* Powerful and reliable automatic data processing in real time or during post-processing
* User-friendly and comprehensive graphical interfaces
* Modern and well-maintained OpenSource software on `GitHub`_ welcoming community contributions.

The first work on what became SeisComP today began nearly two decades ago
with developments at :term:`GFZ` of plugins for digitizers.
It is now continued by :term:`gempa GmbH` and GFZ.
The :ref:`section on historical information <history>` provides details on the past
and current releases.


Features
========

Today SeisComP includes the following features:

* Data acquisition
* Waveform archiving
* Waveform data distribution
* Data quality control
* Data recording
* Real-time data exchange
* Network status monitoring
* Real-time data processing
* Automatic event detection and location
* Interactive event detection and location
* Automatic and interactive magnitude calculation
* Interactive determination of focal mechanisms
* Issuing event alerts
* Event parameter archiving
* Easy access to relevant information about stations, waveforms and recent
  earthquakes through graphical user interface and command-line tools
* Python interface for developing custom scripts and modules.


Software Design
===============

The guidelines for the design of SeisComP are:

* Implementation of critical functions as standalone modules to guarantee the
  independence from other functions (e.g. picker, magnitude calculation,
  interactive analysis)
* Easy implementation of custom modules
* Independence of hard- and software
* Ability of data exchange between different automatic real-time systems
* Distribution of modules on several systems
* Robust system for rapid and reliable earthquake solutions (especially during
  seismic crises)

These design principles have given SeisComP much robustness and flexibility
to respond to new developments. The SeisComP community is encouraged to contribute
their SeisComP source code on `GitHub`_. Examples and guidelines for generating
code are given in the :ref:`developer section <sec_index_developers>`.


This Documentation
==================

This documentation begins with an :ref:`overview` and a :ref:`concepts` section
necessary for understanding and using SeisComP successfully.
The :ref:`Glossary section <glossary>` introduces technical terms.
All important code changes are listed in the :ref:`change log <sc-changelog>`.
When using SeisComP or contributing source code, you should understand the :ref:`license terms <license>`.
If you actually make use of SeisComP and publish the results, we ask you to give
appropriate reference as set out on the :ref:`Citation section <citation>`.

In the following section the documentation covers the :ref:`installation <installation>`
and how to configure and operate a working SeisComP system.
A few :ref:`tutorials` will guide you through a first example set up and further operations.

The tutorials are followed by :ref:`detailed technical descriptions <sec_index_modules>`
of each individual SeisComP module, grouped by their general functionality:

* Interactive analysis
* Data acquisition
* Inventory management
* Automatic processing
* Utilities

and many more :ref:`extensions <sec_index_extensions>` like descriptions of the
:term:`RecordStream`, magnitude types, locators, GUI customizations, waveform filters or plugins.

The final part of the documentation relates to
:ref:`contributing your own source code <sec_index_developers>` to SeisComP.
This requires a deeper knowledge of the :ref:`SeisComP data model<api-datamodel-python>`
and other details.
This part also includes guidelines for developers such as
:ref:`coding conventions <coding_conventions>`, :ref:`unit tests <unittests>` and a
:ref:`guide for contributing documentation <contributing_documentation>`.
:ref:`Some Python examples <sdk-python-examples>` help you to get started quickly
with programming for SeisComP.

SeisComP is developed and distributed under the terms of the GNU
`Affero General Public License`_, as set out in the :ref:`license` section.


References
==========

.. target-notes::

.. _`GitHub` : https://github.com/SeisComP
.. _`Affero General Public License` : https://www.gnu.org/licenses/agpl-3.0.html
