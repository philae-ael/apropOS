#include <i386/irq.h>
#include <i386/irqdefs.h>
#include <i386/idt.h>
#include <i386/asm/asm.h>

//Fct ptrs
void (*handler[16]) (struct regs*) = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

void irq_set_handler(uint8_t irq, void (*fct) (struct regs*)){
    if (irq < 16)
        handler[irq] = fct;
}

void irq_handler(struct regs* r){
    printf("irq %d handled", r->call_code);
    if(r->call_code < 15 && handler[r->call_code])
    {
        handler[r->call_code](r);
    }
    PIC_sendEOI(r->call_code);

}


void PIC_sendEOI(uint8_t irq){
    if(irq >= 8)
        outb(PIC_SLAVE_CONTROL_PORT, PIC_EOI);

    outb(PIC_MASTER_CONTROL_PORT, PIC_EOI);
}

bool irq_initialize(){
    PIC_remap(0x20,0x27);

    idt_set_gate(32, (uint32_t)irq0  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(33, (uint32_t)irq1  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(34, (uint32_t)irq2  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(35, (uint32_t)irq3  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(36, (uint32_t)irq4  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(37, (uint32_t)irq5  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(38, (uint32_t)irq6  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(39, (uint32_t)irq7  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(40, (uint32_t)irq8  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(41, (uint32_t)irq9  ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(42, (uint32_t)irq10 ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(43, (uint32_t)irq11 ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(44, (uint32_t)irq12 ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(45, (uint32_t)irq13 ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(46, (uint32_t)irq14 ,0x8 ,IDT_INTERRUPT_32);
    idt_set_gate(47, (uint32_t)irq15 ,0x8 ,IDT_INTERRUPT_32);

    return true;
}

void PIC_remap(uint8_t offset1,uint8_t offset2){

    unsigned char a1, a2;

    a1 = inb(PIC_MASTER_DATA_PORT);                        // save masks
    a2 = inb(PIC_SLAVE_DATA_PORT);

    outb(PIC_MASTER_CONTROL_PORT, ICW1_INIT+ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
    io_wait();
    outb(PIC_SLAVE_CONTROL_PORT, ICW1_INIT+ICW1_ICW4);
    io_wait();
    outb(PIC_MASTER_DATA_PORT, offset1);                 // ICW2: Master PIC vector offset
    io_wait();
    outb(PIC_SLAVE_DATA_PORT, offset2);                 // ICW2: Slave PIC vector offset
    io_wait();
    outb(PIC_MASTER_DATA_PORT, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
    io_wait();
    outb(PIC_SLAVE_DATA_PORT, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
    io_wait();

    outb(PIC_MASTER_DATA_PORT, ICW4_8086);
    io_wait();
    outb(PIC_SLAVE_DATA_PORT, ICW4_8086);
    io_wait();

    outb(PIC_MASTER_DATA_PORT, a1);   // restore saved masks.
    outb(PIC_SLAVE_DATA_PORT, a2);
}


void IRQ_mask(uint8_t irq, bool mask) {
    uint16_t port;
    uint8_t value;

    if(irq < 8) {
        port = PIC_MASTER_DATA_PORT;
    } else {
        port = PIC_SLAVE_DATA_PORT;
        irq -= 8;
    }
    value = inb(port);
    if (mask)
        value |= (1 << irq);
    else
        value |= ~(1 << irq);

    outb(port, value);
}

void PIC_disable(){
    outb(PIC_MASTER_DATA_PORT, 0xff);
    outb(PIC_SLAVE_DATA_PORT, 0xff);
}
