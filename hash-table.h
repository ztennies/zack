#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include "linked-list.h"

/* hash table of strings, with linked list buckets */

struct hash_table {
  int n_buckets;
  sll **buckets;
};

typedef struct hash_table htbl;

/* hash : char -> unsigned int */
/* compute hash code for given string */
unsigned long hash(char *s);

/* htbl_init : int -> htbl* */
/* allocate space for a new hash table of given size */
/* all buckets must initially contain the empty list */
htbl *htbl_init(int sz);

/* htbl_add : (htbl*, char*) -> int */ 
/* add string s to hast table t */
/* return the number of strings in s's bucket _after_ inserting it */
int htbl_add(htbl *t, char *s);

/* htbl_member : (htbl*, char*) -> int */
/* test membership of given string in given table */
/* the integer returned is a (pseudo) boolean */
int htbl_member(htbl *t, char *s);

/* htbl_show : htbl* -> <void> */
/* print a represntation of the hash table to stdout */
void htbl_show(htbl *t);

#endif /* _HASH_TABLE_H */
