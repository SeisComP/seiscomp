.. _build:

***********************
Getting the Source Code
***********************

.. caution::

   For production systems only
   :ref:`install the officially released packages <installation-packages>`
   from :cite:t:`seiscomp`, :cite:t:`gempa` or compile from the corresponding
   release tags in this repository.

The |scname| software collection is distributed among several repositories.
For more information about compilation and build configuration head over to
:cite:t:`seiscomp-github`.

For building a complete |scname| distribution checkout all repositories using
the following script:

.. code-block:: sh

   #!/bin/bash

   if [ $# -eq 0 ]
   then
       echo "$0 <target-directory>"
       exit 1
   fi

   target_dir=$1
   repo_path=https://github.com/SeisComP

   echo "Cloning base repository into $1"
   git clone $repo_path/seiscomp.git $1

   echo "Cloning base components"
   cd $1/src/base
   git clone $repo_path/seedlink.git
   git clone $repo_path/common.git
   git clone $repo_path/main.git
   git clone $repo_path/extras.git

   echo "Cloning external base components"
   git clone $repo_path/contrib-gns.git
   git clone $repo_path/contrib-ipgp.git
   git clone https://github.com/swiss-seismological-service/sed-SeisComP-contributions.git contrib-sed

   echo "Done"

   cd ../../

   echo "If you want to use 'mu', call 'mu register --recursive'"
   echo "To initialize the build, run 'make'."


.. _compiling_source:

***********************************
Compiling |scname| from Source Code
***********************************

To build from source you will need to clone from one or more repositories as
described in :ref:`build`.

Before building, **install all the dependencies**,
as described below in :ref:`build_dependencies`.

The easiest way to compile |scname| is to use the :file:`Makefile` file
provided which creates a build directory inside the source tree.

Perform the following steps:

* Clone all required repositories (see above)
* Run :file:`make`
* Configure the build
* Press 'c' as long as 'g' appears
* Press 'g' to generate the Makefiles
* Enter the build directory and run :file:`make install`

By default all files are installed under :file:`$HOME/seiscomp`.
This location can be changed with `cmake` or with its front end `ccmake`.

Basically the build directory can live anywhere. The following steps create
a build directory, configure the build and start it:

.. code-block:: sh

   $ mkdir sc-build
   $ cd sc-build
   $ ccmake /path/to/sc-src
   # Configure with ccmake
   $ make install


.. _build_dependencies:

Software dependencies
=====================

For compiling the |scname| sources the development software packages must be
installed by Linux system commands such as :program:`apt` or :program:`dnf`.
The required packages are (Debian/Ubuntu package names):

* flex
* g++
* git
* make
* swig
* cmake-gui
* cmake-curses-gui
* libcrypto-dev
* libboost-all-dev
* libbson-dev
* libfl-dev
* libssl-dev
* libxml2-dev
* openjdk-21-jre-headless
* gsoap
* libgsoap-dev
* libnetcdf-dev
* libv4l-dev
* libjpeg-turbo8-dev
* libshp-dev
* libusb-1.0-0-dev
* gfortran
* librrd-dev
* liblapack-dev

Depending on the |scname| modules to be built the optional packages are
(Debian/Ubuntu package names):

* libqwt-qt5-dev
* libqt5svg5-dev
* libqt5webkit5-dev
* libqt5webengine5
* qtwebengine5-dev
* qtwebengine5-dev-tools
* libmysql++-dev
* libmariadb-dev
* libmariadb-dev-compat
* libmysqlclient-dev
* postgresql-server-dev-16
* libpq-dev
* libsqlite3-dev
* libncurses-dev
* qttools5-dev
* python3-dev
* python3-twisted
* python3-dateutil
* python3-numpy (required if Numpy support is enabled which is also the default configuration)
* qtbase5-dev

.. note::

   * The package names may vary depending on version of the Linux distribution.
   * As of |scname| in version 5.0.0 support for Python 2 is dropped and
     Python 3 has become the default.
     The Python development libraries are required if Python wrappers should be
     compiled which is the default configuration. The development files must
     match the used Python interpreter of the system.


.. _compile_macos:

Compiling |scname| for MacOS
============================

Although |scname| has been developed, compiled and tested on Linux systems,
users have compiled |scname| on MacOS.
The procedures are given online by external sources :cite:p:`macos-compile`.
Please contact the managers of these sources for any requests.
