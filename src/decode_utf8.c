#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "ConvertUTF.h"
uint32_t *decode_utf8(const char *message)
{
    size_t n = strlen(message);
    uint32_t *out = malloc(sizeof(*out)*(n + 1));
    assert(out != NULL && "Buy more RAM lol");
    memset(out, 0, sizeof(*out)*(n + 1));
    uint32_t *out_end = out;

    ConversionResult result = ConvertUTF8toUTF32(
                                  (const UTF8**) &message, (const UTF8*) (message + n),
                                  (UTF32**) &out_end, (UTF32*) out + n, 0);
    switch (result) {
        case conversionOK: return out;
        case sourceExhausted: {
            free(out);
            fprintf(stderr, "ERROR: partial character in source, but hit end");
            return NULL;
        }
        break;
        case targetExhausted: assert(0 && "unreachable");
        case sourceIllegal: {
            free(out);
            fprintf(stderr, "ERROR: source sequence is illegal/malformed");
            return NULL;
        } break;
    }
    assert(0 && "unreachable");
}
