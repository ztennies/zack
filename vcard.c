#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vcard.h"

void vcard_todo(char *s)
{
  fprintf(stderr, "TODO[vcard]: %s\n", s);
  exit(1);
}

vcard vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
  vcard c = (vcard)malloc(sizeof(struct vcard_struct));
  c->cnet = malloc(100);
  c->cnet = strdup(cnet);
  c->email = malloc(100);
  c->email = strdup(email);
  c->fname = malloc(100);
  c->fname = strdup(fname);
  c->lname = strdup(lname);
  c->lname = strdup(lname);
  c->tel = malloc(100);
  c->tel = strdup(tel);

  return c;
  
  /*vcard_todo("vcard_new");
  return NULL; unreachable */
}

void vcard_free(vcard c)
{
  if(c!=NULL) {
    free(c->cnet);
    free(c->email);
    free(c->fname);
    free(c->lname);
    free(c->tel);
    free(c);
  }

  /* vcard_todo("vcard_free");
  return;  unreachable */
}

void vcard_show(vcard c)
{
  printf("cnet: %s\n", c->cnet);
  printf("email: %s\n", c->email);
  printf("name: %s %s\n", c->fname, c->lname);
  printf("tel: %s\n", c->tel);
  
  /* vcard_todo("vcard_show");
  return; unreachable */
}
