/*************************************************
 * Solution to question 1.5 - One Away
 * Assumptions:
 *   - Strings are ASCII
*************************************************/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define NUMBER_OF_STRINGS 2


bool checkOneLengthDifference(const struct str *shorter, const struct str *longer, size_t *const edits) {
    size_t i1 = 0, i2 = 0;

    while (i1 < shorter->length && i2 < longer->length) {
        if (shorter->data[i1] != longer->data[i2]) {
            if (i1 != i2) {
                (*edits)++;
                return false;
            }
            i2++;
        } else {
            i1++;
            i2++;
        }
    }

    return true;
}


int main(int argc, char *argv[]) {
    if (argc < 3 || !isstring(argv[1]) || !isstring(argv[2])) {
        fprintf(stderr, "Please enter two strings on the command line\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "%s,\t%s -> ", argv[1], argv[2]);

    struct str s1 = {
        .data = argv[1],
        .length = strlen(argv[1])
    };
    struct str s2 = {
        .data = argv[2],
        .length = strlen(argv[2])
    };
    size_t edits = abs(s1.length - s2.length);

    // Already too many edits
    if (edits > 1) {
        fprintf(stdout, "false\n");
        return EXIT_SUCCESS;
    }
    // One length difference
    else if (edits) {
        if (s2.length > s1.length) {
            if (!checkOneLengthDifference(&s1, &s2, &edits)) {
                fprintf(stdout, "false\n");
                return EXIT_SUCCESS;
            }
        }
        else if (s1.length > s2.length) {
            if (!checkOneLengthDifference(&s1, &s2, &edits)) {
                fprintf(stdout, "false\n");
                return EXIT_SUCCESS;
            }
        }
        // else clause won't happen because edits != 0
    }
    // No length difference
    else {
        for (size_t i = 0; i < s1.length; i++) {
            if (s1.data[i] != s2.data[i]) {
                edits++;
            }

            if (edits > 1) {
                fprintf(stdout, "false\n");
                return EXIT_SUCCESS;
            }
        }
    }

    fprintf(stdout, "true\n");
    return EXIT_SUCCESS;
}
