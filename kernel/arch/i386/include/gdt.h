#ifndef GDT_H
#define GDT_H

/* gdt_init
 * Initialize the global descriptor table.
 * Descriptors used are
 *  - code descriptor (from 0 to 4G (all memory)) ring 0
 *  - data descriptor (from 0 to 4G (all memory)) ring 0
 * */
void gdt_init();

#endif
