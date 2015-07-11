#include <stdlib.h>
#include <stdio.h>

__attribute__((__noreturn__))
void abort(void)
{
    printf("kernel Panic: abort()\n");
    while(1);
    __builtin_unreachable();
}
