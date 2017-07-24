#ifndef IRQ_H
#define IRQ_H

#include <kernel/i386/asm/regs.h>
#include <stdint.h>
#define PIC1        0x20        /* IO base address for master PIC */
#define PIC2        0xA0        /* IO base address for slave PIC */
#define PIC1_COMMAND    PIC1
#define PIC1_DATA    (PIC1+1)
#define PIC2_COMMAND    PIC2
#define PIC2_DATA    (PIC2+1)

#define ICW1_ICW4    0x01        /* ICW4 (not) needed */
#define ICW1_SINGLE    0x02        /* Single (cascade) mode */
#define ICW1_INTERVAL4    0x04        /* Call address interval 4 (8) */
#define ICW1_LEVEL    0x08        /* Level triggered (edge) mode */
#define ICW1_INIT    0x10        /* Initialization - required! */

#define ICW4_8086    0x01        /* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO    0x02        /* Auto (normal) EOI */
#define ICW4_BUF_SLAVE    0x08        /* Buffered mode/slave */
#define ICW4_BUF_MASTER    0x0C        /* Buffered mode/master */
#define ICW4_SFNM    0x10        /* Special fully nested (not) */


#define PIC_EOI        0x20        /* End-of-interrupt command code */

/* irq_init
 * Initialize IRQs, adding handlers in IDT and remap IRQs.
 * Have to be called before any other functions in this file.
 * Warning, IDT must have be initialized before.
 * */
void irq_init();

/* irq_handler_install
 * Allow to add a custom handler.
 * Args:
 *  - irq_nb the num of the irq. (see http://wiki.osdev.org/Interrupts#General_IBM-PC_Compatible_Interrupt_Information) for basic IRQs.
 * This function don't unmask the interrupt.
 * */
void irq_handler_install(uint8_t irq_nb, void(*handler)(struct regs*));

/* irq_handler_uninstall
 * Remove previously installed handler.
 * This function don't mask the interrupt
 * */
void irq_handler_uninstall(uint8_t irq_nb);

/* irq_mask
 * Mask the IRQ.
 * Args:
 *  - irq_nb: The numero of the IRQ to mask
 * */
void irq_mask(uint8_t irq_nb);
/* irq_unmask
 * Unmask the IRQ.
 * Args:
 *  - irq_nb: The numero of the IRQ to unmask
 * */
void irq_unmask(uint8_t irq_nb);

/* irq_mask_all
 * Mask all IRQs.
 * */
void irq_mask_all();
#endif /* ifndef IRQ_H */
