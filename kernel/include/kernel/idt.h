#ifndef IDT_H
#define IDT_H
#include <stdint.h>

#define IDTSIZE 0xFF // nbr max of descriptors

// IDT descriptor CF : http://wiki.osdev.org/Interrupt_Descriptor_Table for further informations
struct idtgate{
    uint16_t offset0_15;
    uint16_t selector; // a code segment selector in GDT or LDT
    uint8_t zero;      // unused, set to 0
    uint8_t type_attr;
    uint16_t offset16_31;
} __attribute__ ((packed));

// IDTR register
struct idtr {
    uint16_t limit;
    uint32_t size;
} __attribute__ ((packed));

struct idtr kidtr;
struct idtgate kidt[IDTSIZE];

void idt_initialize(void);
void idt_set_gate(uint8_t num,uint32_t offset,
        uint16_t selector, uint8_t type_attr);

#endif
