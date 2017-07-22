#include <stdbool.h>
#include <stdio.h>

#include <asm/interrupts.h>
#include <console.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <irq.h>

void kernel_early(){
    disable_interrupts();
    irq_mask_all();

    console_init();
    puts("Console initialized\n");

    gdt_init();
    puts("GDT initialized\n");

    idt_init();
    puts("IDT initialized\n");

    isr_init();
    puts("ISR initialized\n");

    irq_init();
    puts("IRQ initialized\n");
}
