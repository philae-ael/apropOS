#include <kernel/i386/memory_management.h>
#include <logging.h>
#include <string.h>

heap_entry_t heap_map[1024 * 1024]; // One Mo

void* heap_addr_from_index(size_t index){
    return (void*) (index << 12);
}

heap_entry_t* heap_entry(void* addr){
    return &heap_map[(size_t)addr >> 12];
}

void heap_map_add_entry(size_t* base_addr, size_t length, uint8_t reserved);
void set_kernel_mem_used();

void heap_init(multiboot_memory_map_t* mmap_base_addr, size_t mmap_length){
    multiboot_memory_map_t* mmap;
    /*WARNING I drop base_addr_high (because of 32bits mode)*/

    debugf_func("mmap_addr %X, mmap_length %X", mmap_base_addr, mmap_length);

    memset(heap_map, 1, sizeof(heap_map));

    for(mmap = mmap_base_addr;
        (uint32_t)mmap < (uint32_t) mmap_base_addr + mmap_length;
        mmap += 1) {

        debugf_func("mmap %X at %X of length %X, type %X",
                mmap, mmap->base_addr_low, mmap->length_low, mmap->type);
        heap_map_add_entry((size_t*)mmap->base_addr_low, mmap->length_low, mmap->type);
    }

    set_kernel_mem_used();

    size_t memory_size;
    for (int i = 0; i < 1024*1024; ++i) {
        if(!heap_map[i].reserved)
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

void heap_map_add_entry(size_t* base_addr, size_t length, uint8_t type){
    if(((size_t)base_addr & 0xFFFFF000) != (size_t)base_addr)
        base_addr = (size_t*) ((((size_t)base_addr >> 12) - 1) << 12);

    for (size_t i = (size_t) base_addr >> 12;
         i < ((size_t) base_addr + length) >> 12;
         i++) { // 4k aligned
        heap_map[i].used = 0;
        heap_map[i].reserved = (type == 1) ? 0 : 1;
        heap_map[i].magic = HEAP_FLAGS_MAGIC;
    }
}

void* heap_get_free_block(){
    for (int i = 0; i < 1024 * 1024; ++i) {
        if(heap_map[i].used == 0 && heap_map[i].reserved == 0 && heap_map[i].magic == HEAP_FLAGS_MAGIC){
            heap_map[i].used = 1;
            return heap_addr_from_index(i);
        }
    }
}

void heap_return_block(void* addr){
    memset((void*)((size_t)addr & (size_t)0xFFFFF000)
            , 4096, 0);
    heap_entry_t* entry = heap_entry(addr);
    entry->used = 0;
}
