#include <i386/gdt.h>
#include <i386/idt.h>

void arch_kernel_early()
{
    gdt_initialize();
    idt_initialize();
}
