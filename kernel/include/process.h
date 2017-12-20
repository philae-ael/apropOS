#ifndef USERLAND_H
#define USERLAND_H

#include <stddef.h>
#include <kernel/i386/paging.h>
#include <kernel/i386/asm/regs.h>

#define MAX_PROCESS 256

typedef struct process{
    struct process* next;
    struct regs regs;
    void* cr3;
    uint8_t running :1;
    uint32_t unused :31;

} process_t;

void process_jump(void* entry_point, void* cr3, void* useresp);
process_t *get_current_process(void);

#endif /* ifndef USERLAND_H */
