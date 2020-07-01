#define  ZKV_LOG_C
#include <zkv.h>

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#define ZKV_LOG_BUFF_SIZE  16 MiB
#define ZKV_TIME_BUFF_SIZE 32 B

static char
zkv_log_buff[ZKV_LOG_BUFF_SIZE] = {0};

static char
zkv_time_buff[ZKV_TIME_BUFF_SIZE] = {0};

#define ZKV_LOG_TIME_FMT "%Y-%m-%d %H:%M:%S"

static FILE *
zkv_log_file = NULL;

void
zkv_log_init(const zkv_config_t *config)
{
    if (!config->use_syslog)
        zkv_log_file = stdout;
    if (config->min_log_level)
        zkv_min_log_level = (zkv_log_level_t)config->min_log_level;
}

void
zkv_log_drop(void) {}

void
zkv_write_log(const char *level, const char *fmt, ...)
{
    assert(level && fmt);

    va_list va;
    va_start(va, fmt);

    vsnprintf(BUFFSZ(zkv_log_buff), fmt, va);
    va_end(va);

    if (zkv_log_file)
    {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(BUFFSZ(zkv_time_buff), ZKV_LOG_TIME_FMT, tm_info);

        fprintf(zkv_log_file, "%s [ %zd ] %s %s\n",
                zkv_time_buff, zkv_get_pid(), level, zkv_log_buff);
    }
    else
    {
        //TODO: syslog
    }
}
