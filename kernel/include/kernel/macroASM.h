
#define CLI asm volatile ("cli")

#define PUSHB(x) asm volatile ("push %0"\
        : \
        :"r" (x))

#define POPB(x) asm volatile ("pop %0"\
        :"=m" (x))

#define PUSHREGS asm volatile (" \
        pusha \n \
        push %ds \n \
        push %es \n \
        push %fs \n \
        push %gs \n ")

#define POPREGS asm volatile (" \
        pop %gs \n \
        pop %fs \n \
        pop %es \n \
        pop %ds \n \
        popa ")

#define INTRETURN asm volatile (" \
        add $8, %esp \n \
        iret")

#define outb(src,dest) asm volatile (" \
        outb %b0, %w1\n \
        nop" \
        : \
        :"a" (src), "Nd" (dest) )

#define intb(src,dest) asm volatile (" \
        inb %w0,%b1"\
        :"=a"(dest) \
        :"Nd" (src))

#define CALL(func) asm volatile (" \
        mov %%esp, %%eax \n \
        push %%eax \n \
        mov %0, %%eax \n \
        call *%%eax \n \
        pop %%eax" \
        :\
        :"i" (func))
