#include <kernel/userland.h>
#include <kernel/i386/memory_management.h>
#include <kernel/i386/paging.h>
#include <stdint.h>

#include <libk/string.h>
#include <libk/logging.h>

static process_list_t process_list[MAX_PROCESS];

extern void _userland_jump(page_directory_t*, void (*func)(void));

void userland_init(){
    memset(process_list, 0, sizeof(process_list));
}

void userland_jump(uint32_t process_id, void (*func)(void)){
    if(process_list[process_id].running == 1)
        return;

    process_list[process_id].running = 1;


    debugf_func("Jumping to userland at address %X", func);
    _userland_jump(process_list[process_id].page_dir, func);

    process_list[process_id].running = 0;
}

uint16_t userland_add_process(uint8_t user_id){
    uint16_t process_id;
    for (process_id = 1;
            process_id < MAX_PROCESS + 1;
            ++process_id)
        if(process_list[process_id].used == 0){
            process_id --;
            goto success;
        }

    return 0; // No available process

success:
    process_list[process_id].page_dir = (page_directory_t*)heap_get_free_block();
    paging_map_page_kernel(
            process_list[process_id].page_dir,
            process_list[process_id].page_dir);

    memset(process_list[process_id].page_dir, 0 , 1024 * sizeof(page_directory_t));

    debugf_func("Got page dir at %X for user %d", process_list[process_id].page_dir,
            user_id);

    paging_fill_kernel_page(process_list[process_id].page_dir,
            PAGING_USER | PAGING_PRESENT | PAGING_RW );

    process_list[process_id].used = 1;
    process_list[process_id].user_id = user_id;
    process_list[process_id].process_id = process_id;

    return process_id;
}
