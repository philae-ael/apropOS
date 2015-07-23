#ifndef GDT_H
#define GDT_H
#include <stdint.h>

#define GDTBASE 0x0//where will be the gdt table
#define GDTSIZE 0xFF //nbr max of descriptors


// Segment descriptor CF:http://wiki.osdev.org/Global_Descriptor_Table for further informations
struct gdtdesc {
    uint16_t lim0_15;    
    uint16_t base0_15;
    uint8_t base16_23;
    uint8_t access;
    uint8_t lim16_19 : 4;
    uint8_t flags : 4;
    uint8_t base24_31;
} __attribute__ ((packed));

/* GDTR register */
struct gdtr {
    uint16_t limit ;
    uint32_t base ;
} __attribute__ ((packed));

struct gdtr kgdtr;
struct gdtdesc kgdt[GDTSIZE];

void gdt_initialize(void);
void gdt_initialize_desc(uint32_t base,
        uint32_t limit,uint8_t access,
        uint8_t flags,struct gdtdesc *desc);

#endif
