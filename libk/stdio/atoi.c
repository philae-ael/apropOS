#include <libk/stdio.h>

char* atoi(int value, char* str){
    return itoa(value, str, 10);
}
