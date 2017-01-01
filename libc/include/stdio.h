#ifndef STDIO_H
#define STDIO_H

int printf(const char* format, ...);
void puts(char* str);
void putchar(char c);
char* itoa(int value, char* str, int base);
char* atoi(int value, char* str);

#endif
