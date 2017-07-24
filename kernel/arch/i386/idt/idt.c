#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <kernel/i386/idt.h>

#define IDT_MAX_SIZE 256


struct idt_entry
{
    uint16_t base_lo;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_hi;
} __attribute__((packed));

extern void idt_load(struct idt_entry*, size_t);

struct idt_entry idt[IDT_MAX_SIZE];

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags){
    idt[num].base_lo = base & 0xFFFF;
    idt[num].base_hi = (base >> 16) & 0xFFFF;

    idt[num].flags = flags;
    idt[num].sel = sel;
    idt[num].always0 = 0;
}

void idt_init(){
    memset(idt, 0, sizeof(idt)); // fill with zero the IDT

    idt_load(idt, sizeof(idt) - 1);
}
