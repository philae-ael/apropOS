#ifndef IDT_H
#define IDT_H

#include <stdint.h>
#include <stdbool.h>

#define IDT_ATTR_PRESENT(x) ((x) << 0x7)
#define IDT_ATTR_DPL(x) (((x) & 0x3) << 0x5) // minimal ring (0-3) for being able to call gate
#define IDT_ATTR_STORAGE(x) ((x) << 0x4) // 0 for interupt
#define IDT_ATTR_GATE_TASK_32 0x5
#define IDT_ATTR_GATE_INTERRUPT_16 0x6
#define IDT_ATTR_GATE_TRAP_16 0x7
#define IDT_ATTR_GATE_INTERRUPT_32 0xE
#define IDT_ATTR_GATE_TRAP_32 0xF


#define IDT_INTERRUPT_32 \
        IDT_ATTR_PRESENT(1) |\
        IDT_ATTR_DPL(0) |\
        IDT_ATTR_STORAGE(0) |\
        IDT_ATTR_GATE_INTERRUPT_32

#define IDT_TRAP_32 \
        IDT_ATTR_PRESENT(1) |\
        IDT_ATTR_DPL(0) |\
        IDT_ATTR_STORAGE(0) |\
        IDT_ATTR_GATE_TRAP_32

#define IDT_SIZE 0xFF // nbr max of descriptors

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
struct idtgate kidt[IDT_SIZE];

bool idt_initialize();
void idt_set_gate(uint8_t index, uint32_t offset, uint16_t selector, uint8_t type_attr);

#endif
