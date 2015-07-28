#ifndef TTY_H
#define TTY_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool terminal_initialize(void);

void terminal_setcolor(uint16_t color);
void terminal_putchar(char c);
void terminal_write(char* c,size_t size);
void terminal_writestring(char* c);
void terminal_putentryat(char* c,size_t size);
void terminal_setcursorpos(size_t x,size_t y);
void terminal_scrollup(size_t y);

#endif
