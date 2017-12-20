#include <logging.h>
#include <stdio.h>
#include <stdarg.h>

static int _log_level = LOG_DEFAULT;

static char *log_msg [] = {
    "DEBUG: ",
    "INFO: ",
    "WARNING: ",
    "ERROR: ",
    "ASSERT: "
};

void logf(int log_level, const char * fmt, ...){
    if(log_level < _log_level || log_level < MIN_LOG_LEVEL || log_level > MAX_LOG_LEVEL)
        return;

    va_list args;
    va_start(args, fmt);

    puts(log_msg[log_level]);
    vprintf(fmt, args);
    puts("\n");

    va_end(args);


}

void log(int log_level, const char *msg){
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
