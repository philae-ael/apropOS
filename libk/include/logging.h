#ifndef STD_LOGGING_H
#define STD_LOGGING_H

#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERR 3
#define LOG_ASSERT 4

#define LOG_DEFAULT LOG_WARN

#define MIN_LOG_LEVEL LOG_DEBUG
#define MAX_LOG_LEVEL LOG_ASSERT

void log_(int log_level, const char * ms);
void logf_(int log_level, const char * fmt, ...);

int get_log_level(void);
void set_log_level(int log_level);

#define debug(msg) log_(LOG_DEBUG, (msg))
#define info(msg) log_(LOG_INFO, (msg))
#define warn(msg) log_(LOG_WARN, (msg))
#define err(msg) log_(LOG_ERR, (msg))

#define debugf(...) logf_(LOG_DEBUG, __VA_ARGS__)
#define infof(...) logf_(LOG_INFO, __VA_ARGS__)
#define warnf(...) logf_(LOG_WARN, __VA_ARGS__)
#define errf(...) logf_(LOG_ERR, __VA_ARGS__)

#define STRINGIZE_DETAIL(x) #x
#define STRINGIZE(x) STRINGIZE_DETAIL(x)
#define make_debug_intro_format(fmt) "[%s:" __FILE__ ":" STRINGIZE(__LINE__) "] " fmt, __func__

#define debug_func(msg) debugf(make_debug_intro_format(msg))
#define info_func(msg) infof(make_debug_intro_format(msg))
#define warn_func(msg) warnf(make_debug_intro_format(msg))
#define err_func(msg) errf(make_debug_intro_format(msg))

#define debugf_func(fmt, ...) debugf(make_debug_intro_format(fmt), __VA_ARGS__)
#define infof_func(fmt, ...) infof(make_debug_intro_format(fmt), __VA_ARGS__)
#define warnf_func(fmt, ...) warnf(make_debug_intro_format(fmt), __VA_ARGS__)
#define errf_func(fmt, ...) errf(make_debug_intro_format(fmt), __VA_ARGS__)

#endif
