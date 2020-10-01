The scfruitmachine tool slices, dices and grates.
This is just the thing for preparing a |scname| fruit salad.

Slicing mode
============

When the --slice option is given, all |scname| are sliced.


From the left
-------------

By default, |scname| starts processing on the left.

From the right
--------------

Sometimes it may be necessary to flip things around.


Dicing mode
===========

There are many possible dicing strategies.


Testing
=======

A data set of 10000 fake events were sliced, diced, and grated.
Run scfruitmachine with the --test option to re-run the tests.


Examples
========

 1. Slice from the left, with basic dicing. This is the default salad.

    .. code-block:: sh

       scfruitmachine --slice

 1. Slice from the right, with checkerboard dicing

    .. code-block:: sh

       scfruitmachine --slice=right --dice=checkerboard

    This results in a more pleasant salad experience for left-handers.
