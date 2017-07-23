#ifndef IDT_H
#define IDT_H

#include <stdint.h>

/* idt_init
 * Initialize an empty IDT and tell the system where find it
 * */
void idt_init();

/* idt_set_gate
 * Add an gate for an idt
 * Args:
 *  - num: The number of the interrupt (up to 255)
 *  - base: Entry point of the interrupt
 *  - sel: A code selector in GDT or LDT.
 *         Warning ! It has to be ring 0 (because of iret).
 *  - flags: all other flags. See on http://wiki.osdev.org/Interrupt_Descriptor_Table
 * */
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

#endif /* ifndef IDT_H */
