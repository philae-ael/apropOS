#include <i386/isr.h>
#include <i386/asm/asm.h>

#define ISR_ERRCODE(x)\
    void isr##x(){\
        cli();\
        pushb(x);\
        pushRegs();\
        call(isr_handler);\
        popRegs();\
        sti();\
        intReturn;\
    }

#define ISR_NO_ERRCODE(x)\
    void isr##x(){\
        cli();\
        pushb(0);\
        pushb(x);\
        pushRegs();\
        call(isr_handler);\
        popRegs();\
        sti();\
        intReturn;\
    }

ISR_ERRCODE(0)
ISR_ERRCODE(1)
ISR_ERRCODE(2)
ISR_ERRCODE(3)
ISR_ERRCODE(4)
ISR_ERRCODE(5)
ISR_ERRCODE(6)
ISR_ERRCODE(7)
ISR_NO_ERRCODE(8)
ISR_ERRCODE(9)
ISR_NO_ERRCODE(10)
ISR_NO_ERRCODE(11)
ISR_NO_ERRCODE(12)
ISR_NO_ERRCODE(13)
ISR_NO_ERRCODE(14)
ISR_ERRCODE(15)
ISR_ERRCODE(16)
ISR_NO_ERRCODE(17)
ISR_ERRCODE(18)
ISR_ERRCODE(19)
ISR_ERRCODE(20)
ISR_ERRCODE(21)
ISR_ERRCODE(22)
ISR_ERRCODE(23)
ISR_ERRCODE(24)
ISR_ERRCODE(25)
ISR_ERRCODE(26)
ISR_ERRCODE(27)
ISR_ERRCODE(28)
ISR_ERRCODE(29)
ISR_ERRCODE(30)
ISR_ERRCODE(31)
