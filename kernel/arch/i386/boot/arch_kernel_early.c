#include <i386/gdt.h>

void arch_kernel_early()
{
    gdt_initialize();
}
