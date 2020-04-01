.. _tutorials_postinstall:

**********************
Installation on Ubuntu
**********************

You will ...

* make a basic SeisComP installation.

:Pre-requisites for this tutorial:
* None

:Afterwards/Results/Outcomes:
* Run a SeisComP executable.
* Run a SeisComP GUI program.

:Time range estimate:
* 10-15 minutes.

------------

Get your native or virtual Ubuntu ready
=======================================

The following documentation refers to Ubuntu 18.04,
but the steps for other Ubuntu versions are similar.

#. Add a new user.
   (This is not mandatory; you can install under an existing user
   directory. Creating a new user is recommended as it allows an easy cleanup of the system later simply by
   removing the new user if needed.)
   Throughout our documentation, this user is called `sysop`.

   .. code-block:: bash

      $ sudo adduser sysop
      $ sudo addgroup admin
      $ sudo usermod -a -G admin,adm,audio sysop

#. Check the size and the architecture: ::

     $ df -h
     $ cat /etc/issue
     $ uname -m

   Compare the available disk space with the requirements given in
   the :ref:`installation` section.
   If 'uname' shows 'i686', you have a 32-bit system;
   if you see 'x86_64', you have 64-bit.

Download SeisComP binary package, maps and documentation
========================================================

3. Download the appropriate SeisComP binary package taking into
   account your Linux distribution and the architecture.
   Get the package from
   `www.seiscomp3.org <https://www.seiscomp3.org/downloader>`_ -
   for Ubuntu and other Linux flavours such as CentOS and Debian.

#. From the same site you should also download

   * maps, e.g. https://www.seiscomp3.org/downloader/seiscomp3-jakarta-maps.tar.gz
   * documentation, e.g. for SeisComP3 in version jakarta-2018.327:
     https://www.seiscomp3.org/downloader/seiscomp3-jakarta-2018.327-doc.tar.gz.

   Make sure, the documentation matches your SeisComP version.

#. Untar the :file:`seiscomp*` files (binary package, maps and documentation)
   you will find in your home or downloads directory ::

     $ cd
     $ tar xzf seiscomp3-jakarta-2018.327.15-ubuntu18.04-x86_64.tar.gz
     $ tar xzf seiscomp3-jakarta-maps.tar.gz
     $ tar xzf seiscomp3-jakarta-2018.327-doc.tar.gz
     $ ls seiscomp
     bin  etc  include  lib  man  sbin  share

#. Install all dependencies needed and prepare the environment.

   * This should be automatic for most distributions.
     Simply run the install script: ::

       $ ~/seiscomp/bin/seiscomp install-deps base
       Distribution: Ubuntu 18.04

     This will generally prompt for your user's password to allow `sudo` to
     install packages on your system.

   * On Ubuntu 18, Python 3 is installed, but not Python.
     Get it first::

       $ sudo apt-get install python libqtgui4

   * Alternatively, for Ubuntu 16.04 and Mint 18:

     .. code-block:: bash

        $ sudo apt-get update
        $ sudo apt-get install libxml2 libboost-filesystem1.58.0
        libboost-iostreams1.58.0 libboost-thread1.58.0 libboost-program-options1.58.0
        libboost-regex1.58.0 libboost-signals1.58.0 libboost-system1.58.0 libssl1.0.0
        libncurses5 libmysqlclient20 libpython2.7 python-m2crypto mysql-server
        mysql-client libqtgui4 libqt4-xml


#. *OPTIONAL*. You may set some environment variables.
   For bash users, print the environment variables and copy them to your
   :file:`.bashrc`

   .. code-block:: bash

      $ seiscomp/bin/seiscomp print env
      export SEISCOMP_ROOT=/home/sysop/seiscomp
      export PATH=/home/sysop/seiscomp/bin:$PATH
      export LD_LIBRARY_PATH=/home/sysop/seiscomp/lib:$LD_LIBRARY_PATH
      export PYTHONPATH=/home/sysop/seiscomp/lib/python:$PYTHONPATH
      export MANPATH=/home/sysop/seiscomp/share/man:$MANPATH
      export LC_ALL=C
      source /home/sysop/seiscomp/share/shell-completion/seiscomp.bash

   The path to your home directory will likely differ from
   `/home/sysop` as shown above.
   Cut and paste your own output from the
   `seiscomp print env` command, not what is shown here.
   Edit your :file:`.bashrc` file, inserting the commannd from the output. ::

     $ vi .bashrc

   Then reload the contents of :file:`.bashrc` in your current environment ::

     $ source ~/.bashrc

   After this, you won't have to type `~/seiscomp/bin/seiscomp` as
   the `seiscomp` command will be added to your shell's path.

   .. hint::

      If, when you attempt to run a SeisComP command such as `scconfig` or `scolv`,
      you receive an error message like::

        scconfig: command not found

      then the most likely explanation is that you have not set your SeisComP
      environment variables correctly.

      Run the `seiscomp` command with the full path to
      where you installed.
      The seven lines of output are not actually run by the 'seiscomp print env'
      command; you need to cut and paste them into your shell to run them.
      You can also add these to your :file:`.bashrc`, :file:`.profile`,
      or equivalent file with
      commands to be run every time you log in.


#. Database. For a MySQL installation: ::

     $ ~/seiscomp/bin/seiscomp install-deps mysql-server

   Also, for better performance with a MySQL database,
   adjust the memory pool size and restart MySQL, as described under
   "SQL configuration" in the :ref:`installation` section.

   For PostgreSQL, also see the detailed :ref:`installation` instructions.

   .. warning::

     For Ubuntu 18.04, take care with MySQL installation.
     Before the next step, you must set a root password *for MySQL or MariaDB*
     (not the Linux root password!). See the Internet, or the SeisComP forum
     `thread <https://forum.seiscomp3.org/t/upgraded-to-ubuntu-18-04-and-i-broke-my-seiscomp3/1139>`_
     (for logged-in forum members).


#. Run `seiscomp setup` and enter your preferred IDs and password. For the other
   fields, you can always accept the default values. ::

     $ seiscomp setup

   You should enter an appropriate short name (without spaces) for Agency ID and Datacenter ID.
   These are used for Arclink and Seedlink, and in the information describing data model objects such as origins and events.

#. The `seiscomp` command is a wrapper, which controls the SeisComP modules.
   See :ref:`system-management`.
   Run something by typing seiscomp followed by a command::

     $ ~/seiscomp/bin/seiscomp help
     Available commands:
      install-deps
      setup
      shell
      enable
      disable
      print
      help

     Use 'help [command]' to get more help about a command

#. Start spread and :program:`scmaster`.
   As described in the :ref:`overview`, these are needed for
   communication between the SeisComP database and the individual
   SeisComP modules. ::

     $ seiscomp start scmaster spread
     starting spread
     starting scmaster

#. Add license files.
   Use of the SeisComP3 GUI programs requires your agreement to the
   SeisComP `public license <http://seiscomp3.org/license.html>`_.
   This requirement is expected to change in 2020.
   Until then you will need to do the following:

   - Obtain license files following the procedure at
     http://www.seiscomp.org/ .

   - Un-tar these into the correct directory:

     .. code-block:: bash

        $ cd ~
        $ mkdir -p .seiscomp/key
        $ tar -xf temporary-license.tar
        $ ls ~/.seiscomp/key
        License  License.key  License.signed

#. Start the :program:`scconfig` GUI ::

     $ scconfig

   Learn more about :ref:`scconfig` in this documentation.
   You should see a screen/window like this.

   .. figure:: media/postinstall_scconfig.png
      :width: 16cm
      :align: center

      First view of :ref:`scconfig` configurator.

#. Run :program:`scrttv` ::

     $ ~/seiscomp/bin/seiscomp exec scrttv

   After seeing the SeisComP splash screen,
   you'll likely get an error message "Could not read inventory (NULL)".
   After a new installation, that's okay - you'll add inventory to your
   system later. (:ref:`tutorials_geofon_waveforms`.)
   Click that box away, and you'll see a screen with
   "Enabled", and "Disabled" tabs, and time along bottom axis.
   (See figure below.)

   .. figure:: media/postinstall_scrttv.png
      :width: 14.6cm
      :align: center

      First view of the :ref:`scconfig` configuration tool.

   .. warning::

      If you receive a message like "You have no valid license to run
      this software" you may not have installed the license files in the
      correct directory, :file:`~/.seiscomp/key` (note the '.').
      See above.


Congratulations, you're done with this tutorial.
