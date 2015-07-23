#include <stdint.h>
#include <string.h>

#include <kernel/gdt.h>


/** setup a gdt table with wanted values 
 * a GDT table already exist but we create our own one
 * */
void gdt_initialize()
{
    // initialisation of segment descriptors
    gdt_initialize_desc(0x0, 0x0, 0x0, 0x0, &kgdt[0]);
    gdt_initialize_desc(0x0, 0xFFFFFF, 0x9B, 0x0D, &kgdt[1]); //code
    gdt_initialize_desc(0x0, 0xFFFFFF, 0x93, 0x0D, &kgdt[2]); //data
    gdt_initialize_desc(0x0, 0x0, 0x97, 0x0D, &kgdt[3]); //stack

    kgdtr.limit = GDTSIZE * 8;
    kgdtr.base = &kgdt;


    /* change gdt register */
    asm("lgdtl (kgdtr)");

    /* segment setup */
    asm("   movw $0x10, %ax \n \
            movw %ax, %ds       \n \
            movw %ax, %es       \n \
            movw %ax, %fs       \n \
            movw %ax, %gs       \n \
            movw %ax, %ss       \n \
            jmp $0x08, $next   \n \
            next:               \n");
}

void gdt_initialize_desc(uint32_t base,
        uint32_t limit,uint8_t access,
        uint8_t flags,struct gdtdesc *desc)
{
    desc->lim0_15 = (limit & 0xFFFF);
    desc->base0_15 = (base & 0xFFFF);
    desc->base16_23 = (base & 0xFF0000) >> 16;
    desc->access = access;
    desc->lim16_19 = (limit & 0x0F0000) >> 16;
    desc->flags = (flags & 0xf);
    desc->base24_31 = (base & 0xFF000000) >> 24;

    return;
}
