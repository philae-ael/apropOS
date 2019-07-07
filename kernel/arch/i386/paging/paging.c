#include <kernel/i386/paging.h>
#include <kernel/i386/memory_management.h>

#include <libk/string.h>
#include <libk/logging.h>

extern void enable_paging(void);

extern void* start_kernel;
extern void* end_kernel;

static page_directory_t* page_directory_kernel;
static page_directory_t* page_directory_userland;
static page_entry_t* page_reserve = (page_entry_t*) 0xdeadbeef;

void set_kernel_page_dir(){
    set_page_dir((void*) page_directory_kernel);
}

int paging_map_page(void* physic_addr, void* virtual_addr, page_directory_t* page_directory, uint32_t flags){

    if(page_reserve ==  (page_entry_t*) 0xdeadbeef){ // Set normally when paging is not set
        // Allow kernel to always have access to an empty page
        page_reserve = heap_get_free_block();
        paging_map_page_kernel(page_reserve, page_reserve); // identity map
    }

    size_t page_directory_index = (size_t) virtual_addr >> 22;
    size_t page_entry_index = (size_t) virtual_addr >> 12 & 0x03FF;

    page_entry_t* page = (page_entry_t*) ((size_t) *(page_directory + page_directory_index) & PAGING_4KB_MASK);

    if(page == 0){
        page = page_reserve;

        //debugf_func("New page created at %X ", page);

        if(page == (void*) -1)
            return -1;
        *(page_directory + page_directory_index) = (page_entry_t) flags;
        *(page_directory + page_directory_index) |= (page_entry_t) page;

        page_reserve = heap_get_free_block();
        paging_map_page(page_reserve, page_reserve,
                page_directory_kernel, PAGING_PRESENT | PAGING_RW);
    }

    *(page + page_entry_index) = (page_entry_t) flags;
    *(page + page_entry_index) |= (page_entry_t) physic_addr & PAGING_4KB_MASK;

    return 0;
}

int paging_map_page_kernel(void* physic_addr, void* virtual_addr){
    return paging_map_page(
            physic_addr, virtual_addr,
            page_directory_kernel,
            PAGING_PRESENT | PAGING_RW);
}

void paging_fill_kernel_page(page_directory_t *page_directory, uint32_t flags){
    // identity map, map everything
    for (size_t addr = (size_t)&start_kernel;
            addr < (size_t)&end_kernel;
            addr += 4096) {
        paging_map_page((void*)addr, (void*)addr, page_directory, flags);
    }

    // Console
    for (size_t addr = 0xb8000;
            addr <= 0xb9000;
            addr += 4096) {
        paging_map_page((void*)addr, (void*)addr, page_directory, flags);
    }
}

void paging_init(){
    // OK because blocks are 4kb aligned and 4kb long
    page_directory_kernel = (page_directory_t*) heap_get_free_block();
    memset(page_directory_kernel, 0 , 1024 * sizeof(page_directory_t));
    debugf_func("page_directory at %X", page_directory_kernel);

    // ID-maping Kernel space
    debug_func("ID-mapping kernel space");
    warn_func("only mapping one page! TODO: Correct this depending on kernel size");
    
    paging_map_page(
            (void*) page_directory_kernel,
            (void*) page_directory_kernel,
            page_directory_kernel,
            PAGING_PRESENT | PAGING_RW);

    paging_fill_kernel_page(page_directory_kernel, PAGING_PRESENT | PAGING_RW);

    debug_func("ID-mapping userland space");

    (void) page_directory_userland;
    
    set_kernel_page_dir();
    enable_paging();

}
