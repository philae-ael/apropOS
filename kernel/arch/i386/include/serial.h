#ifndef SERIAL_H
#define SERIAL_H

/* serial_init
 * Initialize the serial.
 * Have to be the first called function of this file.
 * */
void serial_init(void);

/* read_serial
 * Read a char from serial.
 * */
char read_serial(void);

/* write_serial
 * Write a char on the serial output.
 * Arg:
 *  - c: the char to write on the serial.
 * */
void write_serial(char c);

/* puts_serial
 * A wrapper arround write_serial that allow to write a string
 * Args:
 *  - str: the string to send through serial.
 * Return:
 *  - The number of char written (length of str.)
 * */
int puts_serial(const char*);

/* putchar_serial
 * A wrapper arround write_serial that allow to write a char
 * Args:
 *  - c: the char to send through serial.
 * Return:
 *  - The number of char written (1)
 * */
int putchar_serial(int);

#endif
