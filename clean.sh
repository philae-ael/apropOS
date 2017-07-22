#!/bin/sh
set -e
. ./config.sh

INFO "Cleaning all"

for PROJECT in $PROJECTS; do
    INFO "Cleaning project $PROJECT"
    $MAKE -C $PROJECT clean
done

rm -rfv sysroot
rm -rfv isodir
rm -rfv $OS.iso

INFO "Everything cleaned"
