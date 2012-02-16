#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "linked-list.h"
#include "hash-table.h"

#define DEFAULT_SIZE 10  /* default hash table size */
#define MAX_LINE_LEN 256 /* we don't expect very long lines */

void err_table_size(int sz)
{
  fprintf(stderr,"illegal table size %d; table size must be positive\n", sz);
  exit(1);
}

/* Allocate a string on the heap and fill it with '\0' chars. */
char *alloc_str(int sz) 
{
  int i;
  char *s = (char *)malloc(sz*sizeof(char));
  /* Note: it's good practice, when allocating space for a string,
   * to zero out the string's characters.
   */
  for (i=0; i<sz; i++)
    s[i] = '\0';
  return s;
}

/* trim_newline replaces the newline at the end of the string (if there
 *   is one) with '\0', and then calls strdup on the result,
 *   returning a pointer to the duplicated string.
 * The resulting string has no extra characters at the end. */
char *trim_newline(char *s)
{
  int n = strlen(s);
  if (s[n-1]=='\n')
    s[n-1]='\0';
  return strdup(s);
}

int main(int argc, char *argv[])
{
  htbl *tbl;
  int sz = DEFAULT_SIZE;
  char c;
  /* process command-line options */
  while ((c=getopt(argc,argv,"s:"))!=-1) {
    switch (c) {
    case 's':
      sz = atoi(optarg);
      if (sz<1)
	err_table_size(sz);
      break;
    case '?':
      /* getopt will print an error message here */
      exit(1);
    }
  }
  /* build a new empty hash table */
  tbl = htbl_init(sz);
  /* read a line at a time from stdin, add non-empty strings into the table */
  while (!feof(stdin)) {
    char *s = alloc_str(MAX_LINE_LEN);
    char *t;
    fgets(s,MAX_LINE_LEN,stdin);
    t = trim_newline(s);
    free(s);
    if (strlen(t)>0)
      htbl_add(tbl,t);
  }
  htbl_show(tbl);

/* membership tests -- uncomment to run  */
/* These assume you've run ./htbl <cnets */
/* First, test a cnet that is not present in cnets: */
/* printf("htbl_member(\"jack-nicklaus\"): %d\n", htbl_member(tbl, "jack-nicklaus")); */
/* Now test a (randomly selected) cnet that is present in cnets: */
/* printf("htbl_member(\"ekcasey\"): %d\n", htbl_member(tbl, "ekcasey")); */
/* Try your own cnet: */
/* printf("htbl_member(\"try-your-cnet\"): %d\n", htbl_member(tbl, "try-your-cnet")); */

  return 0;
}
