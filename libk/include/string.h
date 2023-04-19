#ifndef STD_STRING_H
#define STD_STRING_H
#include <stddef.h>

#ifdef _cplusplus
extern "C" {
#endif

void* memcpy(void* __restrict, const void* __restrict, size_t); //to, from, how much
void* memmove(void*, const void*, size_t); //to, from, how much
void* memset(void*,int , size_t); //to, from, how much
int memcmp(const void* ptr1, const void* ptr2, size_t num);
size_t strlen(const char* const str);

#ifdef _cplusplus
}
#endif

#endif
