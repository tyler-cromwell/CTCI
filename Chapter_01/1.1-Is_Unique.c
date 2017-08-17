/***************************************
 * Solution to question 1.1 - Is unique
 * Assumptions:
 *   - Strings are ASCII
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_LENGTH 128


int compare(const void *a, const void *b) {
    const char *aa = a;
    const char *bb = b;
    return strcmp(aa, bb);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please enter a string on the command line\n");
        return EXIT_FAILURE;
    } else {
        fprintf(stdout, "String \"%s\" is unique: ", argv[1]);
    }

    size_t l = strlen(argv[1]);

    if (l > ASCII_LENGTH) {
        fprintf(stdout, "false\n");
        return EXIT_SUCCESS;
    }

    char *s = calloc(l+1, sizeof(char));
    strncpy(s, argv[1], l * sizeof(char));

    qsort(s, l, sizeof(char), compare);

    for (size_t i = 0; i < l; i++) {
        if (s[i] == s[i-1]) {
            fprintf(stdout, "false\n");
            free(s);
            return EXIT_SUCCESS;
        }
    }

    fprintf(stdout, "true\n");
    free(s);
    return EXIT_SUCCESS;
}