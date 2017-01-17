#include <pit.h>
#include <irq.h>
#include <asm/regs.h>

#include <stdio.h>

#define PIT_IRQ 0

int timer_ticks;

void pit_handler(struct regs* r){
    timer_ticks++;
}

void pit_init(){
    irq_handler_install(PIT_IRQ, pit_handler);
    irq_mask(PIT_IRQ);
}
