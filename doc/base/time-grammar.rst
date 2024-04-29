.. _time-formats:

************
Time Formats
************

In |scname| all absolute times of raw :term:`miniSEED` waveforms and
:ref:`SeisComP objects <api-datamodel-python>` like event parameters, inventory,
etc. are natively given and assumed in UTC. For reading and writing absolute
times a range of formats are supported.

Historically, the only time format native to |scname| would be

.. code-block:: properties

   YYYY-MM-DD hh:mm:ss.ssssss

As a consequence of the space between *DD* and *hh* this time string needs
to be enclosed by quotes or double quotes. Otherwise, the time string meant to
be a single string only would be interpreted as two strings. Example:

.. code-block:: sh

   scevtls -d localhost --begin '2024-01-01 12:00:00'

Depending on the module, trailing parameters could be omitted or not for
shortening the arguments but the general rules were initially unclear.

More flexibility has been introduced with SeisComP in version 6.4.0 with the
new C++ and Python function:

C++:

.. code-block:: c

   Seiscomp::Core::Time::fromString()

Python:

.. code-block:: python

   seiscomp.core().time().fromString()

In adaptation to the norm :cite:t:`iso_8601` a subset of strings is now
available. Supported formats are

* Calender dates,
* Ordinal dates,
* Times (24-hour clock system) in combination with calender or ordinal dates.

Currently unsupported are:

* Week dates,
* Times without dates,
* Time zone offset designators,
* Local times.

.. csv-table:: List and examples of supported time string formats
   :widths: 30 30 40
   :header: Implementation, Time string format, Examples: all actual times are identical
   :align: left
   :delim: ;

   %FT%T.%fZ    ; YYYY-MM-DDThh:mm:ss.ssssssZ ; 2025-01-01T00:00:00.000000Z
   %FT%T.%f     ; YYYY-MM-DDThh:mm:ss.ssssss  ; 2025-01-01T00:00:00.000000
   %FT%TZ       ; YYYY-MM-DDThh:mm:ssZ        ; 2025-01-01T00:00:00Z
   %FT%T        ; YYYY-MM-DDThh:mm:ss         ; 2025-01-01T00:00:00
   %FT%R        ; YYYY-MM-DDThh:mm            ; 2025-01-01T00:00
   %FT%H        ; YYYY-MM-DDThh               ; 2025-01-01T00
   %Y-%jT%T.%f  ; YYYY-DDDThh:mm:ss.ssssss    ; 2025-001T00:00:00.000000
   %Y-%jT%T     ; YYYY-DDDThh:mm:ss           ; 2025-001T00:00:00
   %Y-%jT%R     ; YYYY-DDDThh:mm              ; 2025-001T00:00
   %Y-%jT%H     ; YYYY-DDDThh                 ; 2025-001T00
   %F %T.%f (*) ; YYYY-MM-DD hh:mm:ss.ssssss  ; '2025-01-01 00:00:00.000000'
   %F %T    (*) ; YYYY-MM-DD hh:mm:ss         ; '2025-01-01 00:00:00'
   %F %R    (*) ; YYYY-MM-DD hh:mm            ; '2025-01-01 00:00'
   %F %H    (*) ; YYYY-MM-DD hh               ; '2025-01-01 00'
   %F           ; YYYY-MM-DD                  ; 2025-01-01
   %Y-%j        ; YYYY-DDD                    ; 2025-001
   %Y           ; YYYY                        ; 2025

(*): Time strings with spaces must be enclosed by quotes or double quotes for
protecting the space.

.. csv-table:: List of format symbols used in table of time string formats
   :widths: 10 90
   :header: Symbol, Description
   :align: left
   :delim: ;

   YYYY;   4-digit year
   MM;     2-digit month starting with 01
   DD;     1- or 2-digit day of the month starting with 01
   DDD;    1-, 2- or 3-digit day of year starting with 001
   hh;     1- or 2-digit hour of the day starting with 00
   mm;     1- or 2-digit minute of the hour starting with 00
   ss;     1- or 2-digit second of the minute starting with 00
   ssssss; 1-6 digits decimal fraction of a second with 0
   Z;      Zone designator for the zero UTC offset

Durations can be formed from start and end dates and times combined by tilde(~).
Example:

.. code-block:: sh

   scart -dsEv -t 2024-01-01T12~2024-01-01T12:15:30.2Z


.. _time-grammar:

************
Time Grammar
************

Amplitudes are measured on waveforms by modules such as :ref:`scautopick`,
:ref:`scamp` or :ref:`scolv` for computing magnitudes, e.g., by :ref:`scmag` or
:ref:`scolv`. The principles are outlined in the concepts section
:ref:`concepts_magnitudes`.

The time windows for measuring noise and signal amplitudes are given by their
respective begin and end values. These window parameters are configured as
global binding parameters specifically for a particular amplitude type, let's
say :ref:`ML <global_ml>`:

.. code-block:: properties

   amplitudes.ML.noiseBegin
   amplitudes.ML.noiseEnd
   amplitudes.ML.signalBegin
   amplitudes.ML.signalEnd

**The configured values are added to trigger time**, *triggerTime*, which
corresponds to the arrival of P waves for most applications. *triggerTime* is
hence the sum of *originTime* and *relativeTriggerTime*.

Example:

.. math::

   absoluteSignalEnd =\ &originTime + relativeTriggerTime + amplitudes.ML.signalEnd \\
                     =\ &originTime - relativeOriginTime + amplitudes.ML.signalEnd \\
                     =\ &triggerTime + amplitudes.ML.signalEnd

.. important::

   Where values of time-window parameter values shall be estimated from distance
   measures such as :envvar:`D` or :envvar:`h`, the relative origin time,
   :envvar:`OT`, must be added to get the actual difference to *triggerTime*. In
   contrast, :py:func:`tt()` returns the time difference to :envvar:`OT`.
   Therefore, :py:func:`tt()` does not need to be corrected for origin time.

In |scname| the configuration of the begin and end values is supported in the
Bindings Panel of :ref:`scconfig`: For global bindings parameters you may create
an amplitude-type profile with the name of the amplitude type, e.g., ML. The
profile allows you to configure the parameters.
You may set the values as a combination of :ref:`functions <sec-time-functions>`,
:ref:`operators <sec-time-operators>`, :ref:`variables <sec-time-variables>` and
constant values. The combination of them allows setting up a flexible time
grammar for time windows. You may further use parentheses *()* to apply
operations within the parentheses before operations outside of parentheses.

If the result of the final evaluation of the parameter value is *unset*, e.g.,
because required information are not available, then the processing receives an
error and the amplitude will not be computed.


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

   Calculates the travel-time of the given phase **w.r.t. relative origin
   time, :py:envvar:`OT`**. The result is unset if the travel time cannot be
   computed. The travel times are computed based on the travel-time interface
   and model defined in :confval:`amplitudes.ttt.interface` and
   :confval:`amplitudes.ttt.model`, respectively.

   :param phase: Phase name available with the defined travel-time interface
                 and model.


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

