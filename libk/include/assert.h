#ifndef STD_ASSERT_H
#define STD_ASSERT_H

#include <libk/logging.h>


#ifdef NDEBUG
#define assert (void) 0;
#else
#define assert(pred) (pred) ? (void) 0 : \
    __assert(#pred, __FILE__, __LINE__, __func__)
#endif

void __assert(const char msg [], const char file [], int line, const char func []);

#endif /* ifndef ASSERT_H */
