#include <zkv.h>

static const char *
zkv_parse_config_fname(int argc, char **argv);

int
main(int argc, char **argv)
{
    zkv_config_t config;
    zkv_config_init(&config);

    const char *config_fname = zkv_parse_config_fname(argc, argv);
    if (config_fname)
        zkv_config_load(&config, config_fname);

    zkv_log_init(&config);
    zkv_log_i("initialized...");

    zkv_log_drop();
    zkv_config_drop(&config);

    return 0;
}

static const char *
zkv_parse_config_fname(int argc, char **argv)
{
    if (argc != 3)
        return NULL;
    if (strcmp(argv[1], "-c"))
        return NULL;
    return argv[2];
}
