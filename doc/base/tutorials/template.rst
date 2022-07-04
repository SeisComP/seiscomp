.. _tutorials_template:

*********************
Create a new tutorial
*********************

You will ...

* Add something
* Configure something else

Pre-requisites for this tutorial:

* Have the source code of SeisComP available

Afterwards/Results/Outcomes:

* A new tutorial

Time range estimate:

* 30 minutes


-----------


Set-up
======

To use this template, you'll need to:

#. Get the source code of the SeisComP documentation, e.g. from
   :cite:t:`seiscomp-github`

#. Copy this tutorial file (:file:`doc/base/tutorials/template.rst`) to the tutorials directory
   with a new name, :file:`doc/base/tutorials/{nn}_{something}.rst`.

#. Change the reference at the top (first line); it must be
   *.. _tutorials_{something}*.

#. Change the title: start with a verb, describe what the student is
   trying to do.

#. Set the tutorial task and a final confirmation action for the student
   to verify check that it worked correctly.

#. Add the file name without the ending *.rst* to the table of contents in :file:`doc/base/tutorials.rst`
   assigning a position for your new tutorial within the sequence of
   existing tutorials.

#. Build the HTML documentation for viewing and :ref:`testing <tutorials_template_testing>`.

#. Optionally, provide your new tutorial to the public repository:

   * Create a new git branch
   * Push the new branch to GitHub
   * Create a merge request to get your branch merged into the master branch


.. _tutorials_template_testing:

Final Tests
===========

* If you've applied this template,

  .. code-block:: sh

     ls doc/base/tutorials

  will show your new tutorial.

* Rebuild the documentation

  .. code-block:: sh

     $ cd doc
     $ python3 build-doc.py

* View the new files in `build-doc/base/html/tutorials` using a web browser, e.g. firefox:

  .. code-block:: sh

     $ firefox build-doc/html/basetutorials.html
