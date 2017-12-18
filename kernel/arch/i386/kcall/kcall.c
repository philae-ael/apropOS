#include <kernel/i386/idt.h>
#include <kernel/i386/asm/regs.h>
#include <kernel/kcall.h>

extern void kcall_asm_handler(void);

void _kcall_handler(struct regs *regs, void* args);
void _kcall_handler(struct regs *regs, void* args){
    (void)regs;
    (void)args;
}

void _kcall_init(){
    idt_set_gate(0x80, (uint32_t)kcall_asm_handler, 0x8, 0xEF);
}
