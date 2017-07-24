#include <kernel/i386/idt.h>
#include <kernel/kcall.h>

extern void kcall_asm_handler();

void _kcall_init(){
    idt_set_gate(0x80, (uint32_t)kcall_asm_handler, 0x8, 0x8E);
}
