#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <kernel/tty.h>
#include <kernel/vga.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/irq.h>
#include <kernel/kbd.h>

#define INIT(name, checkReturn) \
    printf( "initialization of " #name ); \
printf(" [");\
if(! name## _initialize() && (checkReturn)){\
    terminal_setcolor(make_color(COLOR_RED,COLOR_BLACK));\
    printf("FAILED");\
    abort();\
}\
else\
{\
    terminal_setcolor(make_color(COLOR_GREEN,COLOR_BLACK));\
    printf("OK");\
}\
        terminal_setcolor(make_color(COLOR_LIGHT_GREY,COLOR_BLACK));\
        printf("] \n")


        char* buf [100];

void kernel_early(void)
{
    terminal_initialize();
    printf("terminal initialized\n");

    INIT(gdt, false);
    INIT(idt, true);
    INIT(irq,true);
    INIT(kbd, true);
}

void kernel_main(void)
{
    printf("Hello, world !\nLet's play with kernels !\n");
    volatile int x = 1/0;
    /*do
      {
      c = getchar();
      putchar(c);
      }while(c != "\n")*/
}
