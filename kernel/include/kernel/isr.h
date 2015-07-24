#ifndef ISR_H
#define ISR_H

#define CLI asm("cli")

#define PUSHB(x) asm("push $" ## (x) )
#define POPB(x) asm("pop %0"\
        :"=r" (x))

#define PUSHREGS asm(" \
        pusha \n \
        push %ds \n \
        push %es \n \
        push %fs \n \
        push %gs \n ")

#define POPREGS asm(" \
        popa \n \
        pop %ds \n \
        pop %es \n \
        pop %fs \n \
        pop %gs \n ")

#define ISRRETURN asm(" \
        add $8, %esp \n \
        iret")

//exceptions
void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void isr9();
void isr10();
void isr11();
void isr12();
void isr13();
void isr14();
void isr15();
void isr16();
void isr17();
void isr18();
void isr19();
void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();

#endif
