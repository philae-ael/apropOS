#include <multiboot.h>
#include <logging.h>
#include <assert.h>

#include <asm/interrupts.h>
#include <serial.h>
#include <console.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <irq.h>
#include <memory_management.h>
#include <kcall.h>

void kernel_early(multiboot_info_t* mbd, uint32_t magic){
    disable_interrupts();
    irq_mask_all();

    // need console AND serial to be init before we can print ('cause CONSOLE_TO_SERIAL)
    serial_init();
    console_init();

    set_log_level(LOG_DEBUG);

    assert(magic == 0x2BADB002); // Is it really multiboot ?
    info("Serial initialized\n");
    info("Console initialized\n");

    debugf("Multiboot flags %X\n", mbd->flags);

    if (mbd->flags, 0x2)
         infof("Multiline cmdline = %s\n", (char *) mbd->cmdline);

    gdt_init();
    info("GDT initialized\n");

    idt_init();
    info("IDT initialized\n");

    isr_init();
    info("ISR initialized\n");

    irq_init();
    info("IRQ initialized\n");

    kcall_init();
    info("Kcalls initialized");

    enable_interrupts();

    if(!(mbd->flags & 0x40)){
        errf("Non mmap provided by multiboot. Can't continue.");
        for(;;);
    }

    multiboot_memory_map_t* mmap = mbd->mmap_addr;
    mem_management_init(mmap, mbd->mmap_length);
    info("Memory management initialized\n");
}
