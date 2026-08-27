#include <stdio.h>
#include <math.h>

#include "geometry.h"

#define PI 3.14159

int calc_rectangle(void){
  double a,b;
  printf("Prosim zadejte delku stran obdelniku a b:\n");
  if(scanf("%lf %lf", &a, &b) != 2 || a<=0 || b<=0){
    printf("a b maji byt cisla >0\n");
    return 1;
  }

  double perimeter = 2*(a+b);

  double area = a*b;

  printf("Obvod: %f, Obsah: %f\n", perimeter, area);

  return 0;
}

int calc_parallelogram(void){
  double a,b;
  printf("Prosim zadejte delku stran rovnobezniku a b:\n");
  if(scanf("%lf %lf", &a, &b) != 2 || a<=0 || b<=0){
    printf("a b maji byt cisla >0\n");
    return 1;
  }

  double alpha_deg;
  printf("Prosim zadejte uhel 0<=alpha<=180:\n");
  if(scanf("%lf", &alpha_deg) != 1 || alpha_deg <= 0 || alpha_deg >= 180){
    printf("Uhel alpha ma byt >0 a <180\n");
    return 1;
  }

  double perimeter = 2*(a+b);

  double alpha_rad = alpha_deg*PI/180;
  double area = a*b*sin(alpha_rad);

  printf("Obvod: %f, Obsah: %f\n", perimeter, area);

  return 0;
}

int main(void){
  double a,b,c,area;
  calc_triangle(0, &a, &b, &c, &area);
  calc_rectangle();
  calc_parallelogram();
  double d;
  calc_circle(0, &d);
  return 0;
}