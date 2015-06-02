#!/bin/sh

sudo apt-get update
sudo apt-get upgrade
sudo apt-get -y install tk-dev ncurses-dev libmpfr-dev texinfo
sudo apt-get -y install scons libusb-dev libusb-0.1-4
#build...
