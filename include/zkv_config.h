#ifndef ZKV_CONFIG_H
#define ZKV_CONFIG_H

#include <inttypes.h>

#include "zkv_def.h"

typedef struct
{
    uint8_t use_syslog;
    uint8_t min_log_level;

    size_t max_conn;
}
zkv_config_t;

void
zkv_config_init(zkv_config_t *config);

void
zkv_config_drop(zkv_config_t *config);

void
zkv_config_load(zkv_config_t *config, const char *fname);

#endif
