#include <kernel/i386/irq.h>
#include <kernel/i386/idt.h>
#include <kernel/i386/asm/io.h>


extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

void irq_remap(){
    unsigned char a1, a2;

    a1 = inb(PIC1_DATA);                        // save masks
    a2 = inb(PIC2_DATA);

    outb(PIC1_COMMAND, ICW1_INIT+ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
    io_wait();
    outb(PIC2_COMMAND, ICW1_INIT+ICW1_ICW4);
    io_wait();
    outb(PIC1_DATA, 32);                 // ICW2: Master PIC vector offset
    io_wait();
    outb(PIC2_DATA, 40);                 // ICW2: Slave PIC vector offset
    io_wait();
    outb(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
    io_wait();
    outb(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
    io_wait();

    outb(PIC1_DATA, ICW4_8086);
    io_wait();
    outb(PIC2_DATA, ICW4_8086);
    io_wait();

    outb(PIC1_DATA, a1);   // restore saved masks.
    outb(PIC2_DATA, a2);
}

void irq_init(){
    irq_remap();

    idt_set_gate(32, (uint32_t)irq0, 0x8, 0x8E);
    idt_set_gate(33, (uint32_t)irq1, 0x8, 0x8E);
    idt_set_gate(34, (uint32_t)irq2, 0x8, 0x8E);
    idt_set_gate(35, (uint32_t)irq3, 0x8, 0x8E);
    idt_set_gate(36, (uint32_t)irq4, 0x8, 0x8E);
    idt_set_gate(37, (uint32_t)irq5, 0x8, 0x8E);
    idt_set_gate(38, (uint32_t)irq6, 0x8, 0x8E);
    idt_set_gate(39, (uint32_t)irq7, 0x8, 0x8E);
    idt_set_gate(40, (uint32_t)irq8, 0x8, 0x8E);
    idt_set_gate(41, (uint32_t)irq9, 0x8, 0x8E);
    idt_set_gate(42, (uint32_t)irq10, 0x8, 0x8E);
    idt_set_gate(43, (uint32_t)irq11, 0x8, 0x8E);
    idt_set_gate(44, (uint32_t)irq12, 0x8, 0x8E);
    idt_set_gate(45, (uint32_t)irq13, 0x8, 0x8E);
    idt_set_gate(46, (uint32_t)irq14, 0x8, 0x8E);
    idt_set_gate(47, (uint32_t)irq15, 0x8, 0x8E);
}
