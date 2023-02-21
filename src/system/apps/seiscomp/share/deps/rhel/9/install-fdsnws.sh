dnf install python3-dateutil python3-pip || exit 1

echo -n "seiscomp user name for pip install (sysop): "
read user

if  [ -z "$user" ]; then user=sysop; fi

id $user > /dev/null || exit 1

# install Python packages using PIP
echo "updating pip for user $user"
su - $user -c 'python3 -m pip install --upgrade --user pip' || exit 1
echo "installing packages for user $user"
su - $user -c 'python3 -m pip install --user twisted' || exit 1
