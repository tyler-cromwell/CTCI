/*************************************************
 * Solution to question 1.3 - URLify
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


bool isstring(const char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        if (isprint(s[i]) == 0) {
            return false;
        }
    }

    return true;
}


bool isinteger(const char *s) {
    size_t l = strlen(s);

    if (s[0] == '-') {
        s++, l--; // Ignore dash
    }

    for (size_t _i = 0; _i < l; _i++) {
        size_t i = (l-1) - _i;  // Start at the end

        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}


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

    char *s = calloc(length+1, sizeof(char));
    long l = strlen(argv[1]);
    long c = 0;

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
