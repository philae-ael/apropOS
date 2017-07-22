#ifndef _STRING_H
#define _STRING_H
#include <stddef.h>

#ifdef _cplusplus
extern "C" {
#endif

void* memcpy(void* __restrict, const void* __restrict, size_t); //to, from, how much
void* memmove(void*, const void*, size_t); //to, from, how much
void* memset(void*,int , size_t); //to, from, how much
size_t strlen(const char *str);

#ifdef _cplusplus
}
#endif

#endif
