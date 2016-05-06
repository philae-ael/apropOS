#include <stdint.h>

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
        push ds \n \
        push es \n \
        push fs \n \
        push gs \n ") //save regs on stack

#define popRegs() asm volatile (" \
        pop gs \n \
        pop fs \n \
        pop es \n \
        pop ds \n \
        popa ") //restore regs stored on stack

#define intReturn asm volatile (" \
        add esp, 8 \n \
        iret") //clean stack and return for interuptions

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "in %0, %1"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}


static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile (" \
            out %1, %0" : : "a"(val), "Nd"(port) );
}

static inline void io_wait(void)
{
    asm volatile ( "jmp 1f\n\t"
                   "1:jmp 2f\n\t"
                   "2:" );
}

#define call(ifunc) asm volatile (" \
        mov eax, esp \n \
        push eax \n \
        mov eax, %0 \n \
        call eax \n \
        pop eax" \
        :\
        :"i" (ifunc)) // call ifunc
