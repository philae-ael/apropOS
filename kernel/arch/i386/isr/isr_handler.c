#include <libk/logging.h>
#include <kernel/i386/asm/regs.h>
#include <kernel/i386/isr.h>

static char * exception_msg [] = {
    "Division By Zero Exception\0",
    "Debug Exception\0",
    "Non Maskable Interrupt Exception\0",
    "Breakpoint Exception\0",
    "Into Detected Overflow Exception\0",
    "Out of Bounds Exception\0",
    "Invalid Opcode Exception\0",
    "No Coprocessor Exception\0",
    "Double Fault Exception\0",
    "Coprocessor Segment Overrun Exception\0",
    "Bad TSS Exception\0",
    "Segment Not Present Exception\0",
    "Stack Fault Exception\0",
    "General Protection Fault Exception\0",
    "Page Fault Exception\0",
    "Unknown Interrupt Exception\0",
    "Coprocessor Fault Exception\0",
    "Alignment Check Exception\0",
    "Machine Check Exception\0"
};

void __attribute__ ((noreturn)) isr_handler(struct regs* r);
void isr_handler(struct regs* r){
    if(r->int_no < 32){
        if(r->int_no < 15){
            errf("%s", exception_msg[r->int_no]);
            log_regs(r);
        }
    }
    for(;;);//halt
}
