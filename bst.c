#include <stdlib.h>
#include <stdio.h>

#include "vcard.h"
#include "bst.h"


bst bst_singleton(vcard c)
{
  bst t = (bst)malloc(sizeof(struct bst_node));
  t->c = c;
  t->lsub = NULL;
  t->rsub = NULL;
  
  return t;
}

bst bst_insert(bst t, vcard c)
{
  if(t==NULL) {
    t = bst_singleton(c);
  }
  else {
    if (strcmp(c->cnet,t->c->cnet)==0) {
	fprintf(stderr, "Cnet %s already exists\n", c->cnet);
	exit(1);
      }
    else if(strcmp(c->cnet,t->c->cnet)<0)
      t->lsub = bst_insert(t->lsub, c);
    else if(strcmp(c->cnet,t->c->cnet)>0)
      t->rsub = bst_insert(t->rsub, c);
  }
  return t;
}

unsigned int bst_num_entries(bst t)
{
  unsigned int count = 0;

  if(t!=NULL) {
    count++;
    if(t->lsub!=NULL)
      count+=bst_num_entries(t->lsub);
    if(t->rsub!=NULL)
      count+=bst_num_entries(t->rsub);
  }
  
  return count;
}

unsigned int bst_height(bst t)
{
  unsigned int height = 0;
  unsigned int ltot = 0;
  unsigned int rtot = 0;

  if(t!=NULL) {
    height++;
    if(t->lsub!=NULL)
      ltot+=bst_height(t->lsub);
    if(t->rsub!=NULL)
      rtot+=bst_height(t->rsub);
  }
  if(ltot<rtot)
    height+=rtot;
  else
    height+=ltot;

  return height;
}

/* return NULL is nothing is found */
vcard bst_search(bst t, char *cnet, int *n_comparisons)
{
  if(t==NULL) {
    return NULL;
  }
  else if(strcmp(cnet,t->c->cnet) == 0) {
    ++*n_comparisons;
    return t->c;
  }
  else if(strcmp(cnet,t->c->cnet) > 0) {
    ++*n_comparisons;
    return bst_search(t->rsub,cnet,n_comparisons);
  }
  else if(strcmp(cnet,t->c->cnet) < 0) {
    ++*n_comparisons;
    return bst_search(t->lsub,cnet,n_comparisons);
  }
}

void bst_free(bst t)
{
  if(t!=NULL) {
    if(t->lsub!=NULL)
      bst_free(t->lsub);
    if(t->rsub!=NULL)
      bst_free(t->rsub);
    vcard_free(t->c);
    free(t);
  }
}

