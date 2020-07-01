#ifndef ZKV_SYS_H
#define ZKV_SYS_H

#include <unistd.h>

#include "zkv_def.h"

AINLINE ssize_t
zkv_get_pid(void)
{
    return (ssize_t)getpid();
}

void
zkv_panic(const char *fmt, ...);

#endif
