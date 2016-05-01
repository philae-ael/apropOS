#!/bin/sh
set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
  DESTDIR=$PWD/sysroot $MAKE -j`nproc` -C $PROJECT install
done
