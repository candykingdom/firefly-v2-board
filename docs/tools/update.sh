#! /usr/bin/env bash

set -euo pipefail

DIR=bossac-1.7.0

mkdir $DIR
cp bossac_linux $DIR
tar -cvjSf bossac_linux.tar.bz2 $DIR
rm $DIR/bossac_linux
rmdir $DIR

