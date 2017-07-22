#include <logging.h>

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

    set_log_level(LOG_DEBUG);

    info("Serial initialized\n");
    info("Console initialized\n");

    gdt_init();
    info("GDT initialized\n");

    idt_init();
    info("IDT initialized\n");

    isr_init();
    info("ISR initialized\n");

    irq_init();
    info("IRQ initialized\n");
    enable_interrupts();
}
