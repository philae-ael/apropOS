#include <kernel/isr.h>
#include <kernel/macroASM.h>

void isr0(){
	PUSHB(0);
	PUSHB(0);
	PUSHB(0);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr1(){
	PUSHB(0);
	PUSHB(1);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr2(){
	PUSHB(0);
	PUSHB(2);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr3(){
	PUSHB(0);
	PUSHB(3);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr4(){
	PUSHB(0);
	PUSHB(4);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr5(){
	PUSHB(0);
	PUSHB(5);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr6(){
	PUSHB(0);
	PUSHB(6);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr7(){
	PUSHB(0);
	PUSHB(7);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr8(){
	PUSHB(8);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr9(){
	PUSHB(0);
	PUSHB(9);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr10(){
	PUSHB(10);
    CLI;
    PUSHREGS;

	CALL(isr_handler);



    POPREGS;
    INTRETURN;
}

void isr11(){
	PUSHB(11);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr12(){
	PUSHB(12);
    CLI;
    PUSHREGS;

	CALL(isr_handler);



    POPREGS;
    INTRETURN;
}

void isr13(){
	PUSHB(13);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr14(){
	PUSHB(14);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr15(){
	PUSHB(0);
	PUSHB(15);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr16(){
	PUSHB(0);
	PUSHB(16);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr17(){
	PUSHB(17);
 
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr18(){
	PUSHB(0);
	PUSHB(18);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr19(){
	PUSHB(0);
	PUSHB(19);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr20(){
	PUSHB(0);
	PUSHB(20);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr21(){
	PUSHB(0);
	PUSHB(21);
    CLI;
    PUSHREGS;

	CALL(isr_handler);



    POPREGS;
    INTRETURN;
}

void isr22(){
	PUSHB(0);
	PUSHB(22);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr23(){
	PUSHB(0);
	PUSHB(23);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr24(){
	PUSHB(0);
	PUSHB(24);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr25(){
	PUSHB(0);
	PUSHB(25);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr26(){
	PUSHB(0);
	PUSHB(26);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr27(){
	PUSHB(0);
	PUSHB(27);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr28(){
	PUSHB(0);
	PUSHB(28);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}

void isr29(){
	PUSHB(0);
	PUSHB(29);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}


void isr30(){
	PUSHB(30);
    
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
 
    INTRETURN;
}

void isr31(){
	PUSHB(0);
	PUSHB(31);
    CLI;
    PUSHREGS;

	CALL(isr_handler);

    POPREGS;
    INTRETURN;
}
