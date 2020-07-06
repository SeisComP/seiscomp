.. _coding_conventions:

******************
Coding Conventions
******************

Code Style
**********

Formatting
==========

For C++ always use tab indentation. In case of line break white spaces have to be
used to fill the space. The recommended tab width is 4 characters.

.. code-block:: c++

   // Tabs are visualized with '>' and spaces with '.'
   int myFunction() {
   >   int a = 5;
   >   if ( a > 5 ) {
   >   >   SEISCOMP_DEBUG("A is greater than 5. Its current value is %d",
   >   >   ...............a);
   >   return a;
   }

C++ code is (or should be) written with the following code style:

.. code-block:: c++

   /***************************************************************************
    * Copyright (C) ...                                                       *
    *                                                                         *
    * All rights reserved.                                                    *
    * Contact: <contact>                                                      *
    *                                                                         *
    * Author: <name>                                                          *
    * Email: <email>                                                          *
    *                                                                         *
    * GNU Affero General Public License Usage                                 *
    * This file may be used under the terms of the GNU Affero                 *
    * Public License version 3.0 as published by the Free Software Foundation *
    * and appearing in the file LICENSE included in the packaging of this     *
    * file. Please review the following information to ensure the GNU Affero  *
    * Public License version 3.0 requirements will be met:                    *
    * https://www.gnu.org/licenses/agpl-3.0.html.                             *
    *                                                                         *
    * Other Usage                                                             *
    * Alternatively, this file may be used in accordance with the terms and   *
    * conditions contained in a signed written agreement between you and      *
    * gempa GmbH.                                                             *
    ***************************************************************************/

   #ifndef NAMESPACE_LIB_FILENAME_H
   #define NAMESPACE_LIB_FILENAME_H


   #include <math.h>

   class Complex {
      public:
         Complex(double re, double im)
         : _re(re), _im(im) {}

         double modulus() const {
             return sqrt(_re * _re + _im * _im);
         }

         <template typename T>
         void set(T r, T i) {
             _re = r;
             _im = i;
         }

       private:
           double _re;
           double _im;
   };


   void bar(int i) {
       static int counter = 0;
       counter += i;
   }


   namespace Foo {
   namespace Bar {


   void foo(int a, int b) {
       for ( int i = 0; i < a; ++i ) {
           if (  i < b )
               bar(i);
           else {
               bar(i);
               bar(b);
           }
       }
   }


   } // namespace Bar
   } // namespace Foo

   #endif


File layout
===========

* See above header example
* **Trailing newline**: use a newline at the end of each source file.
* **Include guards**: Use include guards in your header files instead of #pragma once:

  .. code-block:: c++

     #ifndef NAMESPACE_LIB_FILENAME_H
     #define NAMESPACE_LIB_FILENAME_H
     ...
     #endif


Name layout
===========

Use descriptive names and camel capping. That means the name of the element
starts with the case given in the following table. Every concatenated word
starts with an uppercase letter (e.g. myDescriptiveElementName).

For straight enumerations where values start with 0 a quantity name should be
defined that describes the upper bound for all valid enumeration values. Its
name should be prepended by two letters describing the enumeration name and an
underscore.

Look at the class example above for guidance.

+-----------------------------+----------------------+--------------------------------------+
| Type                        | Case of first letter | Comment                              |
+=============================+======================+======================================+
| variable                    | lowercase            |                                      |
+-----------------------------+----------------------+--------------------------------------+
| function                    | lowercase            |                                      |
+-----------------------------+----------------------+--------------------------------------+
| structure                   | uppercase            |                                      |
+-----------------------------+----------------------+--------------------------------------+
| class                       | uppercase            |                                      |
+-----------------------------+----------------------+--------------------------------------+
| member variables:                                                                         |
+-----------------------------+----------------------+--------------------------------------+
| \- public                   | lowercase            | starts without underscore            |
+-----------------------------+----------------------+--------------------------------------+
| \- protected                | lowercase            | starts with underscore               |
+-----------------------------+----------------------+--------------------------------------+
| \- private                  | lowercase            | starts with underscore               |
+-----------------------------+----------------------+--------------------------------------+
| methods                     | lowercase            |    no                                |
+-----------------------------+----------------------+--------------------------------------+
| static methods              | uppercase            |    no                                |
+-----------------------------+----------------------+--------------------------------------+
| inline methods and          | lowercase            | sourced out into separate .ipp file  |
| templates                   |                      | with same name as the header file    |
+-----------------------------+----------------------+--------------------------------------+
| enumeration                 | uppercase            | elements are written all uppercase   |
+-----------------------------+----------------------+--------------------------------------+
| documentation and           | -                    | use Doxygen                          |
| comments                    |                      |                                      |
+-----------------------------+----------------------+--------------------------------------+

File naming
===========

All source and header files are named with lowercase letters. The suffix of a
source file is ".cpp" while for a header file it is ".h". The name of files
that contain a class has to correspond with the class name. For other files,
a descriptive name has to be provided (e.g. protocol.h instead of pro.h).


Programming Guidelines
**********************

Return values
=============

While designing methods or functions these rules about return values should be kept in mind:

- Functions returning an int or related types as status: 0 means success;
  everything else is an error [1]_
- Functions returning a pointer:
  0 (or :code:`nullptr`) means an error and of course an
  invalid pointer [1]_
- Functions returning a class object can throw an exception in case of an error.
  This is not obligatory and should be used with care.

  **Example**: std::string myMethod();

Exception specifications
========================

According to [2]_ dynamic exception specifications are considered or proposed
as deprecated feature and not recommended [3]_. Don't use them in declaring a function prototype.

.. code-block:: c++

   // Don't use that
   int foo() throw(ValueException);

   // Just declare it without an exception specification
   int foo();


Null pointer
============

Use either 0 or the :code:`nullptr` keyword of C++11.
Check a null pointer with implicit boolean conversion.

.. code-block:: c++

   if ( !ptr )
       do_something();

rather than

.. code-block:: c++

   if ( ptr == 0 )
       do_something();

or

.. code-block:: c++

   if ( ptr == NULL )
       do_something();

Virtual Functions
=================

Virtual functions are a fundamental concept of polymorphic classes. Virtual
functions will be overwritten in derived classes to implement specific
behaviour. It can happen that the signature of the virtual function in the
base class changes but derived classes do not follow this change.

This causes in erroneous behaviour as the derived virtual function will not
be called as desired. What is even worse is that this mismatch of signatures
is hard to find and to debug.

Fortunately C++11 introduces the long awaited override keyword which declares
that a virtual function of a derived class intends to override the virtual
function with the same name of the base class. If both signatures do not match,
the compiler will throw an error.

.. code-block:: c++

   class Base {
       virtual void print() {
           cout << "Base class" << endl;
       }
   }

   class Derived : public Base {
       virtual void print() {
           cout << "Derived class" << endl;
       }
   }

If we change the signature of print to take an additional parameter then
the derived method will not be called anymore.

.. code-block:: c++

   class Base {
       virtual void print(ostream &os) {
           os << "Base class" << endl;
       }
   }

Adding the override keyword will force the compiler to check both signatures
for equality.

.. code-block:: c++

   class Derived : public Base {
       void print() override {
           os << "Derived class" << endl;
       }
   }

This code above will throw an error during compilation and one has to adapt
the signature of the function.

Use the override keyword whenever you implement a virtual function in derived
classes.

.. [1] http://www.stroustrup.com/bs_faq2.html#null
.. [2] http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3051.html
.. [3] http://www.gotw.ca/publications/mill22.htm
