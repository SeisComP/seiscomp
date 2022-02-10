.. _unittests:

************
Unit Testing
************

Introduction
============

From Wikipedia:

  In computer programming, unit testing is a software testing method by which
  individual units of source code, sets of one or more computer program modules
  together with associated control data, usage procedures, and operating
  procedures, are tested to determine whether they are fit for use. [#WPUT]_

This chapter targets programmers, either ones contributing to |scname| or
adding their extended set of modules / libraries.

Since most of the |scname| code is written in C++, this chapter focuses on
C++ unit tests. For C++, we have evaluated three unit test frameworks:

* CppUnit
* Google Test
* Boost Test

We found that Boost Test is the most appropriate, flexible and easy to
understand unit test framework. Another important fact was the availability of
Boost Test on all major Linux distributions via their package managers. That
|scname| makes already use of other Boost libraries was the icing on the cake.

So this chapter is about integrating unit tests into |scname| with the Boost Test
library.

Apart from the availability of the Boost test libraries, cmake with version
2.8.0 or greater is also required.

Preparations
============

With CMake it is easy to setup arbitrary tests. To make it even easier, we
added a shortcut to the CMake macro :code:`SC_ADD_LIBRARY`. It collects all .cpp
files in the directory :code:`${CMAKE_CURRENT_SOURCE_DIR}/test/{libraryname}`
and creates tests from them.

An example is the |scname| core library. It is located at
:code:`src/base/common/libs/seiscomp`. Following the above rule, the test files
shall be located in :code:`src/base/common/libs/seiscomp/test/core/*.cpp`. For each
found source file, the macro will create a test with the same name and link
its executable against the library the tests are built for.

.. note::

   The recommend test file naming is :code:`{class}_{function}.cpp`.

Execution
=========

Compiling and running tests is as easy as running

.. code-block:: sh

   make test

in the build directory. Thats it.

Test implementation
===================

The following section shows an example of a simple but in many cases sufficient
test module. This example can be used as a template for an |scname| unit test.

.. code-block:: cpp

   #define SEISCOMP_TEST_MODULE [TestModuleName]
   #include <seiscomp/unittest/unittests.h>
   #include <seiscomp/core/datetime.h>

   BOOST_AUTO_TEST_SUITE([domain]_[namespace]_[module])

   BOOST_AUTO_TEST_CASE(addition) {
       Seiscomp::Core::TimeSpan k = 5, l = 7;
       BOOST_CHECK(k + l  == Seiscomp::Core::TimeSpan(12));
   }

   BOOST_AUTO_TEST_CASE(dummy_warning) {
       Seiscomp::Core::Time tNegativeUsec(3000, -789);
       BOOST_WARN_EQUAL(tNegativeUsec.seconds(), 3000);
       BOOST_WARN_EQUAL(tNegativeUsec.microseconds(), -789);
   }

   BOOST_AUTO_TEXT_SUITE_END()

That was simple, wasn't it? For more complex examples and usages, visit the
Boost Unit Test Framework documentation [#b1]_. Furthermore you have to link
your test executable against :code:`${Boost_unit_test_framework_LIBRARY}` and
:code:`seiscomp_unittest`. A simple CMakeLists.txt file looks as follows:

.. code-block:: cmake

   ADD_EXECUTABLE(test_mylib_myfeature feature.cpp)
   SC_LINK_LIBRARIES_INTERNAL(test_mylib_myfeature unittest)
   SC_LINK_LIBRARIES(test_mylib_myfeature ${Boost_unit_test_framework_LIBRARY})

   ADD_TEST(
       NAME test_mylib_myfeature
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
       COMMAND test_mylib_myfeature
   )

Warning levels
--------------

In Boost Test there are **3 different levels** to handle the results.

- Warning: WARN [#b2]_
  The error is printed and the error counter **is not** increased.
  The test execution will not be interrupted and will continue to execute other
  test cases.

- Error: CHECK
  The error is printed and the error counter **is** increased.
  The test execution will not be interrupted and will continue to execute other
  test cases.

- Fatal error: REQUIRE
  The error is printed and the error counter **is** increased.
  The test execution will be aborted.


Tools
-----

+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
|                           Tool                            | what it do (short info)                   | example                                                   | return value                |
+===========================================================+===========================================+===========================================================+=============================+
| BOOST_<LEVEL>_EQUAL(left, right)                          | left == right                             | BOOST_<LEVEL>_EQUAL(4,5)                                  |         true or false       |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>(predicate)                                  | predicate is true                         | BOOST_<LEVEL>(4+5 == 3+3+3)                               | if false, both results show |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_EXCEPTION(expression, exception, predicate) | is exception equal to throw               | BOOST_<LEVEL>_EXCEPTION(myVector(-5), out_of_range, true) | if false, show the exactly  |
|                                                           | exception of expression                   |                                                           |          exception          |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_CLOSE(left, right, tolerance)               | (left - right) <= tolerance               | BOOST_<LEVEL>_CLOSE(5.3, 5.29,0.1)                        |    if false, the exactly    |
|                                                           | tolerance in percentage                   |                                                           |      tolerance is show      |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_LT(left, right)                             | left < right                              | BOOST_<LEVEL>_LT(6,8)                                     |         true or false       |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_GT(left, right)                             | left > right                              | BOOST_<LEVEL>_GT(78,90)                                   |         true or false       |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_GE(left, right)                             | left >= right                             | BOOST_<LEVEL>_GE(54,10)                                   |         true or false       |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_LE(left, right)                             | left <= right                             | BOOST_<LEVEL>_LE(10,2)                                    |         true or false       |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_NE(left, right)                             | left != right                             | BOOST_<LEVEL>_NE(1,0)                                     |         true or false       |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_ERROR("message")                                    | increasing error counter and show message | BOOST_ERROR("There was a problem")                        |            message          |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_TEST_MESSAGE("message") [#b3]_                      | show message                              | BOOST_TEST_MESSAGE("Your ad can be placed here")          |            message          |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+
| BOOST_<LEVEL>_THROW(expression,exception)                 | perform an exception perception check     | BOOST_<LEVEL>_THROW(myVector(-2),out_of_range)            |         true or false       |
+-----------------------------------------------------------+-------------------------------------------+-----------------------------------------------------------+-----------------------------+

For more tools and information about the Boost unit test tools see [#b4]_.

Test output
===========

The test binary will exit with an error code of 0 if no errors were detected
and the tests finished successfully. Any other result code represents failed
tests.

An example output looks like this:

.. code::

   Running tests...
   Test project /home/sysop/seiscomp/build
       Start 1: stringtoxml
   1/4 Test #1: stringtoxml ......................***Failed    0.03 sec
       Start 2: datetime_time
   2/4 Test #2: datetime_time ....................   Passed    0.03 sec
       Start 3: xml_test
   3/4 Test #3: xml_test .........................   Passed    0.03 sec
       Start 4: datetime_timespan
   4/4 Test #4: datetime_timespan ................   Passed    0.03 sec

   75% tests passed, 1 tests failed out of 4

   Total Test time (real) =   0.17 sec

   The following tests FAILED:
             1 - stringtoxml (Failed)
   Errors while running CTest
   Makefile:61: recipe for target 'test' failed
   make: *** [test] Error 8

.. [#WPUT] https://en.wikipedia.org/wiki/Unit_testing
.. [#b1] As of Boost version 1.46, it is located at http://www.boost.org/doc/libs/1_46_0/libs/test/doc/html/index.html
.. [#b2] *to see the warnings use the instruction:* **boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_warnings);**
.. [#b3] *to see the messages use the instruction:* **boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_messages);**
.. [#b4] As of Boost version 1.46, it is located at http://www.boost.org/doc/libs/1_46_0/libs/test/doc/html/utf.html
