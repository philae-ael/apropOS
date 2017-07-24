#!/bin/sh
set -e

. ./build.sh

INFO "Launching qemu"

FILE="/tmp/$OS-log"

INFO "Log mapped on file $LOGFILE"

qemu-system-$(./target-triplet-to-arch.sh $HOST) \
    -serial mon:stdio \
    -kernel kernel/apropos.kernel \
    -nographic \
    $@
