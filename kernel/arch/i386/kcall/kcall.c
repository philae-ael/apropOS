#include <asm/regs.h>
#include <idt.h>
#include <string.h>
#include <logging.h>
#include <kcall.h>

void(*handlers[KCALL_MAX_HANDLERS])(struct regs*);

extern void kcall_asm_handler();

void kcall_init(){
    idt_set_gate(0x80, (uint32_t)kcall_asm_handler, 0x8, 0x8E);
    memset(handlers, 0, sizeof(handlers));
}


void kcall_handler_install(uint32_t kcall_nb, void(*handler)(struct regs*)){
    if(kcall_nb < KCALL_MAX_HANDLERS)
        handlers[kcall_nb] = handler;
}
void kcall_handler_uninstall(uint32_t kcall_nb){
    if(kcall_nb < KCALL_MAX_HANDLERS)
        handlers[kcall_nb] = 0;
}

void* kcall_handler(struct regs* r){
    debug_func("GOT IT! %X", r);
    if(r->eax < KCALL_MAX_HANDLERS && handlers[r->eax])
        handlers[r->eax](r);

    return (void*) 0xDEADBEEF;
}
