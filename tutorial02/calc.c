#include <stdio.h>

int main(){
  int a;
  int b;
  scanf("%d %d", &a, &b);

  int sum = a+b;
  int difference = a-b;
  int multiplication = a*b;
  int division = a/b;
  int remainder = a%b;

  printf("%d + %d = %d\n", a, b, sum);
  printf("%d - %d = %d\n", a, b, difference);
  printf("%d * %d = %d\n", a, b, multiplication);
  printf("%d / %d = %d\n", a, b, division);
  printf("%d %% %d = %d\n", a, b, remainder);
}