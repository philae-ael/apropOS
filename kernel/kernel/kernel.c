#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
 
#include <kernel/tty.h>
#include <kernel/vga.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>

#define INIT(name) \
    printf( "initialization of " #name " \n"); \
    name## _initialize(); \
    printf( #name  " initialized \n");
                    

char* buf [100];

void kernel_early(void)
{
	terminal_initialize();
    printf("terminal initialized\n");

    INIT(gdt);
    
    INIT(idt);
}
 
void kernel_main(void)
{
    printf("Hello, world !\nLet's play with kernels !\n");
    
    printf("%d",1/0);
    
    /*do
    {
        c = getchar();
        putchar(c);
    }while(c != "\n")*/
}
