#include <stdbool.h>
#include <stdio.h>

#include "console.h"


void kernel_early(){
    console_init();
    puts("Console initialized\b\n");
}
