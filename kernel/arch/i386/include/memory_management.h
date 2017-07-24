#ifndef MEM_MANAGEMENT_H
#define MEM_MANAGEMENT_H
#include <stdint.h>
#include <stddef.h>

#include <multiboot.h>

#define MIN_BLOCK_BYTES_SIZE 64

typedef struct mem_block{
    /* flags
     * bit 0: free
     * bit 1: end of mem
     * bit 2: adjacent with next block (no hole in memory)
     * */
    uint8_t flags;
    size_t size;
    struct mem_block* maybe_next_free; // if this block is free, this is next free block, otherwise 0.
    struct mem_block* next;
    struct mem_block* prev;
} mem_block;

mem_block* mem_first_free;
mem_block* mem_first;

void mem_management_init(multiboot_memory_map_t*, size_t mmap_length);
void mem_block_merge(mem_block* block);
void mem_block_split(mem_block* free_block, size_t size);
void mem_block_set_used(mem_block* prev_free_block, mem_block* free_block, size_t size);


#endif /* ifndef MEM_MANAGEMENT_H */
