#include <regs.h>
#include <asm.h>
#include <irq.h>
#include <stdint.h>

void (*irq_handlers[])(struct regs*) = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

void irq_handler(struct regs* r){
    if(r->int_no < 15 && irq_handlers[r->int_no] != 0)
        irq_handlers[r->int_no](r);
    pic_sendEOI(r->int_no);

}

void irq_handler_install(uint8_t irq_nb, void(*handler)(struct regs*)){
    if (irq_nb < 15)
        irq_handlers[irq_nb] = handler;
}


void irq_handler_uninstall(uint8_t irq_nb){
    if (irq_nb < 15)
        irq_handlers[irq_nb] = 0;
}


void irq_unmask(uint8_t irq_nb) {
    uint16_t port;
    uint8_t value;

    if(irq_nb < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        irq_nb -= 8;
    }
    value = inb(port) | (1 << irq_nb);
    outb(port, value);
}

void irq_mask(uint8_t irq_nb) {
    uint16_t port;
    uint8_t value;

    if(irq_nb < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        irq_nb -= 8;
    }
    value = inb(port) & ~(1 << irq_nb);
    outb(port, value);
}

void irq_mask_all() {
    outb(PIC1_DATA, 0xFF);
    outb(PIC2_DATA, 0xFF);
}

void pic_sendEOI(uint8_t irq_nb)
{
    if(irq_nb >= 8)
        outb(PIC2_COMMAND,PIC_EOI);

    outb(PIC1_COMMAND,PIC_EOI);
}
