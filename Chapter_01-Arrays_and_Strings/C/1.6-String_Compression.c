/*************************************************
 * Solution to question 1.6 - String Compression
 *
 * Status: COMPLETE
 *
 * Assumptions:
 *   - Strings are ASCII
 *   - Strings are alphabetical only
 *   - Case insensitive
*************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


static inline size_t ldigits(long number) {
    return (size_t) (floor(log10(labs(number))) + 1);
}


static long lreverse(long num) {
    long rev = 0;

    while (num > 0) {
        rev = (rev * 10) + (num % 10);
        num /= 10;
    }

    return rev;
}


int main(int argc, char *argv[]) {
    if (argc < 2 || !isstring(argv[1])) {
        fprintf(stderr, "Please enter a string on the command line\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "Compressed string: ");

    struct str s1 = {
        .data = argv[1],
        .length = strlen(argv[1])
    };

    // Determine how many chars pairs we'll need
    size_t chars = 0, digits = 0, count = 1;

    for (size_t i = 1; i <= s1.length; i++) {
        if (s1.data[i] != s1.data[i-1]) {
            chars++;
            digits += ldigits(count);
            count = 1;
        } else {
            count++;
        }
    }

    // If new string is not smaller than original
    if (chars + digits >= s1.length) {
        fprintf(stdout, "%s\n", s1.data);
        return EXIT_SUCCESS;
    }

    // Allocate space for the pairs in a new string
    struct str s2 = {
        .data = calloc((chars + digits) + 1, sizeof(char)),
        .length = chars + digits
    };

    size_t s = 0;

    // Create new string
    for (size_t i = 1; i <= s1.length; i++) {
        if (s1.data[i] != s1.data[i-1]) {
            s2.data[s] = s1.data[i-1];    // Add the character
            size_t reverse = lreverse(count);

            // Save each digit
            for (size_t j = 0; j < ldigits(count); j++) {
                s++;
                s2.data[s] = (reverse % 10) + '0';
                reverse /= 10;
            }

            count = 1;
            s++;
        } else {
            count++;
        }
    }

    fprintf(stdout, "%s\n", s2.data);
    free(s2.data);
    return EXIT_SUCCESS;
}
