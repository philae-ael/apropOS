export HOST?=i686-elf
export HOSTARCH:=i386

export MK_RESCUE?=grub-mkrescue

export AR=ar
export CC=clang -target ${HOST} -march=i386


export PREFIX?=
export EXEC_PREFIX?=$(PREFIX)
export BOOTDIR?=$(EXEC_PREFIX)/boot
export INCLUDEDIR?=$(PREFIX)/include
export LIBDIR?=$(EXEC_PREFIX)/lib
export DESTDIR?=$(PWD)/sysroot

export CC+= --sysroot=$(DESTDIR)

export ASM=nasm
export ASFLAGS=-felf32

export CFLAGS_COMMON:=-g -Og\
    -std=gnu11 \
    -ffreestanding -fbuiltin -Weverything -Werror\
    -I=$(INCLUDEDIR) \

export CPPFLAGS_COMMON:=
export LDFLAGS_COMMON:=
export LIBS_COMMON:=

QEMU=qemu-system-$(HOSTARCH)

QEMU_FLAGS_COMMON?= -kernel kernel/apropos.kernel
	     
QEMU_FLAGS?=-serial mon:stdio 

QEMU_DEBUG_FLAGS?= -S -s -monitor stdio -d guest_errors

BOCHS?=bochs
BOCHS_FLAGS?=-f boshrc

all: install-headers install

.PHONY: all clean install install-headers qemu qemu-gdb bochs

install-headers:
	$(MAKE) -C libc install-headers
	$(MAKE) -C libk install-headers
	$(MAKE) -C kernel install-headers
install:
	$(MAKE) -C libc install 
	$(MAKE) -C libk install 
	$(MAKE) -C kernel install
clean: 
	$(MAKE) -C libc clean
	$(MAKE) -C libk clean
	$(MAKE) -C kernel clean
	rm -f apropos.iso
	rm -rf $(DESTDIR)
	rm -rf isodir

qemu: all
	$(QEMU) $(QEMU_FLAGS_COMMON) $(QEMU_FLAGS)

qemu-gdb: all
	$(QEMU) $(QEMU_FLAGS_COMMON) $(QEMU_DEBUG_FLAGS)

bochs: apropos.iso
	$(BOCHS) $(BOCHS_FLAGS)

apropos.iso: all
	mkdir -p isodir/boot/grub

	cp sysroot/boot/apropos.kernel isodir/boot/apropos.kernel
	cp grub.cfg isodir/boot/grub/grub.cfg
	$(MK_RESCUE) -o apropos.iso isodir
