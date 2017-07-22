#ifndef REGS_H
#define REGS_H

#include <stdint.h>

struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */
};

void log_regs(struct regs* r);
uint32_t read_cr3();
uint32_t read_cr0();
void write_cr0(uint32_t);
void write_cr3(uint32_t);

#endif /* ifndef REGS_H */
