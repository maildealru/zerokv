#ifndef ZKV_HASH_H
#define ZKV_HASH_H

#include "zkv_def.h"

typedef size_t
(zkv_hash_func_t*)(uint8_t *buff, size_t n);

typedef struct
{
    size_t key_max;
    size_t key_size;

    size_t value_max;
    size_t value_max;

    uint8_t *key_buff;
    uint8_t *value_buff;

    time_t expires_at;
}
zkv_hash_item_t;

typedef struct
{
    size_t size;
    size_t count;

    zkv_hash_item_t *buff;
}
zkv_hash_table_t;

void
zkv_hash_init(const zkv_config_t *config);

void
zkv_hash_drop(void);

uint8_t
zkv_hash_put(size_t nk, const uint8_t *key, size_t nv, const uint8_t *value, uint32_t expires_in);

uint8_t
zkv_hash_get(size_t nk, const uint8_t *key, size_t *nv, uint8_t *value, uint32_t *expires_in);

uint8_t
zkv_hash_del(size_t nk, const uint8_t *key);

#endif
