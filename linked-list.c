#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked-list.h"

/*sll_cons : (char*, sll*) -> sll* */
/*build new list with given string at the head */
sll *sll_cons(char *s, sll *ss)
{  
  sll *ssll = (sll*)malloc(sizeof(struct string_list_node));
  ssll->s = s;
  ssll->next = ss;

  return ssll;
}

/*sll_length: sll* -> int* */
/* return number of strings in the given list */
int sll_length(sll *ss)
{
  int count=0;

  for(ss; ss!=NULL ; ss = ss->next)
    count++;
  
  return count;
}

/* sll_member: (sll* char*) -> int */
/* test membership of given string in given list */
/* use strcmp to compare strings */
int sll_member(sll *ss, char *s)
{
  for(ss; ss!=NULL ; ss = ss->next)
    if(strcmp(ss->s, s)==0)
      return 1;
  return 0;
}

/*sll_show : sll* -> <void> */
/* print a representation of the linked list to stdout */
void sll_show(sll *ss)
{
  for(ss; ss!=NULL; ss = ss->next)
    printf("\"%s\"->", ss->s);
  printf(".\n");
}

/*int main()
{
  sll *tester = sll_cons("first", NULL);
  tester = sll_cons("second", tester);

  printf("%s\n", tester->s);
  printf("%d\n", sll_length(tester));
  printf("%d\n", sll_member(tester, "third"));
  sll_show(tester);

  return 0;
  } */
