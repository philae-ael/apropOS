#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
 
#include <kernel/tty.h>
#include <kernel/vga.h>
#include <kernel/gdt.h>
 
char* buf [100];

void kernel_early(void)
{
	terminal_initialize();
    gdt_initialize();
}
 
void kernel_main(void)
{
    printf("Hello, world !\nLet's play with kernels !\n");
    /*do
    {
        c = getchar();
        putchar(c);
    }while(c != "\n")*/
}
