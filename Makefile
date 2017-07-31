export HOST?=i686-elf
export HOSTARCH:=i386

export AR=${HOST}-ar
export AS=${HOST}-as
export CC=${HOST}-gcc


export PREFIX?=
export EXEC_PREFIX?=$(PREFIX)
export BOOTDIR?=$(EXEC_PREFIX)/boot
export INCLUDEDIR?=$(PREFIX)/include
export LIBDIR?=$(EXEC_PREFIX)/lib
export DESTDIR?=$(PWD)/sysroot

export CC+= --sysroot=$(DESTDIR)

export ASM=nasm
export ASFLAGS=-felf32

export CFLAGS_COMMON:=-O2 -g \
    -ffreestanding -fbuiltin -Wall -Wextra \
    -I=$(INCLUDEDIR)
export CPPFLAGS_COMMON:=
export LDFLAGS_COMMON:=
export LIBS_COMMON:=

QEMU=qemu-system-$(HOSTARCH)

QEMU_FLAGS?= -serial mon:stdio \
	    -kernel kernel/apropos.kernel \
	    -nographic \

QEMU_DEBUG_FLAGS?= -S -s

BOCHS?=bochs
BOCHS_FLAGS?=-f boshrc

all: install-headers install

.PHONY: all clean install install-headers qemu qemu-gdb bochs

install-headers:
	$(MAKE) -C libc install-headers
	$(MAKE) -C kernel install-headers
install:
	$(MAKE) -C libc install 
	$(MAKE) -C kernel install
clean: 
	$(MAKE) -C libc clean
	$(MAKE) -C kernel clean
	rm -f apropos.iso
	rm -rf $(DESTDIR)
	rm -rf isodir

qemu: all
	$(QEMU) $(QEMU_FLAGS)

qemu-gdb: all
	$(QEMU) $(QEMU_FLAGS) $(QEMU_DEBUG_FLAGS)

bochs: apropos.iso
	$(BOCHS) $(BOCHS_FLAGS)

apropos.iso: all
	mkdir -p isodir/boot/grub

	cp sysroot/boot/apropos.kernel isodir/boot/apropos.kernel
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub2-mkrescue -o apropos.iso isodir
