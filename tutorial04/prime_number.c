#include <stdio.h>

int main(){
  int cislo;
  printf("Zadejte cislo, a dozvedte zda je prvocislo a jeho celociselne delitele\n");
  if(scanf("%d", &cislo)!=1){
    printf("Zadejte platne cele cislo\n");
    return 1;
  };

  int isPrime = (cislo > 1);
  printf("Kladni delitele:\n");
  for(int i=2; i<cislo;i++){
    if(cislo % i == 0){
      printf("%d\n", i);
      isPrime = 0;
    }
  }

  if(isPrime == 1){
    printf("Cislo %d je prvocislem\n", cislo);
  }else{
    printf("Cislo %d neni prvocislem\n", cislo);
  }

  return 0;
}