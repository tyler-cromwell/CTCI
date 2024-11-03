#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

#define ALPHABET_LENGTH 26
#define ASCII_LENGTH    128

struct str {
    char *data;
    size_t length;
};

extern bool isinteger(const char *s);
extern bool isstring(const char *s);
extern int qsort_ascending(const void *a, const void *b);

#endif
