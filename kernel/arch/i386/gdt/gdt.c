#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include <i386/gdt.h>


uint64_t gdt_gen_entry(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags){
    uint64_t descriptor;

    //high 32 bits
    descriptor  = (base >> 16)  & 0x000000FF;
    descriptor |= (access << 8) & 0x0000FF00;
    descriptor |= limit         & 0x000F0000;
    descriptor |= (flags << 20) & 0x00F00000;
    descriptor |= base          & 0xFF000000;

    //Shift of 32 Bits
    descriptor <<= 32;

    // low 32 bits
    descriptor |= (base << 16)  & 0x0000FFFF;
    descriptor |= limit & 0xFFFF0000;

    return descriptor;
}

void gdt_add_entry(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags, uint8_t index){
    printf("%d", gdt_gen_entry(base,limit,access,flags));
    return;
}
