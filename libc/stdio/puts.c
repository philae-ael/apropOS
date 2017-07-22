#include <stdio.h>
#include <string.h>

#ifdef _klibc
#include <kernel/console.h>
#endif

int puts(const char* str){
#ifdef _klibc
    console_puts(str);
#else
    //TODO
#endif
    return strlen(str);
}
