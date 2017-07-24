#include <stdio.h>

#ifdef _klibc
#include <kernel/i386/console.h>
#endif

int putchar(int c){
#ifdef _klibc
    console_putc(c);
#else
    //TODO
#endif
    return c;
}
