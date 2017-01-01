#include <stdio.h>

#ifdef _klibc
#include <kernel/console.h>
#endif

void putchar(char c){
#ifdef _klibc
    console_putc(c);
#else
    //TODO
#endif
}
