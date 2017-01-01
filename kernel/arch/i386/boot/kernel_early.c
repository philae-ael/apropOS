#include <stdbool.h>
#include <stdio.h>

#include <console.h>
#include <gdt.h>


void kernel_early(){
    console_init();
    puts("Console initialized\b\n");
    gdt_init();
}
