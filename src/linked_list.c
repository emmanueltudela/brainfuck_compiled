#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "type_val.h"

typedef struct llist {
    stype_val val;
    sllist *previous;
    sllist *next;
} sllist;

sllist *sllist_create() {
    return NULL;
}

void sllist_free(sllist *llist) {
    if (llist) free(llist);
}

bool sllist_empty(sllist *llist) {
    return llist == NULL;
}

sllist *sllist_previous(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot get previous from NULL linked_list\n");
        exit(EXIT_FAILURE);
    }

    return llist->previous;
}

sllist *sllist_next(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot get next from NULL linked_list\n");
        exit(EXIT_FAILURE);
    }

    return llist->next;
}

sllist *sllist_append(sllist *llist, stype_val val) {
    if (!llist) {
        llist = malloc(sizeof(sllist));
        if (!llist) return NULL;

        llist->val = val;
        llist->previous = NULL;
        llist->next = NULL;
        return llist;
    }

    if (!llist->next) {
        sllist *new = malloc(sizeof(sllist));
        if (!new) {
            fprintf(stderr, "Error when allocating new linked_list\n");
            exit(EXIT_FAILURE);
        }

        new->val = val;
        new->previous = llist;
        new->next = NULL;

        llist->next = new;

        return llist;
    }

    // next exists
    sllist *new = malloc(sizeof(sllist));
    if (!new) {
        fprintf(stderr, "Error when allocating new linked_list\n");
        exit(EXIT_FAILURE);
    }

    new->val = val;
    new->previous = llist;
    new->next = llist->next;

    llist->next->previous = new;
    llist->next = new;

    return llist;
}

sllist *sllist_prepend(sllist *llist, stype_val val) {
    if (!llist) {
        llist = malloc(sizeof(sllist));
        if (!llist) return NULL;

        llist->val = val;
        llist->previous = NULL;
        llist->next = NULL;
        return llist;
    }

    if (!llist->previous) {
        sllist *new = malloc(sizeof(sllist));
        if (!new) {
            fprintf(stderr, "Error when allocating new linked_list\n");
            exit(EXIT_FAILURE);
        }

        new->val = val;
        new->next = llist;
        new->previous = NULL;

        llist->previous = new;

        return llist;
    }

    // next exists
    sllist *new = malloc(sizeof(sllist));
    if (!new) {
        fprintf(stderr, "Error when allocating new linked_list\n");
        exit(EXIT_FAILURE);
    }

    new->val = val;
    new->next = llist;
    new->previous = llist->previous;

    llist->previous->next = new;
    llist->previous = new;

    return llist;
}

sllist *sllist_append_i(sllist *llist, int val) {
    stype_val val_s;
    val_s.i = val;

    return sllist_append(llist, val_s);
}

sllist *sllist_prepend_i(sllist *llist, int val) {
    stype_val val_s;
    val_s.i = val;

    return sllist_prepend(llist, val_s);
}

sllist *sllist_append_c(sllist *llist, char val) {
    stype_val val_s;
    val_s.c = val;

    return sllist_append(llist, val_s);
}

sllist *sllist_prepend_c(sllist *llist, char val) {
    stype_val val_s;
    val_s.c = val;

    return sllist_prepend(llist, val_s);
}

stype_val sllist_value(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot get value from NULL linked_list\n");
        exit(EXIT_FAILURE);
    }

    return llist->val;
}

int sllist_value_i(sllist *llist) {
    stype_val val_s = sllist_value(llist);
    return val_s.i;
}

char sllist_value_c(sllist *llist) {
    stype_val val_s = sllist_value(llist);
    return val_s.c;
}

sllist *sllist_remove(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot remove NULL linked_list\n");
        exit(EXIT_FAILURE);
    }

    if (!llist->next && !llist->previous) {
        free(llist);
        return NULL;
    }

    if (!llist->next) {
        sllist *new = llist->previous;
        new->next = NULL;

        free(llist);

        return new;
    }

    if (!llist->previous) {
        sllist *new = llist->next;
        new->previous = NULL;

        free(llist);

        return new;
    }

    // If previous and next return previous
    sllist *new = llist->previous;
    new->next = llist->next;
    llist->next->previous = new;

    free(llist);

    return new;
}

void sllist_set(sllist *llist, stype_val val) {
    llist->val = val;
}

void sllist_set_i(sllist *llist, int val) {
    stype_val val_s;
    val_s.i = val;
    sllist_set(llist, val_s);
}

void sllist_set_c(sllist *llist, char val) {
    stype_val val_s;
    val_s.c = val;
    sllist_set(llist, val_s);
}
