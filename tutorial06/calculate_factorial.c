#include <stdio.h>

// Iterativni vypocet faktorialu
int main(){
  int a;
  printf("Zadejte cislo pro vypocet faktorialu:\n");
  if(scanf("%d", &a)!=1){
    printf("Neplatny vstup\n");
    return 1;
  }

  int result;
  for(int i=a;i>0;i--){
    result*=i;
  }

  printf("Faktorial cisla %d je: %d\n", a, result);

  return 0;
}