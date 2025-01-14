#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "type_val.h"

sllist *sllist_aux_first(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot get first from NULL llist\n");
        exit(EXIT_FAILURE);
    }

    sllist *first = llist;

    while (sllist_previous(first) != NULL) {
        first = sllist_previous(first);
    }

    return first;
}

sllist *sllist_aux_last(sllist *llist) {
    if (!llist) {
        fprintf(stderr, "Cannot get last from NULL llist\n");
        exit(EXIT_FAILURE);
    }

    sllist *last = llist;

    while (sllist_next(last) != NULL) {
        last = sllist_next(last);
    }

    return last;
}

sllist *sllist_aux_append(sllist *llist, stype_val val) {
    if (!llist) return sllist_append(llist, val);

    sllist *last = sllist_aux_last(llist);
    sllist_append(last, val);
    return llist;
}

sllist *sllist_aux_prepend(sllist *llist, stype_val val) {
    if (!llist) return sllist_prepend(llist, val);

    sllist *first = sllist_aux_first(llist);
    sllist_prepend(first, val);
    return llist;
}

sllist *sllist_aux_append_i(sllist *llist, int val) {
    stype_val val_s;
    val_s.i = val;

    return sllist_aux_append(llist, val_s);
}

sllist *sllist_aux_prepend_i(sllist *llist, int val) {
    stype_val val_s;
    val_s.i = val;

    return sllist_aux_prepend(llist, val_s);
}

sllist *sllist_aux_append_c(sllist *llist, char val) {
    stype_val val_s;
    val_s.c = val;

    return sllist_aux_append(llist, val_s);
}

sllist *sllist_aux_prepend_c(sllist *llist, char val) {
    stype_val val_s;
    val_s.c = val;

    return sllist_aux_prepend(llist, val_s);
}

sllist *sllist_aux_remove_all(sllist *llist) {
    if (!llist) return NULL;

    llist = sllist_aux_first(llist);

    while (llist != NULL) {
        llist = sllist_remove(llist);
    }

    return NULL;
}
