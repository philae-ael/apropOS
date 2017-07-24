HOST?=$(shell ../default-host.sh)
HOSTARCH:=$(shell ../target-triplet-to-arch.sh $(HOST))

ASM=nasm
ASFLAGS=-f aout

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

PREFIX?=/usr/local
DESTDIR?=
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin -Wall -Wextra -I$(INCLUDEDIR)
CPPFLAGS:=$(CPPFLAGS)
LIBK_CFLAGS:=$(CFLAGS) -D_klibc
LIBK_CPPFLAGS:=$(CPPFLAGS)

FREEOBJS:=\
$(ARCH_FREEOBJS)

include def.config

include stdio/make.config
include stdlib/make.config
include logging/make.config
include string/make.config

HOSTEDOBJS:=\
$(ARCH_HOSTEDOBJS) \

OBJS:=\
$(FREEOBJS) \
$(HOSTEDOBJS) \

LIBK_OBJS:=$(FREEOBJS:.o=.libk.o)

BINARIES=libc.a libk.a

all: $(BINARIES)

.PHONY: all clean install install-headers install-libs

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

%.o: %.c
	$(CC) -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS) $(CONF)

%.o: %.asm
	$(ASM) $(ASFLAGS) -o $@ $< 

%.libk.o: %.c
	$(CC) -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS) $(LIBK_CPPFLAGS) $(KCONF)

%.libk.o: %.asm
	$(ASM) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(BINARIES) $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -RTv include $(DESTDIR)$(INCLUDEDIR)

install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)
