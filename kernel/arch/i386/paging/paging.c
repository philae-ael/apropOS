#include <kernel/i386/paging.h>
#include <kernel/i386/memory_management.h>

#include <string.h>

#include <logging.h>

page_directory_t* page_directory;
page_table_t* page_table_kernel;

extern void enable_paging(page_directory_t*);

void fill_kernel_page(){
    // physical = logical memory
    for (int i = 0; i < 1024; ++i) {
        // paging present, R/W, supervisor only
        page_table_kernel[i] = 0x7;
        page_table_kernel[i] |= (i << 12);

//        debugf_func("%X %X %d", page_table_kernel, page_table_kernel[i], i);
    }
}

void paging_init(){
    // OK because blocks are 4kb aligned and 4kb long
    page_directory = (page_directory_t*) heap_get_free_block();
    page_table_kernel = (page_table_t*) heap_get_free_block();

    page_directory_t kernel_dir = 0x7;
    kernel_dir |= (size_t) page_table_kernel;

    paging_setup_directory(0, kernel_dir);

    debugf_func("page_directory at %X  page_table_kernel at %X", page_directory, page_table_kernel);


    fill_kernel_page();
    enable_paging(page_directory);

}

void paging_setup_directory(uint32_t entry_nb, page_directory_t dir){
    if(entry_nb < 1024)
        page_directory[entry_nb] = dir;

}
