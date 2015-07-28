#include <kernel/macroASM.h>

#include <kernel/irqdefs.h>
#include <kernel/irq.h>

void irq0(void)
{
    CLI;
    PUSHB(0);
	PUSHB(0);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq1(void)
{
    CLI;
    PUSHB(0);
	PUSHB(1);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq2(void)
{
    CLI;
    PUSHB(0);
	PUSHB(2);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq3(void)
{
    CLI;
    PUSHB(0);
	PUSHB(3);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq4(void)
{
    CLI;
    PUSHB(0);
	PUSHB(4);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq5(void)
{
    CLI;
    PUSHB(0);
	PUSHB(5);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq6(void)
{
    CLI;
    PUSHB(0);
	PUSHB(6);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq7(void)
{
    CLI;
    PUSHB(0);
	PUSHB(7);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq8(void)
{
    CLI;
    PUSHB(0);
	PUSHB(8);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq9(void)
{
    CLI;
    PUSHB(0);
	PUSHB(9);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq10(void)
{
    CLI;
    PUSHB(0);
	PUSHB(10);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq11(void)
{
    CLI;
    PUSHB(0);
	PUSHB(11);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq12(void)
{
    CLI;
    PUSHB(0);
	PUSHB(12);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq13(void)
{
    CLI;
    PUSHB(0);
	PUSHB(13);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq14(void)
{
    CLI;
    PUSHB(0);
	PUSHB(14);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}

void irq15(void)
{
    CLI;
    PUSHB(0);
	PUSHB(15);
    PUSHREGS;

	CALL(irq_handler);

    POPREGS;
    INTRETURN;
}
