#include <stdint.h>
#include <stdio.h>

#include <kernel/isr.h>

void isr0(){
    PUSHREGS;

    printf("divide by zero error !");
    while(1);
    POPREGS;
    ISRRETURN;
}

void isr1(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr2(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr3(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr4(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr5(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr6(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr7(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr8(){
    uint8_t errcode = 0;  
    POPB(errcode);
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr9(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr10(){
    uint8_t errcode = 0;  
    POPB(errcode);
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr11(){
    uint8_t errcode = 0;  
    POPB(errcode);
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr12(){
    uint8_t errcode = 0;  
    POPB(errcode);
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr13(){
    uint8_t errcode = 0;  
    POPB(errcode);
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr14(){
    uint8_t errcode = 0;  
    POPB(errcode);
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr15(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr16(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr17(){
    uint8_t errcode = 0;  
    POPB(errcode);
 
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr18(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr19(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr20(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr21(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr22(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr23(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr24(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr25(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr26(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr27(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr28(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}

void isr29(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}


void isr30(){
    uint8_t errcode = 0;  
    POPB(errcode);
    PUSHREGS;



    POPREGS;
 
    ISRRETURN;
}

void isr31(){
    PUSHREGS;



    POPREGS;
    ISRRETURN;
}
