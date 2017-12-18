#include <stdint.h>
#include <stddef.h>
#include <logging.h>
#include <kernel/kcall.h>

#define _klibc

#ifdef _klibc
#include <kernel/i386/memory_management.h>
#endif

void* malloc(size_t size){
#ifdef _klibc
    // Only for the moment
    debugf_func("Will malloc %X bytes", size);
    mem_block* block_free = mem_first_free;
    mem_block* prev_free = NULL;

    while(block_free->maybe_next_free != block_free){
        debugf_func("Current block: size %X flags %X maybe_next_free %X prev %X next %X",
                block_free->size, block_free->flags,
                block_free->maybe_next_free, block_free->prev, block_free->next);
        if(block_free->size > size)
            goto block_find;
        prev_free = block_free;
        block_free = block_free->maybe_next_free;
    }
    goto error; // no block found

    mem_block_set_used(prev_free, block_free, size);
block_find:
    return (void*) block_free + sizeof(mem_block);

#else

#endif
error:
    debug_func("Error no place found");
    return NULL;
}

void free(void* addr){

}
