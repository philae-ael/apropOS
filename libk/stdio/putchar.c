#include <stdio.h>

#include <kernel/i386/console.h>
#include <kernel/i386/serial.h>

int putchar(int c){
    console_putc((char)c);
    putchar_serial((char)c);
    return c;
}
