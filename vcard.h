#ifndef _VCARD_H
#define _VCARD_H

struct vcard_struct {
  char *cnet;
  char *email;
  char *fname;
  char *lname;
  char *tel;
};

typedef struct vcard_struct *vcard;

vcard vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel);

void vcard_free(vcard c);

void vcard_show(vcard c);

#endif /* _VCARD_H */
