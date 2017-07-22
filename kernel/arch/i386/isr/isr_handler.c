#include <asm/regs.h>
#include <logging.h>
#include <isr.h>

char * exception_msg [] = {
    "Division By Zero Exception\n",
    "Debug Exception\n",
    "Non Maskable Interrupt Exception\n",
    "Breakpoint Exception\n",
    "Into Detected Overflow Exception\n",
    "Out of Bounds Exception\n",
    "Invalid Opcode Exception\n",
    "No Coprocessor Exception\n",
    "Double Fault Exception\n",
    "Coprocessor Segment Overrun Exception\n",
    "Bad TSS Exception\n",
    "Segment Not Present Exception\n",
    "Stack Fault Exception\n",
    "General Protection Fault Exception\n",
    "Page Fault Exception\n",
    "Unknown Interrupt Exception\n",
    "Coprocessor Fault Exception\n",
    "Alignment Check Exception\n",
    "Machine Check Exception\n"
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
