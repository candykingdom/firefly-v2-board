#! /usr/bin/env bash

set -euo pipefail

DIR=bossac-1.7.0

mkdir $DIR
cp bossac_linux $DIR
tar -cvjSf bossac_linux.tar.bz2 $DIR
rm $DIR/bossac_linux

cp bossac_osx $DIR
tar -cvjSf bossac_osx.tar.bz2 $DIR
rm $DIR/bossac_osx

rmdir $DIR

