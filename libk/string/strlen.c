#include <stddef.h>
#include <libk/string.h>

size_t strlen(const char * const str){
    size_t n = 0;
    const char* s2 = str;
    while(*s2){
        n++;
        s2++;
    }
    return n;
}
