#define  ZKV_CONN_C
#include <zkv.h>

void
zkv_conn_pull_init(zkv_conn_pull_t *pool, const zkv_config_t *config)
{
    XZERO(pool);
    pool->buff = xcalloc(config->max_conn, sizeof(zkv_conn_t));
}

void
zkv_conn_pull_drop(zkv_conn_pull_t *pool)
{
    free(pool->buff); XZERO(pool);
}

void
zkv_conn_pull_listen(zkv_conn_pull_t *pool) {}
