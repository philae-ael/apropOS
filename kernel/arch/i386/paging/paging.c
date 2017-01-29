#include <stdint.h>

#include <asm/regs.h>

#define PAGE_NUMBER 0x400  // 4Mb
#define DIRECTORY_NUMBER 0x400

typedef uint32_t page_directory_entry_t;
typedef uint32_t page_table_t;


page_table_t *page_tables = 0x1000;
page_directory_entry_t *page_directories= 0x2000;

void page_init(){

    uint32_t address = 0; // holds the physical address of where a page is
    uint32_t i;

    // map the first 4MB of memory
    for(i=0; i<PAGE_NUMBER; i++)
    {
        page_tables[i] = address | 3; // attribute set to: supervisor level, read/write, present(011 in binary)
        address += 4096; // 4kb
    }
    page_directories[0] = page_tables;
    page_directories[0] = page_directories[0] | 3; // attribute set to: supervisor level, read/write, present(011 in binary)


    for(i=1; i<DIRECTORY_NUMBER; i++)
    {
        page_directories[i] = 0 | 2; // attribute set to: supervisor level, read/write, not present(010 in binary)
    }
    write_cr3(page_directories);
    write_cr0(read_cr0() | 0x80000000);
}
