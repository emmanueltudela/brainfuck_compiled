#ifndef __LINKED_LIST_AUX_H__
#define __LINKED_LIST_AUX_H__

#include "linked_list.h"
#include "type_val.h"

/* Returns very first or last llist from chain
 */
sllist *sllist_aux_first(sllist *llist);
sllist *sllist_aux_last(sllist *llist);

/* Appends or prepends at beginning or end of chain (internal union)
 */
sllist *sllist_aux_append(sllist *llist, stype_val val);
sllist *sllist_aux_prepend(sllist *llist, stype_val val);

/* Appends or preprends typed value at beginning or end of chain
 */
sllist *sllist_aux_append_i(sllist *llist, int val);
sllist *sllist_aux_prepend_i(sllist *llist, int val);
sllist *sllist_aux_append_c(sllist *llist, char val);
sllist *sllist_aux_prepend_c(sllist *llist, char val);

/* Remove and free every llist from chain
 */
sllist *sllist_aux_remove_all(sllist *llist);

#endif
