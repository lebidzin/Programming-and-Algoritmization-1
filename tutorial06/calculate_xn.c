#include <stdio.h>

int calc_xn_trivialy(){
  int x,n;
  printf("Zadejte cela cisla x a n:\n");
  if(scanf("%d %d", &x, &n)!= 2){
    printf("Neplatny vstup\n");
    return 1;
  }

  int result = 1;
  for(int i=1;i<=n;i++){
    result *= x;
  }

  printf("x^n = %d\n", result);
  
  return 0;
}

int calc_xn_square_multiply(){
  int x,n;
  printf("Zadejte cela cisla x a n:\n");
  if(scanf("%d %d", &x, &n)!= 2){
    printf("Neplatny vstup\n");
    return 1;
  }

  int result = 1;
  int base = x;
  int exp = n;

  while(exp>0){
    if(exp % 2 != 0){
      result *= base;
    }
    if(exp > 1){
      base *= base;
    }
    exp /= 2;
  }

  printf("x^n = %d\n", result);
  return 0;
}

int main(){
  calc_xn_trivialy();
  calc_xn_square_multiply();
}