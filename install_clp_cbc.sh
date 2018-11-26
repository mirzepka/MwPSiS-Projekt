#!/bin/sh
# This script downloads and installs a modified version of the Clp solver on
# the Ubuntu 16.04 operating system available in the computer lab. The Added
# features include support for the GMPL modeling language.
#
# The original version of this script was created by Konrad Adamczyk (18.10.2018)
# Revised by Andrzej Kamisiński
# -----------------------------------------------------------------------------

set -e

TAR_FILENAME="clp_1.16.11_cbc_2.9.9_gmpl_ubuntu_16.04.tar.bz2"
DOWNLOAD_URL="http://kt.agh.edu.pl/~kamisinski/teaching/mpsis/lab/L1/content/${TAR_FILENAME}"

if [ -z "${TAR_FILENAME}" ]
then
	echo "E: empty variable 'TAR_FILENAME'"
	exit 1
fi

cd ~/
wget ${DOWNLOAD_URL}

if [ ! -e ${TAR_FILENAME} ]
then
	echo "E: File does not exist: ${TAR_FILENAME}"
	exit 1
fi

sudo mv ${TAR_FILENAME} /
cd /
sudo tar -xjvpf ${TAR_FILENAME}
sudo rm -f ${TAR_FILENAME}

cd ~/
echo "export LD_LIBRARY_PATH=/usr/local/lib" >> ~/.bashrc

echo "Installation completed successfully. Please restart the terminal."
