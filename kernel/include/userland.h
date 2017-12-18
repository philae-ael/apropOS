#ifndef USERLAND_H
#define USERLAND_H

#include <kernel/i386/paging.h>

#define MAX_PROCESS 256

typedef struct{
    uint8_t used :1;
    uint8_t running :1;
    uint8_t unused :6;
    uint8_t user_id;
    uint16_t process_id;

    page_directory_t* page_dir;
} process_list_t;

void userland_init(void);
void userland_jump(uint32_t uid, void (*func)(void));
uint16_t userland_add_process(uint8_t user_id);

#endif /* ifndef USERLAND_H */
