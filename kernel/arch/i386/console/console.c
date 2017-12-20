/*
   Use vga-text mode to print to screen
*/

#include <stdint.h>
#include <string.h>
#include <kernel/i386/serial.h>
#include <kernel/i386/console.h>

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

static uint16_t* console;
static struct console_status console_status;


void clear_screen(){
    for(uint16_t x = 0; x < console_status.screen.width * console_status.screen.height; x++){
        console[x] = 0;
    }
}

static uint16_t* get_address(uint8_t x, uint8_t y){
    return console + y * console_status.screen.width + x;
}

static void scrolls(uint8_t lineToScrolls){
    uint16_t* start = get_address(0, lineToScrolls);

    uint16_t* start_clear = get_address(0, console_status.screen.height - lineToScrolls);
    uint16_t* end = get_address(console_status.screen.width, console_status.screen.height);

    memmove(console, start, (size_t)(end - start) * sizeof(uint16_t));

    memset(start_clear, 0, (size_t)(end - start_clear) * sizeof(uint16_t));
}

void console_init(){
    console = (uint16_t*)0xB8000;

    console_status.cursor.x = console_status.cursor.y = 0;
    console_status.screen.width = 80;
    console_status.screen.height = 25;

    clear_screen();
}

void console_putc(const char c){
    if(!c) return;

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
        *address = (uint16_t)((0x0F << 8) | c);

        console_status.cursor.x += 1;
    }

}

void console_puts(const char* const str){
    const char* s2 = str;
    while(*s2 != 0){
        console_putc(*s2);
        s2++;
    }
}

