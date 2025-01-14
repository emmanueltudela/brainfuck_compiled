#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>

#include "type_val.h"

// Made to work with multiple types with an hidden union
// but only implemented methods for int and char for the sake
// of this project

typedef struct llist sllist;

// Empty sllist is NULL
sllist *sllist_create();
void sllist_free(sllist *llist);

/* Is llist an empty llist (NULL)
 */
bool sllist_empty(sllist *llist);

/* Returns next or previous llist starting from llist
 */
sllist *sllist_previous(sllist *llist);
sllist *sllist_next(sllist *llist);

/* Appends or prepends after or before current llist (internal union)
 */
sllist *sllist_append(sllist *llist, stype_val val);
sllist *sllist_prepend(sllist *llist, stype_val val);

/* Appends or prepends given type val after or before current llist
 */
sllist *sllist_append_i(sllist *llist, int val);
sllist *sllist_prepend_i(sllist *llist, int val);
sllist *sllist_append_c(sllist *llist, char val);
sllist *sllist_prepend_c(sllist *llist, char val);

/* Returns value of given llist (internal union)
 */
stype_val sllist_value(sllist *llist);

/* Returns typed value of given llist
 */
int sllist_value_i(sllist *llist);
char sllist_value_c(sllist *llist);

/* Sets value of given llist (internal union)
 */
void sllist_set(sllist *llist, stype_val val);

/* Sets typed value of given llist
 */
void sllist_set_i(sllist *llist, int val);
void sllist_set_c(sllist *llist, char val);

/* Deletes and free current llist and returns previous llist if it exists
 */
sllist *sllist_remove(sllist *llist);

#endif
