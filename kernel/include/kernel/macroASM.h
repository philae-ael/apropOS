/*
    Some usefuls macro for OS developpement
    for args : i* -> inputs
               o* -> outputs
*/


// any cli call must be followed quickly by a sti call
#define cli() asm volatile ("cli") // disable maskable interruptions (material)
#define sti() asm volatile ("sti") // restore them

#define pushb(i) asm volatile ("push %0"\
        ::"r" (i)) // push a byte on stack

#define popb(o) asm volatile ("pop %0"\
        :"=m" (o)) // pop a byte on stack to out

#define pushRegs() asm volatile (" \
        pusha \n \
        push %ds \n \
        push %es \n \
        push %fs \n \
        push %gs \n ") //save regs on stack

#define popRegs() asm volatile (" \
        pop %gs \n \
        pop %fs \n \
        pop %es \n \
        pop %ds \n \
        popa ") //restore regs stored on stack

#define intReturn asm volatile (" \
        add $8, %esp \n \
        iret") //clean stack and return for interuptions

#define outb(ival,idest) asm volatile (" \
        outb %b0, %w1\n \
        nop" \
        : \
        :"a" (isrc), "Nd" (idest) ) //send ival on port idest

#define intb(isrc,odest) asm volatile (" \
        inb %w0,%b1"\
        :"=a"(dest) \
        :"Nd" (src)) //get value from port isrc to odest

#define call(ifunc) asm volatile (" \
        mov %%esp, %%eax \n \
        push %%eax \n \
        mov %0, %%eax \n \
        call *%%eax \n \
        pop %%eax" \
        :\
        :"i" (func)) // call ifunc
