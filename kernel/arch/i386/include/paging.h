#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>

#define PAGING_PRESENT 0x1
#define PAGING_RW 0x2
#define PAGING_USER 0x4
#define PAGING_WRITE_THROUGH 0x8
#define PAGING_DISABLE_CACHE 0x10
#define PAGING_ACCESSED 0x20
#define PAGING_GLOBAL 0x80
#define PAGING_4KB_MASK 0xFFFFF000

typedef uint32_t page_directory_t;
typedef uint32_t page_entry_t;


void paging_setup_directory(uint32_t entry_nb, page_directory_t dir);
void paging_init();
page_entry_t* find_next_empty_page(page_directory_t*);

#endif /* ifndef PAGING_H */
