#ifndef CONSOLE_H
#define CONSOLE_H
#include <stdint.h>

/* Console_init
 * Initialize the console and all internals vars used.
 * Have to be called before any other functions of this file.
 * */
void console_init();

/* Clear_screan
 * Clear the screen removing every character on the screen and setting next write position at (0, 0) (top-left corner)
 * Don't reset cursor position.
 * */
void clear_screen();

/* console_putc
 * Add a character on the screen.
 * Don't change the cursor position.
 * */
void console_putc(char);

/* console_puts
 * Add a null-terminated string on the screen.
 * Don't change the cursor position
 * */
void console_puts(char*);

#endif
