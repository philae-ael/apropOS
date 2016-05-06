#ifndef IRQ_H
#define IRQ_H

#include <stdbool.h>
#include <stdint.h>
#include <i386/asm/regs.h>

#define PIC_MASTER_CONTROL_PORT  0x20
#define PIC_MASTER_DATA_PORT     0x21
#define PIC_SLAVE_CONTROL_PORT   0xA0
#define PIC_SLAVE_DATA_PORT      0xA1

#define PIC_EOI 0x20 //End of interrupt

#define ICW1_ICW4       0x01
#define ICW1_SINGLE     0x02
#define ICW1_INTERVAL4  0x04
#define ICW1_LEVEL      0x08
#define ICW1_INIT       0x10

#define ICW4_8086       0x01
#define ICW4_AUTO       0x02
#define ICW4_BUF_SLAVE  0x08
#define ICW4_BUF_MASTER 0x0C
#define ICW4_SFNM       0x10

bool irq_initialize();
void irq_set_handler(uint8_t irq, void (*) (struct regs*));
void irq_handler(struct regs* r);
void PIC_remap(uint8_t offset1, uint8_t offset2); // Remap IRQs 0..7 to offset1..offset1+7 and IRQs 8..15 to offset2..offset2+7
void PIC_sendEOI(uint8_t irq); // Have to be calles after received an IRQ
void PIC_disable();
void IRQ_mask(uint8_t irq, bool mask);
#endif
