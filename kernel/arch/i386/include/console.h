#ifndef CONSOLE_H
#define CONSOLE_H
#include <stdint.h>

void console_init();
void clear_screen();
void console_putc(char);
void console_puts(char*);

#endif
