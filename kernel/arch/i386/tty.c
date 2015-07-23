#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <kernel/vga.h>
#include <kernel/tty.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize()
{
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    terminal_buffer = VGA_MEMORY;
    for(size_t i = 0; i<(VGA_WIDTH * VGA_HEIGHT); i++)
    {
        terminal_buffer[i] = make_vgaentry(' ',terminal_color);
    }
}

void terminal_setcolor(uint16_t color)
{
    terminal_color = color;
}

void terminal_putchar(char c)
{
    if(c == '\n'){
        terminal_column = 0;
        terminal_row++;
        return;
    }
    if(++terminal_column == VGA_WIDTH)
    {
        if(++terminal_row == VGA_HEIGHT){
            terminal_scrollup(1);
        }
        terminal_column = 0;
    }
    const size_t offset = terminal_row * VGA_WIDTH + terminal_column;
    terminal_buffer[offset] = make_vgaentry(c, terminal_color);
}

void terminal_write(char* c,size_t size){
    for(size_t i = 0; i < size; i++)
    {
        terminal_putchar(c[i]);
    }
}

void terminal_writestring(char* c)
{
   terminal_write(c,strlen(c));
}

void terminal_scrollup(size_t y)
{
   if(y > VGA_HEIGHT)
       return;
   memcpy(terminal_buffer,
           terminal_buffer + y * VGA_WIDTH,
           VGA_WIDTH * (VGA_HEIGHT-y) * sizeof(uint16_t));

   memset(terminal_buffer + VGA_WIDTH * (VGA_HEIGHT-y) * sizeof(uint16_t),0,
           VGA_WIDTH * VGA_HEIGHT -  VGA_WIDTH * (VGA_HEIGHT-y));

   terminal_row -= y;
}
