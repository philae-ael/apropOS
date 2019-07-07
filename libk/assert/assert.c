#include <libk/assert.h>

void __assert(const char msg [], const char file [], int line, const char func []){
    logf_(LOG_ASSERT, "[%s:%s:%d]: Assert failed: %s\n", file, func, line, msg);

    warnf("No abort! Do a while(0); TODO: create a nice abort");
    while(0);
    //abort();
}
