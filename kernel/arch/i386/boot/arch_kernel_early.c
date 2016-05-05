#include <i386/gdt.h>

void arch_kernel_early()
{
    gdt_add_entry(0,0x00FFFF, 15, 12, 0);
}
