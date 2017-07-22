#ifndef SERIAL_H
#define SERIAL_H

void serial_init();
char read_serial();
void write_serial(char);
int puts_serial(const char*);
int putchar_serial(int);

#endif
