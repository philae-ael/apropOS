#ifndef KCALL_H
#define KCALL_H

#include <asm/regs.h>

#define KCALL_MAX_HANDLERS 256

void* kcall(uint32_t call_code, void* args);

void* kcall_handler(struct regs* r);
void kcall_handler_install(uint32_t kcall_nb, void(*handler)(struct regs*));
void kcall_handler_uninstall(uint32_t kcall_nb);
#endif /* ifndef KCALL_H */
