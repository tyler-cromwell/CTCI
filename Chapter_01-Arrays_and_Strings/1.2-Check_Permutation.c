/*************************************************
 * Solution to question 1.2 - Check Permutation
 *
 * Status: COMPLETE
 *
 * Assumptions:
 *   - Strings are ASCII
 *   - Case sensitive
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Please enter two strings on the command line\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "String \"%s\" is a permutation of \"%s\": ", argv[2], argv[1]);

    // Not permutations if lengths differ
    size_t l1 = strlen(argv[1]);
    size_t l2 = strlen(argv[2]);

    if (l1 != l2) {
        fprintf(stdout, "false\n");
        return EXIT_SUCCESS;
    }

    // Create sorted copies
    char *s1 = calloc(l1+1, sizeof(char));
    char *s2 = calloc(l2+1, sizeof(char));

    strncpy(s1, argv[1], l1 * sizeof(char));
    strncpy(s2, argv[2], l2 * sizeof(char));

    qsort(s1, l1, sizeof(char), qsort_ascending);
    qsort(s2, l2, sizeof(char), qsort_ascending);

    // Not a permutation if sorted copies don't equal
    if (strncmp(s1, s2, l1)) {
        fprintf(stdout, "false\n");
        return EXIT_SUCCESS;
    }

    fprintf(stdout, "true\n");
    free(s1);
    free(s2);
    return EXIT_SUCCESS;
}
