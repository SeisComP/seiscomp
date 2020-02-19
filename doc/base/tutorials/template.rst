.. _tutorials_template:

*********************
Create a new tutorial
*********************

You will ...

* Add something
* Configure something else

:Pre-requisites for this tutorial:
* None, or
* list of other :ref:`tutorials <tutorials>

:Afterwards/Results/Outcomes:
* {What comes out at the end}

:Time range estimate:
* {XX} minutes.

:Related tutorial(s):
* {X, Y, Z} - where to go next.

-----------

Set-up
======

To use this template, you'll need to:

* Assign a position for your new tutorial within the sequence of
  existing tutorials.

* Copy this file (`99_template.rst`) to the tutorials directory
  with a new name, `{nn}_{something}.rst`.
  Add it to the table of contents file, `tutorial.rst`.

* Change the reference at the top (first line); it must be
  `_tutorials_{something}`.

* Change the title (start with a verb, describe what the student is
  trying to do).

* Set tutorial task and a final confirmation action for the student
  to verify check that it worked correctly.

Final tests
===========

* If you've applied this template, `ls doc/base/tutorials` will show your
  new tutorial.

* Rebuild the documentation ::

    cd doc
    python3 build-doc.py

  and view the new files in `build-doc/html/tutorials`.
