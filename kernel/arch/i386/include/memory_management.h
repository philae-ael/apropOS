#ifndef MEM_MANAGEMENT_H
#define MEM_MANAGEMENT_H
#include <stdint.h>
#include <stddef.h>

#include <kernel/i386/multiboot.h>

#define HEAP_FLAGS_MAGIC 0xA

typedef struct{
    // We can have up to 6 fields ! No more
    uint8_t used :1;
    uint8_t reserved :1;
    uint8_t magic:4;
} heap_entry_t;

void* heap_addr(heap_entry_t*);
void heap_init(multiboot_memory_map_t*, size_t mmap_length);

#endif /* ifndef MEM_MANAGEMENT_H */
