# ApropOS
## Introduction 

My simple os, created by my own, from scratch

It aims only x86 platforms. It is tested on qemu + bochs.

What I want is not a fully fonctional system but a way to learn more on PC architecture. 

## What I want to be working on my system

based on (OSDev's recommandations)[http://wiki.osdev.org/What_order_should_I_make_things_in]

- [x] Working output system for logging on screen + helpers to show numbers in hex/dec/oct numbers (printf like interface)
- [ ] Working output/input system on serial port.
- [ ] Interupts handler + dumping all needed content (regs/stack frames/address default/other debugs things)
- [ ] And more...

# Let's run it
## Prerequisites

Need a working cross-compiler (CF http://wiki.osdev.org/GCC_Cross-Compiler)

## The toolchain

This toolchain come from OSDev tutorials initially but are quite reworked.

- **clean.sh** -> clean all object files and other
- **build.sh** -> build project
- **qemu.sh** -> build and start the kernel throught qemu

## The sources

- **kernel** -> the sources of my kernel
- **libc** -> the sources of my custom libc

---------------
# References:
- A really good way to learn more and more -> (OSDev)[http://wiki.osdev.org/]
