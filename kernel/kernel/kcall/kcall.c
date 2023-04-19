#include <kernel/kcall.h>

#include <libk/string.h>
#include <libk/logging.h>
#include <stdint.h>

static void (*handlers[KCALL_MAX_HANDLERS])(struct regs*, void*);

void kcall_init(void){
    memset(handlers, 0, sizeof(handlers));
    _kcall_init();
}


void kcall_handler_install(uint32_t kcall_nb, void (*handler)(struct regs*, void*)){
    if(kcall_nb < KCALL_MAX_HANDLERS)
        handlers[kcall_nb] = handler;
}
void kcall_handler_uninstall(uint32_t kcall_nb){
    if(kcall_nb < KCALL_MAX_HANDLERS)
        handlers[kcall_nb] = 0;
}

void kcall_handler(uint32_t kcall_nb, struct regs* regs, void* args){
    if(kcall_nb < KCALL_MAX_HANDLERS && handlers[kcall_nb])
        handlers[kcall_nb](regs, args);
}
