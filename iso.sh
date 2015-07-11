#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/apropos.kernel isodir/boot/apropos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "apropos" {
	multiboot /boot/apropos.kernel
}
EOF
grub-mkrescue -o apropos.iso isodir
