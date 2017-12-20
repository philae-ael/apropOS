#include <stdio.h>
#include <kernel/kcall.h>
#include <kernel/kcall_no.h>
#include <kernel/scheduler.h>

static __attribute__((noreturn)) void userland0(void);
void userland0(){
    struct kcall_write_t a = {.str = "A!\n", .len=3};
    for(;;){
        kcall(0, (void*)&a);
        kcall(1, 0);
    }
}

static __attribute__((noreturn)) void userland1(void);
void userland1(){
    for(;;){
        struct kcall_write_t a = {.str = "B!\n", .len=3};
        kcall(0, (void*)&a);
        kcall(1, 0);
    }
}

void kcall_write(struct regs*r, void*args_);
void kcall_write(struct regs*r, void*args_){
    (void)r;
    struct kcall_write_t* args =  (struct kcall_write_t*) args_;
    puts(args->str);
}

void __attribute__((noreturn)) kernel_main(void);
void  kernel_main(){
    kcall_handler_install(0, kcall_write);
    scheduler_init();
    scheduler_add((void*)userland0);
    scheduler_add((void*)userland1);
    scheduler_start();
}
