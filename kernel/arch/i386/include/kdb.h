#ifndef KDB_H
#define KDB_H

#define KDB_IRQ 1
#define KDB_PORT 0x60

void kdb_init();
void kdb_handler();

#endif /* ifndef KDB_H */
