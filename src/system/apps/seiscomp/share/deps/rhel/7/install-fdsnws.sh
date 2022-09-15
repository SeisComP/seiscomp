yum install python36-dateutil python36-pip

echo "user name for pip install (sysop):"
read user

if  [ -z "$user" ]; then user=sysop; fi

# install Python packages using pip
echo "installing packages for user " $user
su - $user -c 'python3 -m pip install --user twisted'
