#include <libk/stdio.h>
#include <libk/string.h>
#include <libk/utils.h>

#include <kernel/i386/console.h>
#include <kernel/i386/serial.h>

int puts(const char* const str){
    puts_serial(str);
    return (int) strlen(str);
}
