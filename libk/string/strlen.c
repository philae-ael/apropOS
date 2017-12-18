#include <stddef.h>
#include <string.h>

size_t strlen(const char *str){
    size_t n = 0;
    while(*str){
        n++;
        str++;
    }
    return n;
}
