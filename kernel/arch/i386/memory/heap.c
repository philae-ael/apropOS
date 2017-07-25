#include <kernel/i386/memory_management.h>
#include <logging.h>
#include <string.h>

heap_entry_t heap_map[1024 * 1024]; // One Mo

void* heap_addr(heap_entry_t* entry){
    return (void*)((
                (entry - heap_map) / sizeof(heap_entry_t)) // get index in heap_map
            << 12);
}

heap_entry_t* heap_entry(void* addr){
    return &heap_map[(size_t)addr >> 12];
}

void heap_map_add_entry(size_t* addr, size_t length, uint8_t reserved);
void set_kernel_mem_used();

void heap_init(multiboot_memory_map_t* mmap_base_addr, size_t mmap_length){
    multiboot_memory_map_t* mmap;
    /*WARNING I drop base_addr_high (because of 32bits mode)*/

    debugf_func("mmap_addr %X, mmap_length %X", mmap_base_addr, mmap_length);

    memset(heap_map, 0, sizeof(heap_map));

    for(mmap = mmap_base_addr;
        (uint32_t)mmap < (uint32_t) mmap_base_addr + mmap_length;
        mmap += 1) {

        debugf_func("mmap %X at %X of length %X, type %X",
                mmap, mmap->base_addr_low, mmap->length_low, mmap->type);

        heap_map_add_entry((size_t*)mmap->base_addr_low, mmap->length_low,
                (mmap->type == 1) ? 1 : 0);
    }

    set_kernel_mem_used();

    size_t memory_size;
    for (int i = 0; i < 1024*1024; ++i) {
        if(heap_map[i].reserved)
            memory_size += 4096;
    }
    debugf("Available heap: %X", memory_size);

}

extern void* start_kernel;
extern void* end_kernel;

void set_kernel_mem_used(){
    heap_entry_t* entry_kernel_start;
    heap_entry_t* entry_kernel_end;

    entry_kernel_start = heap_entry(&start_kernel);
    entry_kernel_end = heap_entry(&end_kernel);

    debugf("Kernel is positioned between %X and %X", &start_kernel, &end_kernel);

    for (heap_entry_t* current_entry = entry_kernel_start;
            current_entry < entry_kernel_end;
            current_entry++) {
        current_entry->used = 1;
    }

}

void heap_map_add_entry(size_t* base_addr, size_t length, uint8_t reserved){
    for (size_t i = (size_t) base_addr >> 12;
         i < ((size_t) base_addr + length) >> 12;
         i++) { // 4k aligned
        heap_map[i].used = 0;
        heap_map[i].reserved = reserved;
        heap_map[i].magic = HEAP_FLAGS_MAGIC;
    }
}
