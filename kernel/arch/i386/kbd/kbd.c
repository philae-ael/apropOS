#include <kbd.h>
#include <key.h>
#include <asm/regs.h>
#include <asm/io.h>
#include <irq.h>
#include <stdio.h>
#define KBD_DEVICE 0x60
#define KBD_COMMAND 0x61
#define KBD_PENDING 0x61
#define KBD_IRQ 0x01


void kbd_wait() {
    while(inb(KBD_PENDING) & 2);
}


key_event_t event;
key_event_state_t kbd_state = {0};

void kbd_handler(struct regs* r){
    uint8_t scancode = inb(KBD_DEVICE);

    key_scancode(&kbd_state, scancode, &event);

    if (event.action == KEY_ACTION_UP) return;
    putchar(event.key);
}

void kbd_reset(){
    uint8_t tmp = inb(KBD_COMMAND);
    outb(KBD_COMMAND, tmp | 0x80);
    outb(KBD_COMMAND, tmp & 0x7F);
    inb(KBD_DEVICE);
}

void kbd_init(){
    irq_handler_install(KBD_IRQ, kbd_handler);
    kbd_reset();
    irq_mask(KBD_IRQ);
}
