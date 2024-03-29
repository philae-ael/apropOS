#include <kernel/i386/asm/io.h>
#include <kernel/i386/serial.h>
#include <stdint.h>

#ifdef SERIAL_PORT_DISABLE

void serial_init(){}
char read_serial(){return 0;}
void write_serial(char c){}

#else

static uint16_t serial_port; // serial_port set in serial_port

void serial_init(void){
    // We will use COM 1 mapped by bios on 0x400
    uint16_t* bios_serial_data = (uint16_t* ) 0x400;
    serial_port = *bios_serial_data; // In qemu (and a lot of machines) serial_port should be 0x3f8

    /* start initializing port
     * We want baudrate = 230400 (base baudrate (1152000) divided by 5)
     * 8bits no parity 1 stop bit
     * interrupts enabled
     * FIFO enabled
     */

    outb(serial_port + 1, 0x00); // Disable interrupts
    outb(serial_port + 3, 0x80); // set DLAB (allow setting baudrate)
    outb(serial_port + 0, 0x03); // now serial_port + 0 will be lo bytes divisor
    outb(serial_port + 1, 0x00); //     serial_port + 1         hi bytes divisor
    outb(serial_port + 3, 0x03); // unset DLAB, 8bits no parity, 1 bit stop
    outb(serial_port + 2, 0xC7); // FIFO set, clear FIFO (r/w) 14 bytes threshold (on interrupts)
    outb(serial_port + 4, 0x0F); // IRQs enabled, RTS/DSR set
    outb(serial_port + 1, 0x01); // Enable interrupts on data available
}

static void wait_serial_in(void){
    // wait FIFO input to be full (bit 0 of line status register should be set)
    while((inb(serial_port + 5) & 0x1) == 0);
}

static void wait_serial_out(void){
    // wait FIFO output to be empty (bit 5 of line status register should be set)
    while((inb(serial_port + 5) & 0x20) == 0);
}
char read_serial(void){
    wait_serial_in();
    return (char)inb(serial_port);
}

void write_serial(char c){
    wait_serial_out();
    outb(serial_port, (uint8_t)c);
}

int putchar_serial(int c){
    write_serial((char)c);
    return c;
}

int puts_serial(const char* const str){
    int n = 0;
    const char* s2 = str;
    while(*s2 != 0){
        write_serial(*s2);
        s2++;
        n++;
    }
    return n;
}

#endif
