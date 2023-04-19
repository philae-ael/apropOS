#include <kernel/i386/asm/regs.h>
#include <kernel/i386/asm/io.h>
#include <kernel/i386/irq.h>
#include <stdint.h>


static void (*irq_handlers[])(struct regs*) = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

static void pic_sendEOI(uint8_t irq_nb){
    if(irq_nb >= 8)
        outb(PIC2_COMMAND,PIC_EOI);

    outb(PIC1_COMMAND,PIC_EOI);
}

void irq_handler(struct regs* r);
void irq_handler(struct regs* r){
    if(r->int_no < 15 && irq_handlers[r->int_no] != 0)
        irq_handlers[r->int_no](r);
    pic_sendEOI((uint8_t)r->int_no);

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
    value = (uint8_t)(inb(port) | (1 << irq_nb));
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

void irq_mask_all(void) {
    outb(PIC1_DATA, 0xFF);
    outb(PIC2_DATA, 0xFF);
}

