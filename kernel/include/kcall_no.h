#ifndef KCALL_NO_H
#define KCALL_NO_H
#include <stddef.h>

#define KCALL_WRITE 0
struct kcall_write_t{
    const char* str;
    size_t len;
};

#endif /* ifndef KCALL_NO_H */
