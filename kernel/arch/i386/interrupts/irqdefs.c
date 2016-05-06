#include <i386/irq.h>
#include <i386/asm/asm.h>

#define IRQ(x)\
    void irq##x(){\
        pushb(0); /* no Errcode*/\
        pushb(x);\
        pushRegs();\
        call(irq_handler);\
        popRegs();\
        intReturn;\
    }

IRQ(0)
IRQ(1)
IRQ(2)
IRQ(3)
IRQ(4)
IRQ(5)
IRQ(6)
IRQ(7)
IRQ(8)
IRQ(9)
IRQ(10)
IRQ(11)
IRQ(12)
IRQ(13)
IRQ(14)
IRQ(15)
