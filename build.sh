#!/bin/sh
set -e
. ./headers.sh

INFO "Building $OS"

for PROJECT in $PROJECTS; do
    INFO "Building project $PROJECT"
    DESTDIR=$PWD/sysroot $MAKE -j`nproc` -C $PROJECT install
done
INFO "Build done"

