#ifndef KCALL_H
#define KCALL_H

#define KCALL_MAX_HANDLERS 256

#include <stdint.h>

void* kcall(uint32_t call_code, void* args);

void kcall_init();
void _kcall_init();

void* kcall_handler(uint32_t call_coder, void* args);
void kcall_handler_install(uint32_t kcall_nb, void* (*handler)(void*));
void kcall_handler_uninstall(uint32_t kcall_nb);
#endif /* ifndef KCALL_H */
