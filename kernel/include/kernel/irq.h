#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>
#include <stdbool.h>

#include <kernel/regs.h>

bool irq_initialize(void);

void irq_set_handler(uint8_t irq_number, void (*func) (struct regs*) );

void irq_handler(struct regs*);
#endif
