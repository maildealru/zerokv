#ifndef ZKV_LOG_H
#define ZKV_LOG_H

#include <stdint.h>

#include "zkv_config.h"

typedef enum
{
    ZKV_LOG_DEBUG   = 1,
    ZKV_LOG_INFO    = 2,
    ZKV_LOG_WARNING = 3,
    ZKV_LOG_ERROR   = 4,
    ZKV_LOG_FATAL   = 5,
}
zkv_log_level_t;

#ifndef ZKV_LOG_C
    extern
#endif
    zkv_log_level_t zkv_min_log_level
#ifdef  ZKV_LOG_C
    = ZKV_LOG_INFO
#endif
    ;

#define __zkv_write_log(level, lstr, fmt, ...)       \
    ({                                               \
        if (level >= zkv_min_log_level)              \
            zkv_write_log(lstr, fmt, ##__VA_ARGS__); \
    })

#define __zkv_write_log_fl(level, lstr, fmt, ...)                                            \
    ({                                                                                       \
        __zkv_write_log(level, lstr, fmt " [%s:%d]", ##__VA_ARGS__, __FILE_REL__, __LINE__); \
    })

#define __zkv_log_d(fn, fmt, ...) fn(ZKV_LOG_DEBUG,   "D", fmt, ##__VA_ARGS__)
#define __zkv_log_i(fn, fmt, ...) fn(ZKV_LOG_INFO,    "I", fmt, ##__VA_ARGS__)
#define __zkv_log_w(fn, fmt, ...) fn(ZKV_LOG_WARNING, "W", fmt, ##__VA_ARGS__)
#define __zkv_log_e(fn, fmt, ...) fn(ZKV_LOG_ERROR,   "E", fmt, ##__VA_ARGS__)
#define __zkv_log_f(fn, fmt, ...) fn(ZKV_LOG_FATAL,   "F", fmt, ##__VA_ARGS__)

#define zkv_log_d(fmt, ...) __zkv_log_d(__zkv_write_log, fmt, ##__VA_ARGS__)
#define zkv_log_i(fmt, ...) __zkv_log_i(__zkv_write_log, fmt, ##__VA_ARGS__)
#define zkv_log_w(fmt, ...) __zkv_log_w(__zkv_write_log, fmt, ##__VA_ARGS__)
#define zkv_log_e(fmt, ...) __zkv_log_e(__zkv_write_log, fmt, ##__VA_ARGS__)
#define zkv_log_f(fmt, ...) __zkv_log_f(__zkv_write_log, fmt, ##__VA_ARGS__)

#define zkv_log_dp(fmt, ...) __zkv_log_d(__zkv_write_log_fl, fmt, ##__VA_ARGS__)
#define zkv_log_ip(fmt, ...) __zkv_log_i(__zkv_write_log_fl, fmt, ##__VA_ARGS__)
#define zkv_log_wp(fmt, ...) __zkv_log_w(__zkv_write_log_fl, fmt, ##__VA_ARGS__)
#define zkv_log_ep(fmt, ...) __zkv_log_e(__zkv_write_log_fl, fmt, ##__VA_ARGS__)
#define zkv_log_fp(fmt, ...) __zkv_log_f(__zkv_write_log_fl, fmt, ##__VA_ARGS__)

void
zkv_log_init(const zkv_config_t *config);

void
zkv_log_drop(void);

void
zkv_write_log(const char *level, const char *fmt, ...);

#endif
