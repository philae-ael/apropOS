#include <logging.h>
#include <assert.h>

#include <kernel/i386/multiboot.h>
#include <kernel/i386/asm/interrupts.h>
#include <kernel/i386/serial.h>
#include <kernel/i386/console.h>
#include <kernel/i386/gdt.h>
#include <kernel/i386/idt.h>
#include <kernel/i386/isr.h>
#include <kernel/i386/irq.h>
#include <kernel/i386/memory_management.h>
#include <kernel/kcall.h>

void kernel_early(multiboot_info_t* mbd, uint32_t magic){
    disable_interrupts();
    irq_mask_all();

    // need console AND serial to be init before we can print ('cause CONSOLE_TO_SERIAL)
    serial_init();
    console_init();

    set_log_level(LOG_DEBUG);

    assert(magic == 0x2BADB002); // Is it really multiboot ?
    info("Serial initialized");
    info("Console initialized");

    debugf("Multiboot flags %X", mbd->flags);

    if (mbd->flags, 0x2)
         infof("Multiline cmdline = %s", mbd->cmdline);

    gdt_init();
    info("GDT initialized");

    idt_init();
    info("IDT initialized");

    isr_init();
    info("ISR initialized");

    irq_init();
    info("IRQ initialized");

    kcall_init();
    info("Kcalls initialized");

    enable_interrupts();

    if(!(mbd->flags & 0x40)){
        errf("Non mmap provided by multiboot. Can't continue.");
        for(;;);
    }

    multiboot_memory_map_t* mmap = (multiboot_memory_map_t*) mbd->mmap_addr;
    heap_init(mmap, mbd->mmap_length);
    info("Memory management initialized");
}
