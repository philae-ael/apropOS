#include <stdarg.h>
#include <stdio.h>

int printf(const char *format, ...){
    const char *p;
    char buff[256]; //to contain atoi/itoa return
    char* s;
    char c;
    va_list args;
    va_start(args, format);

    for(p = format; *p != 0; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        p++;

        switch(*p){
            case '%':
                putchar('%');
                break;
            case 's':
                s = va_arg(args, char*);
                puts(s);
                break;
            case 'X':
                puts("0x");
            case 'x':
                itoa(va_arg(args, int), buff, 16);
                puts(buff);
                break;
            case 'd':
                atoi(va_arg(args, int), buff);
                puts(buff);
                break;
            case 'c':
                c = va_arg(args, int);
                putchar(c);
                break;
        }
    }

    va_end(args);
    return 0;
}
