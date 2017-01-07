#include <kdb.h>
#include <regs.h>
#include <asm.h>
#include <stdio.h>
#include <irq.h>

void kdb_handler(struct regs* r){
    uint8_t scancode;

    scancode = inb(KDB_PORT);
    printf("Scancode: %x\n", scancode);
}

void kdb_init(){
    irq_handler_install(KDB_IRQ, kdb_handler);
    irq_mask(KDB_IRQ);
}
