#!/bin/sh
set -e
. ./config.sh

INFO "Installing headers"
mkdir -p sysroot

for PROJECT in $SYSTEM_HEADER_PROJECTS; do
    INFO "Installing headers for project $PROJECT"
  DESTDIR="$PWD/sysroot" $MAKE -C $PROJECT install-headers
done
INFO "Headers installed"
