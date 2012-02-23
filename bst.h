#ifndef _BST_H
#define _BST_H

#include "vcard.h"

typedef struct bst_node *bst;

struct bst_node {
  vcard c;
  bst lsub;
  bst rsub;
};

bst bst_singleton(vcard c);

/* use cnet alphabetical order */
bst bst_insert(bst t, vcard c);

unsigned int bst_num_entries(bst t);

unsigned int bst_height(bst t);

/* return NULL is nothing is found */
vcard bst_search(bst t, char *cnet, int *n_comparisons);

void bst_free(bst t);

#endif /* _BST_H */
