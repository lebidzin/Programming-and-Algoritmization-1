#include <stdio.h>

int main(){
  // int a = 7/0; // nedefinované chování
  // double b = 5/3;  // 1.000000000
  // double c = 7/0; // Undefined behaviour
  // printf("a: %d b: %f c: %f", a, b, c);

  // int a = 1.56E30; // 1.56 * 10^30 = 15600000000000... => bude integer overflow => Nedefinovane chovani
  // double b = 1.2E4 + 15; // 1.20 * 10^4 + 15 = 12015.0000000
  // double c = 5.2E3 * 5E-1; // 5.2*10^3 * 5*10^-1 = 5200 * 1/2 = 2600.0000000
  double a = 25.f; // 25.000000
  int b = 5.7;  // vysledek 5
  int c = 2; c += 5.7; // vysledek 7
  int d = 2; d *= 5.7; // vysledek 11

  printf("a: %f b: %d c: %d d: %d", a, b, c, d);
  return 0;
}