#ifndef STD_STDIO_H
#define STD_STDIO_H

#include <stdarg.h>

int printf(const char* const format, ...);
int vprintf(const char* const format, va_list);
int _printf(int (*)(const char * const), int (*)(int), const char *const, va_list);
int puts(const char* const str);
int putchar(int c);
char* itoa(int value, char* str, int base);
char* atoi(int value, char* str);

#endif
