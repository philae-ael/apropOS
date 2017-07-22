/*
   Use vga-text mode to print to screen
*/

#include <stdint.h>
#include <string.h>
#include <serial.h>

uint16_t* console;

struct console_status{
    struct{
        uint8_t x;
        uint8_t y;
    } cursor;
    struct{
        uint8_t width;
        uint8_t height;
    } screen;
};


struct console_status console_status;

void clear_screen(){
    for(uint16_t x = 0; x < console_status.screen.width * console_status.screen.height; x++){
        console[x] = 0;
    }
}

uint16_t* get_address(uint8_t x, uint8_t y){
    return console + y * console_status.screen.width + x;
}

void scrolls(uint8_t lineToScrolls){
    uint16_t* start = get_address(0, lineToScrolls);

    uint16_t* start_clear = get_address(0, console_status.screen.height - lineToScrolls);
    uint16_t* end = get_address(console_status.screen.width, console_status.screen.height);

    memmove(console, start, (end - start) * sizeof(uint16_t));

    memset(start_clear, 0, (end - start_clear) * sizeof(uint16_t));
}

void console_init(){
    console = (uint16_t*)0xB8000;

    console_status.cursor.x = console_status.cursor.y = 0;
    console_status.screen.width = 80;
    console_status.screen.height = 25;

    clear_screen();
}

void console_putc(char c){
    if(!c) return;

#ifdef CONSOLE_TO_SERIAL
    write_serial(c);
#endif

    if(console_status.cursor.x > console_status.screen.width){
        console_status.cursor.x = 0;
        console_status.cursor.y += 1;
    }
    if(console_status.cursor.y >= console_status.screen.height){
        scrolls(1);
        console_status.cursor.y--;
    }
    uint16_t* address = get_address(console_status.cursor.x,
                                  console_status.cursor.y);
    switch(c){
    case '\n':
        console_status.cursor.y += 1;
        console_status.cursor.x = 0;
        break;
    case '\r':
        console_status.cursor.x = 0;
        break;
    case '\b':
        if(console_status.cursor.x > 0)
            console_status.cursor.x -= 1;

        address = get_address(console_status.cursor.x,
                                  console_status.cursor.y);
        *address = (0x0F << 8) | 0;
        break;

    default:
        *address = (0x0F << 8) | c;

        console_status.cursor.x += 1;
    }

}

void console_puts(char* str){
    while(*str != 0){
        console_putc(*str);
        str++;
    }
}

