#define  ZKV_SYS_C
#include <zkv.h>

void
zkv_panic(const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);

    char buff[256];
    vsnprintf(BUFFSZ(buff), fmt, va);

    perror(buff);
    xexit(-1);
}
