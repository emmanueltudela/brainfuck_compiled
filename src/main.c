#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "brainfuck.h"
#include "compile.h"

#define _POSIX_C_SOURCE 200809L

void usage(char *exec) {
    printf("%s source_file target_exec\n", exec);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source_file = argv[1];
    char *exec_file = argv[2];
    char target_source_file[strlen(exec_file) + 3];
    target_source_file[strlen(exec_file) + 2] = '\0';

    strcpy(target_source_file, exec_file);

    target_source_file[strlen(exec_file) + 1] = 'c';
    target_source_file[strlen(exec_file) + 0] = '.';

    FILE *src = fopen(source_file, "r");
    if (!src) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *dst = brainfuck_transpile_to_file(src, target_source_file);

    fclose(src);
    fclose(dst);

    compile(target_source_file, exec_file);
    return EXIT_SUCCESS;
}
