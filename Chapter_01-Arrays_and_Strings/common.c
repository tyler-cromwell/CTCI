#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "common.h"


bool isinteger(const char *s) {
    size_t l = strlen(s);

    if (s[0] == '-') {
        s++, l--; // Ignore dash
    }

    for (size_t _i = 0; _i < l; _i++) {
        size_t i = (l-1) - _i;

        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}


bool isstring(const char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        if (isprint(s[i]) == 0) {
            return false;
        }
    }

    return true;
}


int qsort_ascending(const void *a, const void *b) {
    const char *aa = a;
    const char *bb = b;
    return strcmp(aa, bb);
}
