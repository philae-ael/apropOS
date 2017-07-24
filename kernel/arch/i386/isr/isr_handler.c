#include <logging.h>
#include <kernel/i386/asm/regs.h>
#include <kernel/i386/isr.h>

char * exception_msg [] = {
    "Division By Zero Exception",
    "Debug Exception",
    "Non Maskable Interrupt Exception",
    "Breakpoint Exception",
    "Into Detected Overflow Exception",
    "Out of Bounds Exception",
    "Invalid Opcode Exception",
    "No Coprocessor Exception",
    "Double Fault Exception",
    "Coprocessor Segment Overrun Exception",
    "Bad TSS Exception",
    "Segment Not Present Exception",
    "Stack Fault Exception",
    "General Protection Fault Exception",
    "Page Fault Exception",
    "Unknown Interrupt Exception",
    "Coprocessor Fault Exception",
    "Alignment Check Exception",
    "Machine Check Exception"
};

void isr_handler(struct regs* r){
    if(r->int_no < 32){
        if(r->int_no < 15){
            err(exception_msg[r->int_no]);
            log_regs(r);
        }
    }
    for(;;);//halt
}
