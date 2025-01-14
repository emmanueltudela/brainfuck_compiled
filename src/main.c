#include <stdio.h>
#include <stdlib.h>

#include "compile.h"

int main(int argc, char *argv[]) {
    int r = compile("test.c", "test");
    return EXIT_SUCCESS;
}
