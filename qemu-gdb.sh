#!/bin/sh
set -e

. ./iso.sh

INFO "Launching qemu"

FILE="/tmp/$OS-log"

INFO "Log mapped on file $LOGFILE"

qemu-system-$(./target-triplet-to-arch.sh $HOST) \
    -S -s\
    -chardev file,id=log,path=$FIFO  -device isa-serial,chardev=log\
    -cdrom $OS.iso
