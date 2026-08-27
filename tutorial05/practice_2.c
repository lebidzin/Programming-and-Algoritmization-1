#include <stdio.h>
#include <math.h>

#include "geometry.h"

int calc_rectangular_prism(void){
  double a,b,c;
  printf("Prosim zadejte delku hran Kvadru(Rectangular cuboid) a b c:\n");
  if(scanf("%lf %lf %lf", &a, &b, &c) != 3 || a<=0 || b<=0 || c<=0){
    printf("Hrany a b c maji byt cisla >0\n");
    return 1;
  }

  // Povrch
  double surface_area = 2*(a*b+b*c+a*c);
  // Objem
  double volume = a*b*c;
  printf("Povrch: %f, Objem: %f\n", surface_area, volume);

  return 0;
}

int calc_triangular_prism(void){
  double a,b,c,S_triangle;
  int calc_triangle_return_code = calc_triangle(1, &a, &b, &c, &S_triangle);
  if(calc_triangle_return_code == 1){
    return 1;
  }
  double v;
  printf("Prosim zadejte vysku 'v' tribokeho hranolu:\n");
  if(scanf("%lf", &v)!=1 || v<=0){
    printf("Vyska ma byt >0\n");
    return 1;
  }

  double S_lateral = (a+b+c)*v;
  // Celkovy povrch:
  double S = 2*S_triangle+S_lateral;
  // Objem:
  double V = S_triangle*v;

  printf("Povrch: %f; Objem: %f\n", S, V);
  return 0;
}

int calc_cone(void){
  double d,v;
  int calc_circle_return = calc_circle(1, &d);
  if(calc_circle_return == 1){
    return 1;
  }
  printf("Prosim, zadejte vysku 'v':\n");
  if(scanf("%lf", &v)!=1 || v<=0){
    printf("Vyska 'v' ma byt >0\n");
    return 1;
  }

  double r = d/2.0;
  double slant_height = sqrt(r*r+v*v);
  double base_area = M_PI*(r*r);
  double lateral_area = M_PI*r*slant_height;
  //Celkovy povrch:
  double surface_area = base_area+lateral_area;
  // Objem:
  double volume = 1.0/3.0*base_area*v;

  printf("Celkovy povrch kuzelu: %f; Objem: %f\n",surface_area, volume);
  return 0;
}

int calc_sphere(void){
  double d;
  printf("Prosim zadejte prumer koule 'd':\n");
  if(scanf("%lf", &d)!=1 || d<=0){
    printf("Prumer koule ma byt >0\n");
    return 1;
  }

  double r = d/2.0;
  double surface_area = 4*M_PI*(r*r);
  double volume = 4.0/3.0*M_PI*(r*r*r);

  printf("Povrch kouli: %f; Objem: %f\n",surface_area, volume);
  return 0;
}

int main(void){
  calc_rectangular_prism();
  calc_triangular_prism();
  calc_cone();
  calc_sphere();
  return 0;
}