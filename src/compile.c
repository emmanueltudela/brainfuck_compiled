#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

int compile(char *filename, char *execname) {
    pid_t pid = fork();
    if (!pid) {
        if (execname == NULL) {
            execlp("gcc", "gcc", filename, NULL);
        } else {
            execlp("gcc", "gcc", filename, "-o", execname, NULL);
        }
        exit(EXIT_FAILURE);
    }

    wait(NULL);
    return EXIT_SUCCESS;
}
