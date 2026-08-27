#include <stdio.h>
#include <math.h>

#define PI 3.14159

int calc_triangle(){
  double a,b,c;
  printf("Prosim zadejte delku stran trojuhelniku a b c:\n");
  if(scanf("%lf %lf %lf", &a, &b, &c) != 3 || a<=0 || b<=0 || c<=0){
    printf("a b c maji byt cisla >0\n");
    return 1;
  }

  if(!(a+b>c && a+c>b && b+c>a)){
    printf("Trojuhelnik se strany a: %f, b: %f, c: %f nemuze existovat\n", a,b,c);
    return 1;
  }

  double triangle_perimeter = a+b+c;

  double s = (a+b+c)/2.0;
  double triangle_area = sqrt(s*(s-a)*(s-b)*(s-c));

  printf("Obvod: %f, Obsah: %f\n", triangle_perimeter, triangle_area);

  return 0;
}

int calc_rectangle(){
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

int calc_parallelogram(){
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

int calc_circle(){
  double d;
  printf("Prosim zadejte prumer(diameter) kruhu d:\n");
  if(scanf("%lf", &d) != 1 || d<=0){
    printf("prumer d ma byt >0\n");
    return 1;
  }

  double perimeter = PI*d;

  double area = (PI*d*d)/4.0;

  printf("Obvod: %f, Obsah: %f\n", perimeter, area);

  return 0;
}

int main(){
  calc_triangle();
  calc_rectangle();
  calc_parallelogram();
  calc_circle();
  return 0;
}