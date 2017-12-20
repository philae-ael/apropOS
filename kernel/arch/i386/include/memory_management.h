#ifndef MEM_MANAGEMENT_H
#define MEM_MANAGEMENT_H
#include <stdint.h>
#include <stddef.h>

#include <kernel/i386/multiboot.h>
#include <kernel/i386/paging.h>

#define HEAP_BLOCK_SIZE PAGE_SIZE
#define HEAP_FLAGS_MAGIC 0xA

typedef struct{
    // We can have up to 6 fields ! No more
    uint8_t used :1;
    uint8_t reserved :1;
    uint8_t magic:4;
    uint8_t unused:2;
} heap_entry_t;

void* heap_addr_from_index(size_t);
heap_entry_t* heap_entry(void* addr);
void heap_init(multiboot_memory_map_t*, size_t mmap_length);
void* heap_get_free_block(void);
void* heap_get_free_blocks(int blocks);

#endif /* ifndef MEM_MANAGEMENT_H */
