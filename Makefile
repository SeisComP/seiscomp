default: all

all:
	mkdir -p build
	cd build && ccmake ../ -DCMAKE_INSTALL_PREFIX=${HOME}/seiscomp -DCMAKE_POLICY_VERSION_MINIMUM=3.5
	echo "*** To build the sources change into the 'build' directory and enter make[ install] ***"

