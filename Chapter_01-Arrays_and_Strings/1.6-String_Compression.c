/*************************************************
 * Solution to question 1.6 - String Compression
 *
 * Status: INCOMPLETE
 *
 * Assumptions:
 *   - Strings are ASCII
 *   - Strings are alphabetical only
 *   - Case insensitive
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

struct str {
    char *data;
    size_t length;
};


int main(int argc, char *argv[]) {
    if (argc < 2 || !isstring(argv[1])) {
        fprintf(stderr, "Please enter two strings on the command line\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "Compressed string: ");

    struct str s1 = {
        .data = argv[1],
        .length = strlen(argv[1])
    };

    // Determine how many char/count pairs we'll need
    size_t pairs = 0;

    for (size_t i = 1; i <= s1.length; i++) {
        if (s1.data[i] != s1.data[i-1]) {
            pairs++;
        }
    }

    // If new string is not smaller than original
    if (pairs * 2 >= s1.length) {
        fprintf(stdout, "%s\n", s1.data);
        return EXIT_SUCCESS;
    }

    // Allocate space for the pairs in a new string
    struct str s2 = {
        .data = calloc((pairs * 2) + 1, sizeof(char)),
        .length = pairs * 2
    };

    unsigned char count = 1;
    size_t j = 0;

    // Get the counts
    for (size_t i = 1; i <= s1.length; i++) {
        if (s1.data[i] != s1.data[i-1]) {
            s2.data[j+0] = s1.data[i-1];    // Add the character
            s2.data[j+1] = count + '0';     // Add its count
            count = 1;
            j += 2;
        } else {
            count++;
        }
    }

    fprintf(stdout, "%s\n", s2.data);
    free(s2.data);
    return EXIT_SUCCESS;
}
