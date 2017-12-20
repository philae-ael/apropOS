#include <kernel/i386/memory_management.h>
#include <kernel/i386/paging.h>
#include <libk/stdio.h>
#include <libk/stdlib.h>
#include <libk/logging.h>

int liballoc_lock(){
    warn_func("No lock?");
    return 0;
}

int liballoc_unlock(){
    warn_func("No unlock?");
    return 0;
}

void* liballoc_alloc(size_t pages) {
    void *p2 = heap_get_free_blocks((int)pages);
    paging_map_page_kernel(p2, p2);
    return p2;
}

int liballoc_free(void* ptr, size_t pages){
    warn_func("No free ?");
    return 0;
}



