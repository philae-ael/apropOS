#include <stdbool.h>

#include "console.h"


void kernel_early(){
    init_console();
    puts("Console initialized\b\n");

}
