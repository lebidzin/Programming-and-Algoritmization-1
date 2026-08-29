#include <stdio.h>
#include <stdlib.h>

// funkce se dvěma parametry, která najde …​ těchto čísel
// největší společný dělitel
// nejmenší společný násobek

// Slozitost - O(n):
// int find_gcd(int a, int b){
//   int minimum = a < b ? a : b;
//   int maximum = a > b ? a : b;

//   int result;
//   for(int i=minimum;i>=1;i--){
//     if((minimum % i == 0) && (maximum % i == 0)){
//       result = i;
//       break;
//     }
//   }

//   return result;
// }

// Slozitost O(log(min(a,b))):
int find_gcd(int a, int b){
  a = abs(a);
  b = abs(b);
  while(b!=0){
    int tmp = a%b;
    a = b;
    b = tmp;
  }

  return a;
}

int find_lcm(int a, int b){
  a = abs(a);
  b = abs(b);
  if(a == 0 || b == 0){
    return 0;
  }
  int gcd = find_gcd(a, b);
  int result = a/gcd*b;
  return result;
}

int main(){
  int gcd = find_gcd(100, 50);
  int lcm = find_lcm(10, 5);

  printf("gcd: %d\n", gcd);
  printf("lcm: %d\n", lcm);
  return 0;
}