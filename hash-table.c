#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash-table.h"
#include "linked-list.h"

/*hash : char -> unsigned int */
/* compute hash code for given string */
unsigned long hash(char *s)
{
  unsigned long res = 17;
  int i=0;

  while(s[i]!='\0')
    res = res*37+s[i++];

  return res;
}

/*htbl_init : int -> htbl* */
/*allocate space for a new hash table of given size */
/*all buckets must initially contain the empty list */
htbl *htbl_init(int sz)
{
  int i=0;
  htbl *new_tbl = (htbl*)malloc(sizeof(struct hash_table));
  /* might not need this...as we are heap allocating the sll */
  new_tbl->buckets = (sll*)malloc(sz*sizeof(struct string_list_node));
  new_tbl->n_buckets = sz;
  for(i;i<sz;i++)
    new_tbl->buckets = NULL;
  
  return new_tbl;
}

/*htbl_add : (htbl*,char*) -> int */
/*add string s to hash table t */
/*return the number of strings in s's bucket after inserting it */
int htbl_add(htbl *t, char*s)
{
  t->buckets[hash(s)]=sll_cons(s,t->buckets[hash(s)]);
  return sll_length(t->buckets[hash(s)]);
}

/*htbl_member : (htbl*,char*) -> int */
/*test membership of given string in given table */
/*the integer returned is a (psuedo) boolean */
int htbl_member(htbl *t, char *s)
{
  int i=0;
  for(i;i<t->n_buckets;i++)
    if(sll_member(t->buckets[i],s)==1)
      return 1;
  return 0;
}

/*htbl_show : htbl* -> <void> */
/*print a representation of the hash table to stdout */
void htbl_show(htbl *t)
{
  int i;
  for(i=0;i<t->n_buckets;i++) {
    printf("[%d]\t", i);
    sll_show(t->buckets[i]);
  }
}
  
