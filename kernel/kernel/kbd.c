#include <stdio.h> 
#include <stdbool.h> 

#include <kernel/kbd.h>
#include <kernel/irq.h>
#include <kernel/regs.h>

void kbd_irq(struct regs* r)
{
    printf("keyboard input !!!!");
}

int kbd_read(void)
{
    return 0;
}

bool kbd_initialize(void)
{
    irq_set_handler(1,&kbd_irq);
    return true;
}
