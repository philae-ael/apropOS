#include <stdio.h>

#if defined(__is_apropOS_kernel)
#include <kernel/kbd.h>

int getchar(void)
{
#if defined(__is_apropOS_kernel)
    return kbd_read();
#else
    //TODO: you need to implement a read system call.
}
