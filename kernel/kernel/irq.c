#include <stdint.h>
#include <stdbool.h> 
#include <stdio.h>
#include <kernel/macroASM.h>

#include <kernel/irq.h>
#include <kernel/irqdefs.h>
#include <kernel/idt.h>
#include <kernel/regs.h>

void (*handler[16]) (struct regs*) = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

bool irq_initialize(void)
{
    //remap irq
    outb(0x20, 0x11);
    outb(0xA0, 0x11);

    outb(0x21, 0x20);
    outb(0xA1, 0x28);

    outb(0x21, 0x04);
    outb(0xA1, 0x02);

    outb(0x21, 0x01);
    outb(0xA1, 0x01);

    outb(0x21, 0x0);
    outb(0xA1, 0x0);

    idt_set_gate(32, (uint32_t)irq0  ,0x8 ,0x8E);
    idt_set_gate(33, (uint32_t)irq1  ,0x8 ,0x8E);
    idt_set_gate(34, (uint32_t)irq2  ,0x8 ,0x8E);
    idt_set_gate(35, (uint32_t)irq3  ,0x8 ,0x8E);
    idt_set_gate(36, (uint32_t)irq4  ,0x8 ,0x8E);
    idt_set_gate(37, (uint32_t)irq5  ,0x8 ,0x8E);
    idt_set_gate(38, (uint32_t)irq6  ,0x8 ,0x8E);
    idt_set_gate(39, (uint32_t)irq7  ,0x8 ,0x8E);
    idt_set_gate(40, (uint32_t)irq8  ,0x8 ,0x8E);
    idt_set_gate(41, (uint32_t)irq9  ,0x8 ,0x8E);
    idt_set_gate(42, (uint32_t)irq10 ,0x8 ,0x8E);
    idt_set_gate(43, (uint32_t)irq11 ,0x8 ,0x8E);
    idt_set_gate(44, (uint32_t)irq12 ,0x8 ,0x8E);
    idt_set_gate(45, (uint32_t)irq13 ,0x8 ,0x8E);
    idt_set_gate(46, (uint32_t)irq14 ,0x8 ,0x8E);
    idt_set_gate(47, (uint32_t)irq15 ,0x8 ,0x8E);

    return true;
}

void irq_set_handler(uint8_t irq_number, void (*func) (struct regs*))
{
    if(irq_number < 15)
        handler[irq_number] = func;
}

void irq_handler(struct regs* r)
{
    printf("eeeeeee");
    if(r->call_code < 15 && handler[r->call_code])
    {
        handler[r->call_code](r);
    }

    if(r->call_code > 7) //send EOI to slave
    {
        outb(0xA0,0x20);
    }

    outb(0x20,0x20); //send EOI to master
}
