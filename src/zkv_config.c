#define  ZKV_CONFIG_C
#include <zkv.h>

#include <yaml.h>

void
zkv_config_init(zkv_config_t *config)
{
    XZERO(config);

    config->max_conn = 1024;
}

void
zkv_config_drop(zkv_config_t *config) {}

void
zkv_config_load(zkv_config_t *config, const char *fname)
{
    FILE *f = fopen(fname, "r");
    if (!f)
        zkv_panic("failed to load config from \"%s\"", fname);

    yaml_parser_t p;
    if(!yaml_parser_initialize(&p))
        zkv_panic("failed to initialize parser!", stderr);

    yaml_parser_set_input_file(&p, f);

    uint8_t eos = 0;
    while (!eos)
    {
        yaml_token_t t;
        yaml_parser_scan(&p, &t);

        switch(t.type)
        {
            case YAML_STREAM_START_TOKEN:
                break;
            case YAML_STREAM_END_TOKEN:
                eos = 1;
                break;

            //TODO: parse
            case YAML_NO_TOKEN:
                break;
            case YAML_VERSION_DIRECTIVE_TOKEN:
                break;
            case YAML_TAG_DIRECTIVE_TOKEN:
                break;
            case YAML_DOCUMENT_START_TOKEN:
                break;
            case YAML_DOCUMENT_END_TOKEN:
                break;
            case YAML_BLOCK_SEQUENCE_START_TOKEN:
                break;
            case YAML_BLOCK_MAPPING_START_TOKEN:
                break;
            case YAML_BLOCK_END_TOKEN:
                break;
            case YAML_FLOW_SEQUENCE_START_TOKEN:
                break;
            case YAML_FLOW_SEQUENCE_END_TOKEN:
                break;
            case YAML_FLOW_MAPPING_START_TOKEN:
                break;
            case YAML_FLOW_MAPPING_END_TOKEN:
                break;
            case YAML_BLOCK_ENTRY_TOKEN:
                break;
            case YAML_FLOW_ENTRY_TOKEN:
                break;
            case YAML_KEY_TOKEN:
                break;
            case YAML_VALUE_TOKEN:
                break;
            case YAML_ALIAS_TOKEN:
                break;
            case YAML_ANCHOR_TOKEN:
                break;
            case YAML_TAG_TOKEN:
                break;
            case YAML_SCALAR_TOKEN:
                break;
        }

        yaml_token_delete(&t);
    }

    yaml_parser_delete(&p);
    fclose(f);
}
