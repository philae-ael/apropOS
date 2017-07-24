#ifndef LOGGING_H
#define LOGGING_H

#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERR 3
#define LOG_ASSERT 4

#define LOG_DEFAULT LOG_WARN

#define MIN_LOG_LEVEL LOG_DEBUG
#define MAX_LOG_LEVEL LOG_ASSERT

void log(int log_level, const char * ms);
void logf(int log_level, const char * fmt, ...);

int get_log_level();
void set_log_level(int log_level);

#define debug(msg) log(LOG_DEBUG, (msg))
#define info(msg) log(LOG_INFO, (msg))
#define warn(msg) log(LOG_WARN, (msg))
#define err(msg) log(LOG_ERR, (msg))

#define debugf(...) logf(LOG_DEBUG, __VA_ARGS__)
#define infof(...) logf(LOG_INFO, __VA_ARGS__)
#define warnf(...) logf(LOG_WARN, __VA_ARGS__)
#define errf(...) logf(LOG_ERR, __VA_ARGS__)

#define debug_func(msg) debugf("[%s] " fmt, __func__)
#define info_func(msg) debugf("[%s] " fmt, __func__)
#define warn_func(msg) debugf("[%s] " fmt, __func__)
#define err_func(msg) debugf("[%s] " fmt, __func__)

#define debugf_func(fmt, ...) debugf("[%s] " fmt, __func__, __VA_ARGS__)
#define infof_func(fmt, ...) debugf("[%s] " fmt, __func__, __VA_ARGS__)
#define warnf_func(fmt, ...) debugf("[%s] " fmt, __func__, __VA_ARGS__)
#define errf_func(fmt, ...) debugf("[%s] " fmt, __func__, __VA_ARGS__)

#endif
