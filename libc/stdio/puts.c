#include <stdio.h>

#ifdef _klibc
#include <kernel/console.h>
#endif

void puts(char* str){
#ifdef _klibc
    console_puts(str);
#else
    //TODO
#endif
}
