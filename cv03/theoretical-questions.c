#include <stdio.h>
#include <limits.h>

int main(){
  // printf("%d\n",x == -x);   // bude splneno pro x=0, x=INT_MIN
  // printf("%d\n",(-10 < x) < 10);   // bude splneno pro vsechny x, protoze 10 > 1,0
  // printf("%d\n",(-1 < x) < 1);   // bude splneno pro x <= -1, protoze 1>0, ale 1=1
  // int x;
  // int a = 1;
  // int b = 2; 
  // x = a + b;  // x=3
  // printf("x: %d\n", x);

  int x;
  int a = 1; 
  int b = a += 2; 
  x = a / b;  // x=1
  printf("x: %d\n", x);

  return 0;
}