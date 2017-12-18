#include <stdint.h>
#include <kernel/i386/gdt.h>
#include <kernel/i386/tss.h>

#define GDT_MAX_ENTRY 16 // up to 2^13

struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
};


static struct gdt_entry gdt[GDT_MAX_ENTRY];


extern void gdt_flush(struct gdt_entry*, uint16_t size);

/* Setup a descriptor in the Global Descriptor Table */
static void fill_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
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
    fill_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Kernel's code selector (0x08)
    fill_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Kernel's data selector (0x10)


    fill_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User's code selector (0x18)
    fill_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User's data selector (0x20)

    void* addr = tss_setup(0x10);
    fill_entry(5, (unsigned long) addr,
              (unsigned long) addr + sizeof(struct tss_entry_t),
               0xE9, 0x0); // TSS

    // say to the processor to use the gdt
    gdt_flush(gdt, sizeof(gdt) - 1);
    tss_flush(0x2B);
}
