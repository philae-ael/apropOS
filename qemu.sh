#!/bin/sh
set -e

. ./iso.sh

INFO "Launching qemu"

FILE="/tmp/$OS-log"

INFO "Log mapped on file $LOGFILE"

qemu-system-$(./target-triplet-to-arch.sh $HOST) \
    -serial mon:stdio \
    -cdrom $OS.iso \
    -nographic
