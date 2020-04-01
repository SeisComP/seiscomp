**********************
Introduction and Scope
**********************

SeisComP is likely the most widely distributed software package for real-time monitoring
of earthquakes and other seismic events. It provides automatic and interactive
seismological data acquisition, processing and data exchange over the Internet. Its
data transmission protocol SeedLink has become a de facto world standard.

SeisComP convinces many seismologists and earthquake specialists at data and
research centers, companies and governmental agencies world-wide by:

* powerful and reliable automatic data processing in real time or during post-processing
* user-friendly and comprehensive graphical interfaces
* modern and well-maintained `OpenSource software <https://github.com/SeisComP>`_ welcoming community contributions.

The first work on what became SeisComP today began nearly two decades ago
with developments at GFZ of plugins for digitizers.
The :ref:`section on historical information <history>` provide details on the past
and current releases.

Today SeisComP includes the following features:

* data acquisition
* waveform archiving
* waveform data distribution
* data quality control
* data recording
* real-time data exchange
* network status monitoring
* real-time data processing
* issuing event alerts
* automatic event detection and location
* interactive event detection and location
* event parameter archiving
* easy access to relevant information about stations, waveforms and recent
  earthquakes

The guidelines for the design
of SeisComP are:

* implementation of critical functions as standalone modules to guarantee the
  independence from other functions (e.g. picker, magnitude calculation,
  interactive analysis)
* easy implementation of custom modules
* independence of hard- and software
* ability of data exchange between different automatic real-time systems
* distribution of modules on several systems
* robust system for rapid and reliable earthquake solutions (especially during
  seismic crises)

These design principles have given SeisComP much robustness and flexibility
to respond to new developments.

This documentation begins with an overview and :ref:`concepts` necessary for using SeisComP successfully.
It then covers the :ref:`installation <installation>`, and how to configure and operate a working SeisComP system.
A few :ref:`tutorials` will guide you through a first example set up and further operations.
The tutorials are followed by detailed technical descriptions of each individual SeisComP
module, grouped by their general functionality - interactive analysis, data acquisition, inventory management,
automatic processing, etc.

The final part of the documentation relates to contributing your own code to SeisComP.
This requires a deeper knowledge of the SeisComP data model and other details.
It also includes guidelines for developers.

SeisComP is developed and distributed under the terms of the GNU
`Affero General Public License <https://www.gnu.org/licenses/agpl-3.0.html>`_,
as set out in the :ref:`license` section.
