#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list_aux.h"

unsigned int stripe_target_size(sllist *filecontent) {
    sllist *llist = sllist_aux_first(filecontent);

    unsigned int max_index = 0;
    unsigned int index = 0;

    while (llist != NULL) {
        char c = sllist_value_c(llist);

        switch (c) {
            case '>':
                index++;
                if (index > max_index) {
                    max_index = index;
                }
                break;
            case '<':
                index--;
                break;
            default:
                break;
        }

        llist = sllist_next(llist);
    }

    return max_index + 1;
}

sllist *file_to_llist(FILE *file) {
    sllist *llist = sllist_create();
    char buffer;
    size_t read = fread(&buffer, sizeof(char), 1, file);
    while (read > 0) {
        llist = sllist_aux_append_c(llist, buffer);
        read = fread(&buffer, sizeof(char), 1, file);
    }
    return llist;
}

void transpile_c_indentation_level(FILE *file, unsigned int indentation_level) {
    for (int i = 0; i < indentation_level; i++) {
        fprintf(file, "\t");
    }
}

void transpile_c_head(FILE *file) {
    fprintf(file, "#include <stdio.h>\n#include <stdlib.h>\n\nint main(void) {\n");
}

void transpile_c_stripe(FILE *file, unsigned int stripe_size, unsigned int indentation_level) {
    transpile_c_indentation_level(file, indentation_level);
    fprintf(file, "int *stripe = malloc(sizeof(int) * %u);\n", stripe_size);
    transpile_c_indentation_level(file, indentation_level);
    fprintf(file, "int index = 0;\n");
}

void transpile_c_tail(FILE *file) {
    fprintf(file, "}\n");
}

FILE *brainfuck_transpile_to_file(FILE *src, char *dstname) {
    sllist *llist = file_to_llist(src);

    unsigned int indentation_level = 1;
    int transpiled_index = 0;

    FILE *dst = fopen(dstname, "w");
    if (!dst) {
        return NULL;
    }

    transpile_c_head(dst);
    transpile_c_stripe(dst, stripe_target_size(llist), indentation_level);

    // Transpile brainfuck
    sllist *ptr = sllist_aux_first(llist);
    while (ptr != NULL) {
        char c = sllist_value_c(ptr);
        switch (c) {
            case '+':
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "stripe[index]++;\n");
                break;
            case '-':
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "stripe[index]--;\n");
                break;
            case '.':
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "printf(\"%s\", (char)stripe[index]);\n", "%c");
                break;
            case ',':
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "stripe[index] = getchar();\n");
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "while ((char)(stripe[index]) == '\\n') {\n");
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "\tstripe[index] = getchar();\n");
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "}\n");
                break;
            case '[':
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "while (stripe[index] != 0) {\n");
                indentation_level++;
                break;
            case ']':
                indentation_level--;
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "}\n");
                break;
            case '>':
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "index++;\n");
                transpiled_index++;
                break;
            case '<':
                transpile_c_indentation_level(dst, indentation_level);
                fprintf(dst, "index--;\n");
                transpiled_index--;
                break;
        }
        ptr = sllist_next(ptr);
    }

    transpile_c_tail(dst);

    llist = sllist_aux_remove_all(llist);
    return dst;
}
