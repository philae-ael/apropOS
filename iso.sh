#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/$OS.kernel isodir/boot/$OS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "$OS" {
	multiboot /boot/$OS.kernel
}
EOF
grub-mkrescue -o $OS.iso isodir
