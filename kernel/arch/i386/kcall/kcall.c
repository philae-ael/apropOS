#include <kernel/i386/idt.h>
#include <kernel/i386/paging.h>
#include <kernel/process.h>
#include <kernel/i386/asm/regs.h>
#include <kernel/kcall.h>

extern void kcall_asm_handler(void);

void _kcall_handler(struct regs *regs, void* args);
void _kcall_handler(struct regs *regs, void* args){
    set_kernel_page_dir();
    kcall_handler(regs->int_no, regs, args);
    set_page_dir(get_current_process()->cr3);
}

void _kcall_init(void){
    idt_set_gate(0x80, (uint32_t)kcall_asm_handler, 0x8, 0xEF);
}
