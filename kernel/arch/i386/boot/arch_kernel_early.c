#include <i386/gdt.h>
#include <i386/idt.h>
#include <i386/irq.h>

void arch_kernel_early()
{
    gdt_initialize();
    idt_initialize();
    irq_initialize();
}
