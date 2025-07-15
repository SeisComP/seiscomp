#!/bin/bash

# The name of the following file may change. Find the correct one in source:
# https://github.com/IstvanBondar/iLoc
# The download source corresponds to the iloc documentation
URL="https://github.com/IstvanBondar/iLoc/raw/main/iLocAuxDir4.2.tgz"

error() {
        echo $1
        exit 1
}

echo "Installing iLoc dependencies"

echo -n "User name for owning the SeisComP installation (sysop): "
read user

if  [ -z "$user" ]; then
        user=sysop
fi

seiscompTemp=/home/${user}/seiscomp

echo -n "SeisComP installation directory (${seiscompTemp}): "
read seiscomp

if  [ -z "$seiscomp" ]; then
        seiscomp=${seiscompTemp}
fi

if [ ! -d "${seiscomp}" ]; then
        error "Directory "${seiscomp}" does not exists"
fi

iloc="$seiscomp/share/iloc"

mkdir -p "${iloc}" || error "Could not create target path ${iloc}"

tarFile="$(mktemp)"

echo "Downloading ${URL} to ${tarFile}"
wget -O "${tarFile}" "${URL}" || error "Failed to download ${URL} to ${tarFile}"

echo "Extracting tarball to '${iloc}'"
tar xzf "${tarFile}" -C "${iloc}" || error "Failed to extract ${tarFile}"

echo "Changing ownership of ${iloc} to $user - you may wish to set group ownership"
chown -R $user "${iloc}"

exit 0
