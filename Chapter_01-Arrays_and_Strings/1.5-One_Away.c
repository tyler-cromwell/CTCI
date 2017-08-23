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

#define ALPHABET_LENGTH 26
#define NUMBER_OF_STRINGS 2


int compare(const void *a, const void *b) {
    const char *aa = a;
    const char *bb = b;
    return strcmp(aa, bb);
}


bool isstring(const char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        if (isprint(s[i]) == 0) {
            return false;
        }
    }

    return true;
}


bool checkOneLengthDifference(const char *shorter, const char *longer, const size_t l1, const size_t l2, size_t *const edits) {
    size_t i1 = 0, i2 = 0;

    while (i1 < l1 && i2 < l2) {
        if (shorter[i1] != longer[i2]) {
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

    size_t l1 = strlen(argv[1]);
    size_t l2 = strlen(argv[2]);
    size_t edits = abs(l1 - l2);

    // Already too many edits
    if (edits > 1) {
        fprintf(stdout, "false\n");
        return EXIT_SUCCESS;
    }
    // One length difference
    else if (edits) {
        if (l2 > l1) {
            if (!checkOneLengthDifference(argv[1], argv[2], l1, l2, &edits)) {
                fprintf(stdout, "false\n");
                return EXIT_SUCCESS;
            }
        }
        else if (l1 > l2) {
            if (!checkOneLengthDifference(argv[2], argv[1], l2, l1, &edits)) {
                fprintf(stdout, "false\n");
                return EXIT_SUCCESS;
            }
        }
        // else clause won't happen because edits != 0
    }
    // No length difference
    else {
        for (size_t i = 0; i < l1; i++) {
            if (argv[1][i] != argv[2][i]) {
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
