#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include <i386/asm/asm.h>

#include <i386/gdt.h>

void gdt_initialize_desc(uint32_t base,
        uint32_t limit,uint8_t access,
        uint8_t flags,struct gdtdesc *desc)
{
    desc->lim0_15 = (limit & 0xFFFF);
    desc->base0_15 = (base & 0xFFFF);
    desc->base16_23 = (base & 0xFF0000) >> 16;
    desc->access = access;
    desc->lim16_19 = (limit & 0x0F0000) >> 16;
    desc->flags = (flags & 0xF);
    desc->base24_31 = (base & 0xFF000000) >> 24;
    return;
}

void gdt_initialize(){

    kgdtr.base = (uint32_t)&kgdtdesc;
    kgdtr.size = GDT_SIZE * 8;

    //Fill GDT describtors
    gdt_initialize_desc(0x0,0x0     , 0x0,  0x0,  &kgdtdesc[0]);
    gdt_initialize_desc(0x0,0xFFFFFF,
            SEG_PRES(1)     |
            SEG_PRIV(0)     |
            SEG_DESCTYPE(1) |
            SEG_CODE_EXRDA,
            SEG_GRAN(1) |
            SEG_SIZE(1) |
            SEG_LONG(0) |
            SEG_SAVL(0),
            &kgdtdesc[1]); // code

    gdt_initialize_desc(0x0,0xFFFFFF,
            SEG_PRES(1)     |
            SEG_PRIV(0)     |
            SEG_DESCTYPE(1) |
            SEG_DATA_RDWRA,
            SEG_GRAN(1) |
            SEG_SIZE(1) |
            SEG_LONG(0) |
            SEG_SAVL(0),
            &kgdtdesc[2]); //data

    gdt_initialize_desc(0x0,0x0,
            SEG_PRES(1)     |
            SEG_PRIV(0)     |
            SEG_DESCTYPE(1) |
            SEG_DATA_RDWREXPDA,
            SEG_GRAN(1) |
            SEG_SIZE(1) |
            SEG_LONG(0) |
            SEG_SAVL(0),
            &kgdtdesc[3]); //stack

    //load the new gdt
    asm("lgdt [kgdtr]");

    // setup segmentation
    asm("   mov ax, 0x10 \n \
            mov ds, ax   \n \
            mov es, ax   \n \
            mov fs, ax   \n \
            mov gs, ax   \n \
            mov ss, ax   \n \
            jmp 0x08:next\n \
            next:        \n");
    return;
}
