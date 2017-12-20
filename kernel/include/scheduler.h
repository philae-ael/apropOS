#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <kernel/i386/asm/regs.h>

void scheduler_init(void);
void __attribute__((noreturn)) scheduler_start(void);
void scheduler_add(void* entry_point);
void scheduler_next(struct regs*, void*);
//void schedule_tick(struct regs*);

#endif /* ifndef SCHEDULER_H */
