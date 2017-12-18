#include <stdio.h>
#include <string.h>
#include <utils.h>

#include <kernel/kcall.h>
#include <kernel/kcall_no.h>

int puts(const char* str){
    size_t len = strlen(str);
    struct kcall_write_t write_args = {.str = str, .len=len};

    kcall(KCALL_WRITE, &write_args);
    return (int) len;
}
