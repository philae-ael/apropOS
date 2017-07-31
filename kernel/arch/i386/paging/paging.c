#include <kernel/i386/paging.h>
#include <kernel/i386/memory_management.h>

#include <string.h>

#include <logging.h>

page_directory_t *page_directory_kernel;

extern void enable_paging(page_directory_t*);

extern void* start_kernel;
extern void* end_kernel;

int paging_map_page(void* physic_addr, void* virtual_addr, page_directory_t* page_directory, uint32_t flags){
    size_t page_directory_index = (size_t) virtual_addr >> 22;
    size_t page_entry_index = (size_t) virtual_addr >> 12 & 0x03FF;

    /* debugf_func("Mapping virtual_addr %X to physic_addr %X on page_directory located on %X with flags %X", physic_addr, virtual_addr, page_directory, flags); */
    /* debugf_func("Page directory index %d Page entry index %d", page_directory_index, page_entry_index); */

    page_entry_t* page = (page_entry_t*) ((size_t) *(page_directory + page_directory_index) & PAGING_4KB_MASK);

    if(page == 0){
        page = heap_get_free_block();

        debugf_func("New page created at %X ", page);

        if(page == (void*) -1)
            return -1;
        *(page_directory + page_directory_index) = (page_entry_t) flags;
        *(page_directory + page_directory_index) |= (page_entry_t) page;
    }

    if(*(page + page_entry_index) & PAGING_PRESENT == 0)
        return -1;

    *(page + page_entry_index) = (page_entry_t) flags;
    *(page + page_entry_index) |= (page_entry_t) physic_addr & PAGING_4KB_MASK;

}

void fill_kernel_page(){
    for (size_t addr = (size_t)&start_kernel;
            addr < (size_t)&end_kernel;
            addr += 4096) {
        paging_map_page((void*)addr,
                (void*)addr,
                page_directory_kernel,
                PAGING_PRESENT |
                PAGING_RW);
    }
}

void paging_init(){
    // OK because blocks are 4kb aligned and 4kb long
    page_directory_kernel = (page_directory_t*) heap_get_free_block();

    memset(page_directory_kernel, 0 , 1024 * sizeof(page_directory_t));

    debugf_func("page_directory at %X", page_directory_kernel);

    fill_kernel_page();
    enable_paging(page_directory_kernel);

}
