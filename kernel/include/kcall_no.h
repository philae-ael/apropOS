#ifndef KCALL_NO_H
#define KCALL_NO_H
#include <stddef.h>

#define KCALL_WRITE 0
struct kcall_write_t{
    const char* const str;
    const size_t len;
};

#define KCALL_YIELD 1

#endif /* ifndef KCALL_NO_H */
