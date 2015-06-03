* vagrant box add precise-server-ubuntu https://cloud-images.ubuntu.com/vagrant/precise/current/precise-server-cloudimg-i386-vagrant-disk1.box
* vagrant up
* vagrant ssh
* cd /vagrant
* sh build_arm_toolchain.sh
* sudo cp 70-lego.rules /etc/udev/rules.d/70-lego.rules # for upload to nxt

