#include <stdarg.h>
#include <stdio.h>

int _printf(int (*puts)(const char[]),
        int (*putchar)(int),
        const char *format, va_list args){
    const char *p;
    char buff[256]; //to contain atoi/itoa return
    char* s;
    char c;

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

    return 0;
}

int vprintf(const char* format, va_list args){
    return _printf(puts, putchar, format, args);
}

int printf(const char* format, ...){
    va_list args;
    va_start(args, format);
    int ret = _printf(puts, putchar, format, args);
    va_end(args);
    return ret;
}
