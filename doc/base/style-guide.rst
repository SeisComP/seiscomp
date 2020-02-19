*****************************
Style Guide for Documentation
*****************************

File layout
***********

The :ref:`contributing_documentation` section aboves details
documentation requirements for executables.
This uses a pair of source files; an XML file gives command details,
command line and configuration parameters, while a reST text file
gives a more-detailed description and examples.
The reST text file should follow the guidelines in this section.


Documentation file syntax
*************************

A template for a typical application or module in reST is in :file:`doc/templates/app.rst`.
An introductory paragraph should describe the purpose of the executable.
This is followed be any additional information needed to understand
the command, introduced with one or more subheadings.

- Put information about testing and examples into their own subheadings.


General principles
==================

- If possible, keep line lengths under 80 characters.
- It eases later editing if sentences in the raw RST start on a new
  line, even though they will flow together in the finished document.
- It is helpful if long text objects such as HTML link text each
  appear on their own line.


Headings
========

Module description files do *not* require top-level headings, as the
build script will take this text and assemble it with other
description information in the appropriate part of the documentation.

While RST doesn't care too much about what syntax is used for
headings, it is best to stick to one style consistently.
Thus you will generally need only two levels of headings. (Table like in RST doc. TODO)

+----------------+---------------------------+
| Document level | Mark up                   |
| Subheading     |  == beneath heading text  |
+----------------+---------------------------+
| Subsubheading  |  -- beneath heading text  |
+----------------+---------------------------+

Use Title Case for subheadings, and only the first letter for subsubheadings is uppercase.
Higher levels, marked up with asterisks, are used for sections of the documentation.

Parts such as Examples are marked in **bold**.

However notes and figures should use the appropriate RST directive, and don't require their own headings.


Lists
=====

Indent, ordering, unordered.


Other markup tools and conventions
==================================

- Use the reST code-block syntax for code fragments, with flavour "c", "python", "sh" or "xml" as appropriate. ::

     .. code-block:: python

- Use the reST :file: indicator to refer to files such as configuration files. ::

     :file:`/etc/foo/bar.cfg`

- Configuration values and options have a special syntax using the :confval: tag. ::

     :confval:`foo`

  Using this allows a link to be made to the documentation for that configuration value.
- One blank line below headings is enough.
  Two lines above are often used, and this looks better than one.


English
=======

- Start list items with a capital letter. End them with a full stop (period).
- SeisComP (capital P), not SeisComP 3 or SC3.
- SeisComP module names are proper nouns, even though written with lower case.
  Thus they do not need an article.

  * Correct: "Although scmaster receives a message"
  * Incorrect: "Although the scmaster receives a message..."

Disputed: a sentences may begin with a lower case module name e.g. "scmaster has five modes..."
To avoid this: "The scmaster module has..."

- Worttrennung:

  - Getrennt:
    base class
  - Zusammengeschrieben:
    aftershock, foreshock, *and mainshock too*,
    bandpass, eigenperiod etc., metadata, standalone, username, workflow,
  - Difficult:
    high-pass filter; commandline or command-line or command line?; time span?

- Hyphenation for compound adjectives: yes, before a noun; after verb to be is harder.
  See https://english.stackexchange.com/questions/65630/you-should-be-well-organised-or-you-should-be-well-organised

- Spelling:

  - With 'z': digitizer, realize, visualize.
  - With 's': license.
  - What about synchronise?
  - Center, data center.
  - Unclear: behaviour/behavior.
  - Ugly: timespan

- Case:

  - SEED, Mini-SEED (miniSEED in libmseed doc, or MiniSEED,
    but Mini-SEED appears in Appendix G of the standard.)
  - Ctrl+S for 'control' key plus 's'.
  - MySQL, PostgreSQL

- Abbreviations

  - e.g., i.e.
  - STA, LTA
  - TAR/tar?

.. note::
  packagemake ?? (installation.rst)
  SuSE?
  ringbuffer (depends)
