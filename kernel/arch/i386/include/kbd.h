#ifndef KDB_H
#define KDB_H
#include <asm/regs.h>

void kbd_wait();
void kbd_handler(struct regs* r);
void kbd_reset();
void kbd_init();

#endif /* ifndef KDB_H */

