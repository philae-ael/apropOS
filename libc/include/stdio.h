#ifndef _STDIO_H
#define _STDIO_H

#include <sys/cdefs.h>

#ifdef __cpluplus
extern "C"{
#endif

int printf(const char* __restrict,...);
int puts(const char*);
int putchar(int);

#ifdef __cpluplus
}
#endif

#endif
