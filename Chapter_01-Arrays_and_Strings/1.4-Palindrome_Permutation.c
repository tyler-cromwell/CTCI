/*************************************************
 * Solution to question 1.4 - Palindrome Permutation
 * 
 * Status: COMPLETE
 *
 * Assumptions:
 *   - Strings are ASCII
 *   - Lowercase only
 *
 * Notes:
 *   - Algorithm will only handle alphabetic strings
*************************************************/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


int main(int argc, char *argv[]) {
    if (argc < 2 || !isstring(argv[1])) {
        fprintf(stderr, "Please enter a string on the command line\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "String \"%s\" is a palindrome permutation: ", argv[1]);

    long ones = 0;
    size_t l = strlen(argv[1]);
    long *counts = calloc(ALPHABET_LENGTH, sizeof(long));

    for (size_t i = 0; i < l; i++) {
        // Skip space
        if (argv[1][i] == ' ') {
            l--;
            continue;
        }
        // If character is lowercase
        else if (argv[1][i] >= 'a' && argv[1][i] <= 'z') {
            counts[argv[1][i] - 'a']++;
        }
        else {
            fprintf(stdout, "false\n");
            goto exit;
        }
    }

    // String is of even length
    if (l % 2 == 0) {
        for (size_t i = 0; i < ALPHABET_LENGTH; i++) {
            if (counts[i] % 2 == 1) {
                fprintf(stdout, "false\n");
                goto exit;
            }
        }
    }
    // String is of odd length
    else {
        for (size_t i = 0; i < ALPHABET_LENGTH; i++) {
            if (counts[i] == 1) {
                ones++;
            }
            if (ones > 1) {
                fprintf(stdout, "false\n");
                goto exit;
            }
        }
    }

    fprintf(stdout, "true\n");
exit:
    free(counts);
    return EXIT_SUCCESS;
}
