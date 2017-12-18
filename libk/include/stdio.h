#ifndef STD_STDIO_H
#define STD_STDIO_H

#include <stdarg.h>

int printf(const char* format, ...);
int vprintf(const char* format, va_list);
int _printf(int (*)(const char[]), int (*)(int), const char *, va_list);
int puts(const char* str);
int putchar(int c);
char* itoa(int value, char* str, int base);
char* atoi(int value, char* str);

#endif
