#include <stdio.h>
#include <string.h>
#include <utils.h>

#include <kernel/i386/console.h>

int puts(const char* str){
    console_puts(str);
    return (int) strlen(str);
}
