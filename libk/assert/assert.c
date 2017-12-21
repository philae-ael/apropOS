#include <libk/assert.h>

void __assert(const char msg [], const char file [], int line, const char func []){
    logf(LOG_ASSERT, "%s:%s:%d: Assert failed: %s\n", file, func, line, msg);
    //abort();
}
