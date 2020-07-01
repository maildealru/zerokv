#ifndef ZKV_DEF_H
#define ZKV_DEF_H

#include <string.h>

#include <libiberty/libiberty.h>

#ifdef __FILE_PREFIX__
#define __FILE_REL__ (__FILE__ + sizeof(__FILE_PREFIX__))
#else
#define __FILE_REL__ (__FILE__)
#endif

#define AINLINE __always_inline

#define STRLN(s) (sizeof(s) - 1)

#define STRSLN(s) (s), STRLN(s)
#define STRLNS(s) STRLN(s), (s)

#define STRSLEN(s) (s), strlen(s)
#define STRLENS(s) strlen(s), (s)

#define BUFFSZ(b) (b), sizeof(b)
#define SZBUFF(b) sizeof(b), (b)

#define XZERO(b) memset((b), 0, sizeof(*(b)))

#define   B    *1
#define KiB   B*1024
#define MiB KiB*1024
#define GiB MiB*1024

#endif
