#include <memory_management.h>
#include <logging.h>


extern mem_block* end_kernel; // declared in linker file

mem_block* mem_init_block(mem_block* block, size_t block_length, mem_block* prev);

void mem_management_init(multiboot_memory_map_t* mmap_base_addr, size_t mmap_length){
    multiboot_memory_map_t* mmap;
    mem_block* prev = NULL;

    /*WARNING I drop base_addr_high (because of 32bits mode)*/

    debug_func("mmap_addr %X, mmap_length %X", mmap_base_addr, mmap_length);

    for(mmap = mmap_base_addr;
        mmap < (uint32_t)mmap_base_addr + mmap_length;
        mmap += 1) {

        debug_func("mmap %X at %X of length %X, type %X",
                mmap, mmap->base_addr_low, mmap->length_low, mmap->type);

        if(mmap->type == 1 && mmap->length_low > MIN_BLOCK_BYTES_SIZE)
            prev = mem_init_block(mmap->base_addr_low, mmap->length_low, prev);
    }

}

mem_block* mem_init_block(mem_block* block, size_t block_length, mem_block* prev){
    debug_func("Adding block %X of length %X, prev is %X", block, block_length, prev);
    block->size = block_length - sizeof(mem_block);
    block->prev = prev;
    block->flags = 0x1; // Free, EOM (until we add a block after him), not adjacent with next_block

    if(prev){
        // update prev block with new infos
        prev->next = block;
        prev->flags |= 0x2; // No more EOM
        prev->maybe_next_free = block;
    }
    else{// First block
        mem_first_free = mem_first = block;
    }

    return block;
}

void mem_block_merge(mem_block* block){
    if(block->next == NULL)
        return;
    if((block->flags & 1) == 0)
        return;

    // All condition are OK
    // Starting merging
    block->next->next->prev = block;
    block->size = block->size + block->next->size + sizeof(mem_block);

}

void mem_block_split(mem_block* free_block, size_t size){
    debug_func("free block %X, size header %d, size %d, maybe_next_free %X", free_block, sizeof(mem_block), size, &free_block->maybe_next_free);

    debugf("%X + %X + %X ", free_block, sizeof(mem_block), size);
    mem_block* next_block = free_block + sizeof(mem_block) + size; // get location of next block
    next_block->flags = free_block->flags;
    next_block->next = free_block->prev;

    free_block->next->prev = next_block;
    free_block->next = next_block;


    free_block->maybe_next_free = next_block;

    debug_func("next block %X, size header %d, size %d, maybe_next_free %X", next_block, sizeof(mem_block), size, &next_block->maybe_next_free);
}

void mem_block_set_used(mem_block* prev_free_block, mem_block* free_block, size_t size){
    // if(free_block->size - size >= MIN_BLOCK_BYTES_SIZE)
    mem_block_split(free_block, size);

    free_block->flags ^= 1; // no more free

    // restore freed linked list
    if(prev_free_block)
        prev_free_block->maybe_next_free = free_block->maybe_next_free;
    else
        mem_first_free = free_block->maybe_next_free;

    free_block->maybe_next_free = 0;
}
