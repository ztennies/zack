#include <stdio.h>
#include <math.h>

#define LIM 11

int julia_test(int lim, double c_re, double c_im,
        double z_re, double z_im)
{
  double a = ((z_re*z_re)-(z_im*z_im));
  double b = 2*(z_re*z_im);
  double re = a+c_re;
  double im = b+c_im;

  if((sqrt((re*re)+(im*im)))>=2)
    return lim;
  else if(lim > LIM)
    return -1;
  else
    return julia_test(lim+1, c_re, c_im, re, im);
}

void show_julia()
{
  int lim;
  double i;
  double j;
  double m;
  double n;
  double x = 4;
  double y = 480;
  
  /* heading of ppm file */
  printf("P3\n");
  printf("480 480\n");
  printf("255\n");

  for(i=0; i<480; i++)
    for(j=0; j<480; j++){
      m = (i*(x/y))-2;
      n = (j*(x/y))-2;
      lim = julia_test(0,-0.390541,-0.586788, m, n);
      if(lim < 0) {
        printf("0 0 0\n");
      } else {
        printf("255 255 255\n");
      }
    }
}

/* main */
main ()
{  
  show_julia();
  return 0;
}
