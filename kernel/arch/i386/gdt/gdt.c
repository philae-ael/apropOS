#include <stdint.h>
#include <gdt.h>

#define GDT_MAX_ENTRY 16 // up to 2^13

struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));


struct gdt_entry gdt[GDT_MAX_ENTRY];


extern void gdt_flush(struct gdt_entry*, uint16_t size);

/* Setup a descriptor in the Global Descriptor Table */
void fill_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void gdt_init(){
    fill_entry(0, 0, 0, 0, 0); // Null selector (0x0), cannot be used
    fill_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code selector (0x08)
    fill_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data selector (0x10)

    // say to the processor to use the gdt
    gdt_flush(gdt, sizeof(gdt));
}
