.. _build:

***********************************
Compiling SeisComP from source code
***********************************

To build from source you will need to clone from one or more repositories.
Here we describe the simplest case only.

.. note ::

   For production systems only use the official releases
   from `SeisComP`_, `gempa GmbH`_ or compile from the corresponding release tags in this repository.

Before building, **install all the dependencies**,
as described below in :ref:`build_dependencies`.

The easiest way to compile SeisComP is to use the :file:`Makefile.cvs` file
provide, which creates a build directory inside the source tree.

.. code-block:: sh

		$ make -f Makefile.cvs
		$ cd build
		$ make
		$ make install

By default all files are installed under :file:`$HOME/seiscomp`.
This location can be changed with `cmake` or with its front end `ccmake`.

Basically the build directory can live anywhere. The following steps create
a build directory, configure the build and start it:

.. code-block:: sh

   $ mkdir sc-build
   $ cd sc-build
   $ ccmake /path/to/sc-src
   # Configure with ccmake
   $ make
   $ make install

Step-by-step instructions
=========================

1. Check out SeisComP source code from Github

   .. code-block:: sh

      sysop@host:~$ git clone https://github.com/SeisComP/seiscomp.git sc-src  # FIXME
      sysop@host:~$ cd sc-src
      sysop@host:~/sc-src$


2. Change into the desired branch (if not master) or checkout tag

   .. code-block:: sh

      sysop@host:~/sc-src$ git checkout release/jakarta/2017.124.02

3. Configure the build.

   SeisComP uses `cmake` as build environment. For users that are not experienced
   with `cmake` it is recommended to use `ccmake`, an ncurses frontend which is launched
   by the default :file:`Makefile.cvs`.

   .. code-block:: sh

      sysop@host:~/sc-src$ make -f Makefile.cvs

   This will bring up the `cmake` frontend. Press `c` to configure the build initially.
   If `cmake` is being used, the variables can be passed as command line options:

   .. code-block:: sh

       sysop@host:~/sc-src/build$ cmake -DCMAKE_INSTALL_PREFIX=/path/to/install/dir ..

   With `ccmake` some components can be activated and deactivated such as database
   backends you want to compile support for. The default just enables MySQL. Once done
   with options, press `c` again to apply the changes. If everything runs without errors,
   press `g` to generate the Makefiles. `ccmake` will quit if the Makefiles have been
   generated:

   .. code-block:: sh

      *** To build the sources change into the 'build' directory and enter make[ install] ***
      sysop@host:~/sc-src$ cd build
      sysop@host:~/sc-src/build$ make

   If `make` finished without errors, install SeisComP with

   .. code-block:: sh

      sysop@host:~/sc-src/build$ make install

   All files are then installed under :file:`~/seiscomp` or
   under the directory you have
   specified with ```CMAKE_INSTALL_PREFIX```.


.. _build_dependencies:

Dependencies
============

To compile the sources the following development packages are required (Redhat/CentOS package names):

- flex
- libxml2-devel
- boost-devel
- openssl-devel
- ncurses-devel
- mysql-devel
- postgresql-devel (optional)
- python-devel
- m2crypto-devel
- qt4-devel

References
==========

.. target-notes::

.. _`SeisComP` : https://www.seiscomp.de/downloader/
.. _`gempa GmbH` : https://www.gempa.de
