#ifndef GDT_H
#define GDT_H
#include <stdint.h>
#include <stdbool.h>

// Ring
#define GDT_ACCESS_PRIVL_0 0x00
#define GDT_ACCESS_PRIVL_1 0x10
#define GDT_ACCESS_PRIVL_2 0x20
#define GDT_ACCESS_PRIVL_3 0x30

// Code or data segment
#define GDT_ACCESS_EX_CODE 0x00
#define GDT_ACCESS_EX_DATA 0x08

// Direction bit
#define GDT_ACCESS_DIRECTION

// Allow Write or Read (Write for code segments, read for Code segment
#define GDT_ACCESS_DISALLOW_RW 0
#define GDT_ACCESS_ALLOW_RW 0x02

//Acceded bit
#define GDT_ACCESS_ACCEDED 0

//granularity 1b(0) or 4Kb(1)
#define GDT_FLAG_GRANULARITY_1B  0x00
#define GDT_FLAG_GRANULARITY_4KB 0x80
//16 bit proteced mode (0) or 32 bits protected mode (1)
#define GDT_FLAG_SIZE_16 0
#define GDT_FLAG_SIZE_32 0x40

void gdt_initialize();
void gdt_add_entry(uint32_t base,uint32_t limit,uint8_t access,uint8_t flags, uint8_t size);
#endif
