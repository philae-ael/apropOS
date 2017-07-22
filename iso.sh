#!/bin/sh
set -e
. ./build.sh

INFO "Creating ISO"
mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/$OS.kernel isodir/boot/$OS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
set timeout=0
menuentry "$OS" {
	multiboot /boot/$OS.kernel
}
EOF
grub2-mkrescue -o $OS.iso isodir
INFO "ISO created"
