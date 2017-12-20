#include <kernel/scheduler.h>

#include <kernel/i386/asm/regs.h>
#include <kernel/i386/paging.h>
#include <kernel/i386/memory_management.h>
#include <kernel/process.h>
#include <kernel/kcall.h>
#include <kernel/kcall_no.h>

#include <libk/string.h>
#include <libk/stdlib.h>
#include <libk/utils.h>

static process_t *current_process = NULL;

process_t *get_current_process(){
    return current_process;
}

void scheduler_add(void* entry_point){
    process_t *process = calloc(1, sizeof(process_t));

    if(current_process != NULL){
        process->next = current_process->next;
        current_process->next = process;
    }
    else{
        current_process = process;
        process->next = process;
    }

    process->cr3 = heap_get_free_block();
    paging_map_page_kernel(process->cr3, process->cr3);

    process->regs.useresp = (uint32_t)((uint8_t*) heap_get_free_block() +
                                    HEAP_BLOCK_SIZE - 1);
    paging_map_page((void*)process->regs.useresp,
                    (void*)process->regs.useresp,
                    (page_directory_t*)process->cr3,
                    PAGING_USER | PAGING_RW | PAGING_PRESENT);
    paging_map_page_kernel((void*)process->regs.useresp,
                    (void*)process->regs.useresp);

    process->regs.ss = process->regs.ds
                     = process->regs.fs
                     = process->regs.es
                     = process->regs.gs
                     = 0x23;

    process->regs.cs = 0x1B;

    process->regs.eip = (uint32_t)entry_point;
    paging_fill_kernel_page(process->cr3,
            PAGING_USER | PAGING_RW | PAGING_PRESENT);

}

void scheduler_start(){
    current_process->running = 1;
    process_jump((void*)current_process->regs.eip,
                 current_process->cr3,
                 (void*)current_process->regs.useresp);
    for(;;);
}


void scheduler_next(struct regs* regs, void* args){
    UNUSED(args);

    memcpy(&current_process->regs, regs, sizeof(struct regs));
    current_process->running = 0;

    current_process = current_process->next;

    current_process->running = 1;
    current_process->regs.esp = regs->esp;
    memcpy(regs, &current_process->regs, sizeof(struct regs));
}

void scheduler_init(){
   kcall_handler_install(KCALL_YIELD, &scheduler_next);
}
