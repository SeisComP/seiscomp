.. _documentation_style_guide:

*****************************
Style Guide for Documentation
*****************************


File Layout
===========

The documentation of an executable module comes as a pair of source files:

* A description XML file (.xml) giving command details, command-line and configuration parameters,
* A documentation reST text file (.rst) gives a more-detailed module description and examples.

Any other documentation, e.g. this style guide, tutorials, etc. only require the
documentation reST text file.

The reST text file should follow the guidelines in this style guide.

The :ref:`contributing_documentation` section details
the documentation requirements for executables including the structure of description XML files.


Documentation Syntax
====================

A template for a typical application or module in reST is in :file:`doc/templates/app.rst`.
An introductory paragraph should describe the purpose of the executable.
The introduction is followed be any additional information needed to understand
the command, introduced with one or more headings.
Add information about testing and examples into their own sections.


General principles
------------------

- If possible, keep line lengths under 80 characters.
- It eases later editing if sentences in the raw RST start on a new
  line, even though they will flow together in the finished document.
- It is helpful if long text objects such as HTML link text each
  appear on their own line.


  .. _documentation_style_guide_headings:

Section and headings
--------------------

Module description files do *not* require top-level headings, as the
build script will take this text and assemble it with other
description information in the appropriate part of the documentation.

While RST doesn't care too much about what syntax is used for
headings, it is best to stick to one style consistently.
Thus, you will generally need only two levels of headings but you can add more.

+-------+------------------------------+
| Level | Mark up beneath heading text |
+=======+==============================+
| 1     |  ' ==== '                    |
+-------+------------------------------+
| 2     |  " ---- "                    |
+-------+------------------------------+
| 3     |  ' ~~~~ '                    |
+-------+------------------------------+
| 4     |  ' ^^^^ '                    |
+-------+------------------------------+

Use Title Case for headings within a section, and make only the first letter uppercase for subheadings.
Higher levels, marked up with asterisks, are used for sections of the documentation.

**Example:**

.. code-block:: sh

   Level 1 Title
   =============

   Some text.


   Level 2 title
   -------------

   Some text

Parts such as Examples are marked in **bold**.

However notes and figures should use the appropriate RST directive, and don't require their own headings.

- One blank line below headings is enough.
- Two lines above are often used, and this looks better than one.

Lists
-----

Use numbered or unnumbered lists at several levels.

- Start list items at the first level with a capital letter. End them with a full stop.
- Use lower-case letters for all other levels. End them with a full stop.

.. code-block:: rst

   #. Item 1.
   #. Item 2.
      * subitem 1.
        #. subsubitem 1.
        #. subsubitem 1.
      * subitem 2.

**Result:**

#. Item 1.
#. Item 2.

   * subitem 1.

     a. subsubitem 1.
     #. subsubitem 2.

   * subitem 2.


Other markup tools and conventions
----------------------------------

- **Code fragments:** Use the reST code-block syntax for code fragments, with
  flavor "c", "python", "sh" or "xml" as appropriate: ::

     .. code-block:: sh

        #!/bin/bash
        echo $SEISCOMP_ROOT

  Result:

  .. code-block:: sh

     #!/bin/bash
     echo $SEISCOMP_ROOT

- **Configuration parameters:** Configuration values and options have a special syntax. Use the :confval: tag
  within the module configuration: ::

     :confval:`foo`

  Using this tag allows a link to be made within the documentation to that module
  to the given configuration or command-line parameter of the same module.

- **Configuration files:** Use the reST :file: indicator to refer to files such as configuration files: ::

     :file:`$SEISCOMP_ROOT/etc/scautopick.cfg`

  Result: :file:`$SEISCOMP_ROOT/etc/scautopick.cfg`

- **Programs:** Use the reST :program: indicator for |scname| programs: ::

     :program:`scautopick`

  Result: :program:`scautopick`

- **References:** Use the reST :ref: indicator for cross referencing |scname|. documentation pages.
  Use :ref: if a cross reference to the documentation is needed: ::

     :ref:`scautopick`

  Result: :ref:`scautopick`

- **Glossary:** Use the reST :term: indicator for referencing terms in the |scname| :ref:`glossary`: ::

     :term:`magnitude`

  Result: :term:`magnitude`


.. _documentation_style_guide_links:

Internal links
--------------

Create links to sections and subsections within and to figures  the text which can be referenced.
Use unique link names, e.g. including the upper-level section name or the module name.
Use appropriate short names to fit within the texts.

Link with in this documentation to the section on headings: ::

   .. _documentation_style_guide_headings:

Reference: ::

   :ref:`short name <documentation_style_guide_headings>`

Result: :ref:`short name <documentation_style_guide_headings>`


External references
-------------------

Do not show full citations or URLs for
external web sites within the text but make references which
are listed in the section :ref:`sec-references`. Procedure:

#. Add publications, external URLs, etc. as complete citation
   entries to the reference list :file:`doc/base/references.bib`
   in the base |scname| :ref:`repository on Github <build>`.
#. Cite documents within the RST file using the *cite*
   directive ::

      :cite:p:`seiscomp`
      :cite:t:`seiscomp`

   which results in :cite:p:`seiscomp` and
   :cite:t:`seiscomp` within the documentation HTML text.


Text boxes
----------

You may emphasize information within the text as text boxes to stand out at different levels.
Make sensible use of it!

* Hints ::

     .. hint::

        This adds a useful hint.

  Result:

  .. hint::

     This adds a useful hint.

* Notes ::

     .. note::

        This adds an extra note.

  Result:

  .. note::

     This adds an extra note.

* Alerts ::

     .. caution::

        This adds a heads-up alert.

  Result:

  .. caution::

     This adds a heads-up alert.

* Warnings ::

     .. warning::

        This adds an important warning.

  Result:

  .. warning::

     This adds an important warning.


English Language
================

- SeisComP (capital P), not SeisComP 3 or SC3.
- |scname| module names are proper nouns, even though written with lower case.
  Thus they do not need an article.

  * Correct: "Although :program:`scmaster` receives a message"
  * Incorrect: "Although the scmaster receives a message..."

A sentence may begin with a lower case module name e.g. "scmaster has five modes..."
avoiding this: "The :program:`scmaster` module has..."

- Word separation:

  - Separate words:
    base class, wave number, time span
  - One word:
    aftershock, foreshock, *and mainshock too*,
    bandpass, eigenperiod etc., metadata, standalone, username, workflow, waveform
  - Difficult:
    high-pass filter; command line; command-line parameter

- Hyphenation for compound adjectives: yes, before a noun; after verb to be is harder.
  See the `discussion`_, e.g.:

  - Use command-line parameters.
  - Type on the command line.

- Spelling:

  Use American English:

  - With 'z': digitizer, realize, visualize, synchronize, behavior, color.
  - With 's': license.
  - Center, data center.

- Case:

  - SEED, miniSEED (miniSEED in `libmseed documentation`_, or MiniSEED,
    but Mini-SEED appears in Appendix G of the `Seed Reference Manual`_.)
  - Ctrl+S for 'control' key plus 's'.
  - MySQL, PostgreSQL, MariaDB

- Abbreviations:

  - e.g., i.e.
  - STA, LTA, STA/LTA detector
  - TAR file

.. _documentation_style_guide_images:

Adding Images
=============

Code implementation
-------------------

* Add images with fixed width.
* Add image captions.
* Store images in a separate directory of below the directory where the
  documentation is kept.

Example for an image which can be enlarge by mouse click:

.. code-block:: rst

   .. figure::  media/image.png
      :alt: image one
      :width: 10cm
      :align: center

      Image one.

Example for images in two columns which cannot be enlarged. Up to 4 columns are possible.
Compare with the :ref:`concept section on configuration<concepts_configuration-configs>`:

.. code-block:: rst

   .. raw:: html

   <div class="two column layout">

   .. figure:: ../media/scconfig_no_bindings.png
      :alt: scconfig: bindings configurations

      scconfig modules panel indicating that no bindings can be configured.

    .. figure:: ../media/scconfig_has_bindings.png
       :alt: scconfig: no bindings configurations

       scconfig modules panel indicating that bindings can be configured.

    .. raw:: html

    </div>


Image style and format
----------------------

* Images shall be informative.
* Images must not have any offensive or inappropriate content.
* Use PNG format.
* Make the important image details readable at the normal image size without enlargement.
* Images shall be optimized for file size.
* Images should have a frame, e.g. a window frame.
* Avoid private information on images.
* Do not show desktop background unless required.
* Images from |scname| GUIs can be screenshots.
* Do not create screenshots from applications started remotely with X-forwarding.
  X-forwarding may distort the application features.


References
==========

.. target-notes::

.. _`gempa GmbH`: https://www.gempa.de
.. _`discussion` : https://english.stackexchange.com/questions/65630/you-should-be-well-organised-or-you-should-be-well-organised
.. _`libmseed documentation` : https://github.com/iris-edu/libmseed/wiki
.. _`Seed Reference Manual` : https://www.fdsn.org/pdf/SEEDManual_V2.4.pdf
