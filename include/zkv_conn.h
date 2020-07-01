#ifndef ZKV_CONN_H
#define ZKV_CONN_H

#include <stdlib.h>

#include "zkv_def.h"
#include "zkv_config.h"

typedef struct
{
    ssize_t fd;
}
zkv_conn_t;

typedef struct
{
    size_t size;
    size_t count;

    zkv_conn_t *buff;
}
zkv_conn_pull_t;

void
zkv_conn_pull_init(zkv_conn_pull_t *pool, const zkv_config_t *config);

void
zkv_conn_pull_drop(zkv_conn_pull_t *pool);

void
zkv_conn_pull_listen(zkv_conn_pull_t *pool);

#endif
