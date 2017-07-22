#include <stdbool.h>
#include <stdio.h>

#include <asm/interrupts.h>
#include <serial.h>
#include <console.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <irq.h>

void kernel_early(){
    disable_interrupts();
    irq_mask_all();

    // need console AND serial to be init before we can print ('cause CONSOLE_TO_SERIAL)
    serial_init();
    console_init();

    puts("Serial initialized\n");
    puts("Console initialized\n");

    gdt_init();
    puts("GDT initialized\n");

    idt_init();
    puts("IDT initialized\n");

    isr_init();
    puts("ISR initialized\n");

    irq_init();
    puts("IRQ initialized\n");
    enable_interrupts();
}
