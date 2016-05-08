#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static void print(const char* data, size_t data_length)
{
    for ( size_t i = 0; i < data_length; i++ )
        putchar((int) ((const unsigned char*) data)[i]);
}

int printf(const char* restrict format, ...)
{
    va_list parameters;
    va_start(parameters, format);

    int written = 0;

    while ( *format != '\0' )
   {
        if ( *format == '%')
        {
            format++;
            if(*format == 'd'){
                    int i = va_arg(parameters, int);
                    char c [32]; //works up to 10^32
                    itoa(i, c, 10);
                    print(c, strlen(c));
                    written += strlen(c);
            }
            else if(*format == 'x'){
                    int i = va_arg(parameters, int);
                    char c [32]; //works up to 10^32
                    itoa(i, c, 16);
                    print(c, strlen(c));
                    written += strlen(c);
            }
            else if(*format == 'b'){
                    int i = va_arg(parameters, int);
                    char c [32]; //works up to 10^32
                    itoa(i, c, 2);
                    print(c, strlen(c));
                    written += strlen(c);
            }
            else if(*format == 's'){
                    const char* c = va_arg(parameters, char*);
                    print(c, strlen(c));
                    written += strlen(c);
            }
            else if(*format == 'c'){
                    const char c = va_arg(parameters, char);
                    print(&c, 1);
                    written += 1;
            }
            else{
                print(format, 1);
            }
            format++;
        }
        else{
            int amount = 0;
            while(*(format + amount) != '%' && *(format + amount) != '\0')
                amount++;
            print(format, amount);
            format += amount;
            written += written;
        }
    }
    va_end(parameters);

    return written;
}
