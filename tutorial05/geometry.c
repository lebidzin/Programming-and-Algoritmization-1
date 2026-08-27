#include <stdio.h>
#include <math.h>

#include "geometry.h"

#define PI 3.14159

int calc_triangle(int only_return, double *a, double *b, double *c, double *area){
  printf("Prosim zadejte delku stran trojuhelniku a b c:\n");
  if(scanf("%lf %lf %lf", a, b, c) != 3 || *a<=0 || *b<=0 || *c<=0){
    printf("a b c maji byt cisla >0\n");
    return 1;
  }

  if(!(*a+*b>*c && *a+*c>*b && *b+*c>*a)){
    printf("Trojuhelnik se strany a: %f, b: %f, c: %f nemuze existovat\n", *a,*b,*c);
    return 1;
  }

  double triangle_perimeter = *a+*b+*c;

  double s = (*a+*b+*c)/2.0;
  *area = sqrt(s*(s-*a)*(s-*b)*(s-*c));

  if(!only_return){
    printf("Obvod: %f, Obsah: %f\n", triangle_perimeter, *area);
  }

  return 0;
}

int calc_circle(int only_return, double *d){
  printf("Prosim zadejte prumer(diameter) kruhu d:\n");
  if(scanf("%lf", d) != 1 || *d<=0){
    printf("prumer d ma byt >0\n");
    return 1;
  }

  double perimeter = PI*(*d);

  double area = (PI*(*d)*(*d))/4.0;

  if(!only_return){
    printf("Obvod: %f, Obsah: %f\n", perimeter, area);
  }

  return 0;
}