default: all

all:
	mkdir -p build
	cd build && ccmake ../ -DCMAKE_INSTALL_PREFIX=${HOME}/seiscomp
	echo "*** To build the sources change into the 'build' directory and enter make[ install] ***"

