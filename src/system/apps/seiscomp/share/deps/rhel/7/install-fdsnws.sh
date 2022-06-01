yum install python36-dateutil python36-pip

# install Python packages using pip
echo "installing packages for user " $user
su - $user -c 'python3 -m pip install --user twisted'
