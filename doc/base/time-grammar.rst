.. _time-grammar:

************
Time grammar
************

|scname| supports the definition of times by :ref:`functions
<sec-time-functions>`, :ref:`operators <sec-time-operators>` and :ref:`variables
<sec-time-variables>` and the combination of them as well as constant values.
These expressions can be used to configure parameters defining time windows for
measuring amplitudes for magnitudes.
You may use brackets *()* to apply operations within before operations outside
of them.


Examples
========

The details of the grammar elements used in the following examples are
described :ref:`below <sec-time-details>`.

* Return the end time to measure :term:`mB amplitudes <magnitude,
  broadband body-wave (mB_BB)>`:

  .. code-block:: properties

     min(D * 11.5, 60) || 60

  where :py:func:`min()` is a function with two parameters to
  compare, :envvar:`D` is a variable and '\*' and '\+' are operators. In this
  example  the minimum time from either epicentral distance in degree times 11.5
  or 60  is returned if an epicentral distance is available. If epicentral
  distance is not available, 60 is returned

* Return the end time to measure S-wave amplitudes:

  .. code-block:: properties

     min(tt(S) + 10, 150)

  where :py:func:`tt()` is a function with one argument  and '\+' is an
  operators. In this example the minimum time from either the travel time plus
  10 or 150 is returned.

Similar to the statements above, the time windows for measuring amplitudes can
be configured, e.g., for overriding default time for :term:`MLv amplitudes
<magnitude, local vertical (MLv)>`:

.. code-block:: properties

   amplitudes.MLv.noiseBegin=-10
   amplitudes.MLv.noiseEnd=-1
   amplitudes.MLv.signalBegin=-1
   amplitudes.MLv.signalEnd=tt(S)+10


.. _sec-time-details:

Functions, Operators, Variables
===============================

Variables, operators and functions are available. Variables define standard
values and function provide values based on a parameter given within parentheses
like :py:func:`tt()`. Find below their individual descriptions.


.. _sec-time-functions:

Functions
---------

.. py:function:: max(arg1,arg2)

   Calculates the maximum of two values

   :param arg1: First value to consider
   :param arg2: Second value to consider

.. py:function:: min(arg1,arg2)

   Calculates the minimum of two values

   :param arg1: First value to consider
   :param arg2: Second value to consider


.. py:function:: tt(phase)

   Calculates the travel-time of the given phase

   :param phase: Phase name available with the define travel-time interface
                 and profile.


.. _sec-time-operators:

Operators
---------

* \+ : addition
* \- : subtraction
* \* : multiplitation
* \/ : division
* \^ : power / exponentiation
* \|\| : logical OR
* \|. \| : absolute value
* \% : modulo


.. _sec-time-variables:

Variables
---------

.. envvar:: D

   :term:`Epicentral distance <distance, epicentral>` in degree

.. envvar:: d, R

   :term:`Epicentral distance <distance, epicentral>` in kilometer

.. envvar:: H

   :term:`Hypocentral distance <distance, hypocentral>` in degree

.. envvar:: h

   :term:`Hypocentral distance <distance, hypocentral>` in kilometer

.. envvar:: Z

   :term:`origin` depth in kilometer