#include <stdio.h>
#include <kernel/userland.h>
#include <kernel/kcall.h>

extern void userland(void);

void userland(){
    puts("test ?\n");
}

void kernel_main(void);
void kernel_main(){
    userland_init();
    uint32_t process_id = userland_add_process(0);
    userland_jump(process_id, userland);
}
