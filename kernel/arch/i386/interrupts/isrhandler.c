#include <i386/isr.h>
#include <i386/asm/regs.h>
#include <stdlib.h>
#include <stdio.h>

void isr_handler(struct regs* r)
{
    switch(r->call_code)
    {
        case 0:
            printf("division by zero\n");
            abort();
            break;
        default:
            printf("Exception not handled\n");
    }
}
