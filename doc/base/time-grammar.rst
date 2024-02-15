.. _time-grammar:

************
Time grammar
************

The time windows for measuring noise and signal for amplitudes used to compute
magnitudes can be configured by the respective begin and end values. These
window parameters are configured as global binding parameters specifically for
a particular amplitude type, let's say :ref:`ML <global_ml>`:

.. code-block:: properties

   amplitudes.ML.noiseBegin
   amplitudes.ML.noiseEnd
   amplitudes.ML.signalBegin
   amplitudes.ML.signalEnd

**The configured values are added to the relative trigger time and the
origin time** for forming absolute times. The relative trigger time
corresponds to the arrival of P waves for most applications. The configured
begin and end values are therefore given as time differences relative to the
absolute trigger time.


Example:

.. math::

   absoluteSignalEnd =\ &originTime + relativeTriggerTime + amplitudes.ML.signalEnd \\
                     =\ &triggerTime + amplitudes.ML.signalEnd

.. important::

   Where travel times of a particular phase are estimated from distance
   measures such as :envvar:`D` or :envvar:`h`, the relative origin time,
   :envvar:`OT`, must be added to get the time difference. In contrast,
   :py:func:`tt()` returns the time difference to :envvar:`OT` and
   :py:func:`tt()` does not need to be corrected.

In |scname| the configuration of the begin and end values is supported by a
combination of :ref:`functions <sec-time-functions>`,
:ref:`operators <sec-time-operators>`, :ref:`variables <sec-time-variables>` and
constant values. The combination of them allows setting up a flexible time
grammar for time windows. You may use parentheses *()* to apply operations
within the parentheses before operations outside of parentheses.

If the result of the final evaluation is *unset*, e.g., because required
information are not available, then the processing receives an error and the
amplitude will not be computed.


Examples
========

The details of the grammar elements used in the following examples are
described :ref:`below <sec-time-details>`.

* Return the signal end time to measure :term:`mB amplitudes <magnitude,
  broadband body-wave (mB_BB)>`:

  .. code-block:: properties

     min(D * 11.5, 60)

  where function :py:func:`min()` returns the minium from two parameters to,
  epicentral distance, :envvar:`D`, is a variable and '\*' and '\+' are
  operators.

  In this example, the minimum time from either epicentral distance in degree
  times 11.5 s/deg or 60 s is returned if epicentral distance is available. If
  epicentral distance is not available, 60 s is returned hence being the default.

* Return the signal end time to measure amplitudes ending before the arrival of
  surface waves or 150 s:

  .. code-block:: properties

     min(OT + D * 35, 150)

  where the epicentral distance, :py:envvar:`D`, is multiplied by 35 s/deg. The
  relative origin time, :py:envvar:`OT`, is either added in order to obtain the
  time relative to trigger time.
  The minimum of this value and 150 s is returned by :py:func:`min()`. This
  means that 150 s it the default in case epicentral distance is not available.

* Return the time difference as the minimum of predicted arrivals of S-waves
  adding 10 s or 150 s:

  .. code-block:: properties

     min(tt(S) + 10, 150)

  where the function :py:func:`tt()` returns the relative travel time of the
  argument, here the S phase, and '\+' is an operator.

  In this example the minimum time from either the relative arrival time of S
  phase plus 10 s or 150 s is returned.

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
values and function provide values based on a parameter given within
parentheses like :py:func:`tt()`. Find below their individual descriptions.

.. _sec-time-functions:

Functions
---------

.. py:function:: max(arg1, arg2)

   Calculates the maximum of two values. If one value is unset then the other
   value is returned. If both values are unset then the result is unset, too.

   :param arg1: First value to consider
   :param arg2: Second value to consider

.. py:function:: min(arg1, arg2)

   Calculates the minimum of two values. If one value is unset then the other
   value is returned. If both values are unset then the result is unset, too.

   :param arg1: First value to consider
   :param arg2: Second value to consider


.. py:function:: tt(phase)

   Calculates the travel-time of the given phase **relative to the trigger time**.
   The result is unset if the travel time cannot be computed.

   :param phase: Phase name available with the define travel-time interface
                 and profile.


.. py:function:: arr(phase, acceptAll)

   Extracts the travel times of actually used arrivals **relative to the trigger
   time**. The arrivals with the given phase code must exist.

   :param phase: Phase code of the arrival. The arrival must exist and the
                 sensor location of the associated pick must match the sensor
                 location of the target object.
   :param acceptAll: Whether to accept all arrivals or only manually
                     revised arrivals. The default is 'true' if not
                     given. Allowed is either 'true' or 'false'. If
                     'true' is given, then either the evaluation mode
                     of the origin or the evaluation mode of the pick
                     must be 'manual'.


.. _sec-time-operators:

Operators
---------

If either of the operands is unset then the result will be also unset.

* \+ : addition
* \- : subtraction
* \* : multiplication
* \/ : division
* \^ : power / exponentiation
* \|\| : logical OR which returns the first set value if any
* \|. \| : absolute value
* \% : modulo


.. _sec-time-variables:

Variables
---------

Variables can take the value *unset* when required information is not available.
The behaviour of :ref:`operators <sec-time-operators>` and
:ref:`functions <sec-time-functions>` with variables of value *unset* depends
on the operator and function itself.

.. envvar:: OT

   Relative origin time as difference from origin to trigger
   (originTime - triggerTime). For most amplitude types, the
   trigger is the measured or the predicted arrival time of the P phase.

   Unit: ``s``

.. envvar:: D

   Unit: ``km``

   :term:`Epicentral distance <distance, epicentral>`

   Unit: ``deg``

.. envvar:: d, R

   :term:`Epicentral distance <distance, epicentral>`

   Unit: ``km``

.. envvar:: H

   :term:`Hypocentral distance <distance, hypocentral>`

   Unit: ``deg``

.. envvar:: h

   :term:`Hypocentral distance <distance, hypocentral>`

   Unit: ``km``

.. envvar:: Z

   :term:`origin` depth

   Unit: ``km``

