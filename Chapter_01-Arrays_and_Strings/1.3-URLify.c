/*************************************************
 * Solution to question 1.3 - URLify
 * 
 * Status: COMPLETE
 *
 * Assumptions:
 *   - Strings are ASCII
 *   - Given string has enough extra space on the end
 *   - Length of the string is given
*************************************************/

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


int main(int argc, char *argv[]) {
    if (argc < 3 || !isstring(argv[1]) || !isinteger(argv[2])) {
        fprintf(stderr, "Please enter a string then a postive integer on the command line\n");
        return EXIT_FAILURE;
    }

    errno = 0;
    long length = strtol(argv[2], NULL, 10);

    if (errno == ERANGE) {
        fprintf(stderr, "%s: %s: %s\n", argv[0], argv[2], strerror(errno));
        return EXIT_FAILURE;
    }

    // Create buffer for URLified
    char *s = calloc(length+1, sizeof(char));
    long l = strlen(argv[1]);
    long c = 0;

    // Replace space with %20 otherwise copy
    for (size_t i = 0; i < l-c; i++) {
        if (argv[1][i] == ' ') {
            s[i+c+0] = '%';
            s[i+c+1] = '2';
            s[i+c+2] = '0';
            c += 2;
        } else {
            s[i+c+0] = argv[1][i];
        }
    }

    fprintf(stdout, "%s\n", s);
    free(s);
    return EXIT_SUCCESS;
}
