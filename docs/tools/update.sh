#! /usr/bin/env bash

set -euo pipefail

cd linux
tar -cvjSf ../bossac_linux.tar.bz2 *
cd ..
sha1sum bossac_linux.tar.bz2

cd osx
tar -cvjSf ../bossac_osx.tar.bz2 *
cd ..
sha1sum bossac_osx.tar.bz2

cd windows
tar -cvjSf ../bossac_windows.tar.bz2 *
cd ..
sha1sum bossac_windows.tar.bz2
