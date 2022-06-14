.. _introduction:

**********************
Introduction and Scope
**********************

SeisComP is likely the most widely distributed software package for real-time monitoring
of earthquakes and other seismic events. It provides automatic and interactive
seismological data acquisition, processing and data exchange over the internet. Its
data transmission protocol SeedLink has become a de facto world standard.

|scname| convinces many seismologists and earthquake specialists at data and
research centers, companies and governmental agencies world-wide by:

* Powerful and reliable automatic data processing in real time or during post-processing
* User-friendly and comprehensive graphical interfaces
* Modern and well-maintained OpenSource software on GitHub
  :cite:p:`seiscomp-github` welcoming community contributions.

The first work on what became |scname| today began nearly two decades ago
with developments at :term:`GFZ` of plugins for digitizers.
It is now continued by :term:`gempa GmbH` and GFZ.
The :ref:`section on historical information <history>` provides details on the past
and current releases.


Features
========

Today |scname| includes the following features:

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

The guidelines for the design of |scname| are:

* Implementation of critical functions as standalone modules to guarantee the
  independence from other functions (e.g. picker, magnitude calculation,
  interactive analysis)
* Easy implementation of custom modules
* Independence of hard- and software
* Ability of data exchange between different automatic real-time systems
* Distribution of modules on several systems
* Robust system for rapid and reliable earthquake solutions (especially during
  seismic crises)

These design principles have given |scname| much robustness and flexibility
to respond to new developments. The |scname| community is encouraged to contribute
their |scname| source code on GitHub :cite:p:`seiscomp-github`. Examples and
guidelines for generating
code are given in the :ref:`developer section <sec_index_developers>`.


This Documentation
==================

This documentation begins with an :ref:`overview` and a :ref:`concepts` section
necessary for understanding and using |scname| successfully.
The :ref:`Glossary section <glossary>` introduces technical terms.
All important code changes are listed in the :ref:`change log <sc-changelog>`.
When using |scname| or contributing source code, you should understand the
:ref:`license terms <license>`.
If you actually make use of |scname| and publish the results, we ask you to give
appropriate reference as set out on the :ref:`Citation section <citation>`.

In the following section the documentation covers the :ref:`installation <installation>`
and how to configure and operate a working |scname| system.
A few :ref:`tutorials` will guide you through a first example set up and further
operations.

The tutorials are followed by :ref:`detailed technical descriptions <sec_index_modules>`
of each individual |scname| module, grouped by their general functionality:

* Interactive analysis
* Data acquisition
* Inventory management
* Automatic processing
* Utilities

and many more :ref:`extensions <sec_index_extensions>` like descriptions of the
:term:`RecordStream`, magnitude types, locators, GUI customizations, waveform
filters or plugins.

The final part of the documentation relates to
:ref:`contributing your own source code <sec_index_developers>` to |scname|.
This requires a deeper knowledge of the |scname| :ref:`data model<api-datamodel-python>`
and other details.
This part also includes guidelines for developers such as
:ref:`coding conventions <coding_conventions>`, :ref:`unit tests <unittests>`
and a :ref:`guide for contributing documentation <contributing_documentation>`.
:ref:`Some Python examples <sdk-python-examples>` help you to get started
quickly with programming for |scname|.

|scname| is developed and distributed under the terms of the GNU
:cite:t:`agpl`, as set out in the :ref:`license` section.
