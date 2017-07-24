#include <logging.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef LOG_SERIAL
#include <kernel/i386/serial.h>
#endif

int _log_level = LOG_DEFAULT;

char *log_msg [] = {
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
#ifdef LOG_SERIAL
    puts_serial(log_msg[log_level]);
    _printf(puts_serial, putchar_serial, fmt, args);
    puts_serial("\n");
#else
    puts(log_msg[log_level]);
    vprintf(fmt, args);
    puts("\n");
#endif
    va_end(args);


}

void log(int log_level, const char *msg){
    if(log_level < _log_level || log_level < MIN_LOG_LEVEL || log_level > MAX_LOG_LEVEL)
        return;

#ifdef LOG_SERIAL
    puts_serial(log_msg[log_level]);
    puts_serial(msg);
    puts_serial("\n");
#else
    puts(log_msg[log_level]);
    puts(msg);
    puts("\n");
#endif


}

int get_log_level(){
    return _log_level;
}

void set_log_level(int log_level){
    _log_level = log_level;
}
