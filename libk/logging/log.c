#include <libk/logging.h>
#include <libk/stdio.h>
#include <stdarg.h>

static int _log_level = LOG_DEFAULT;

#ifdef LOG_ANSI_COLOR
static const char *log_msg [] = {
    "\033[90mDEBUG: ",
    "\033[34mINFO: ",
    "\033[33mWARNING: ",
    "\033[31mERROR: ",
    "\033[31mASSERT: "
};
static const char* log_end = "\033[0m\n";
#else
static char *log_msg [] = {
    "DEBUG: ",
    "INFO: ",
    "WARNING: ",
    "ERROR: ",
    "ASSERT: "
};
static const char* log_end = "\n";
#endif /* ifdef LOG_ANSI_COLOR */


void logf_(int log_level, const char * fmt, ...){
    if(log_level < _log_level || log_level < MIN_LOG_LEVEL || log_level > MAX_LOG_LEVEL)
        return;

    va_list args;
    va_start(args, fmt);

    puts(log_msg[log_level]);
    vprintf(fmt, args);
    puts(log_end);

    va_end(args);


}

void log_(int log_level, const char *msg){
    if(log_level < _log_level || log_level < MIN_LOG_LEVEL || log_level > MAX_LOG_LEVEL)
        return;

    puts(log_msg[log_level]);
    puts(msg);
    puts("\n");


}

int get_log_level(){
    return _log_level;
}

void set_log_level(int log_level){
    _log_level = log_level;
}
