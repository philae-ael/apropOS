#ifndef _STRING_H
#define _STRING_H

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef _cplusplus
extern "C" {
#endif

int memcpm(const void*, const void*, size_t); //from, to, how much
void* memcpy(void* __restrict, const void* __restrict, size_t); //to, from, how much
void* memmove(void*, const void*, size_t); //to, from, how much
void* memset(void*,int , size_t); //to, from, how much
size_t strlen(const char*);
char* itoa(int);

#ifdef _cplusplus
}
#endif

#endif
