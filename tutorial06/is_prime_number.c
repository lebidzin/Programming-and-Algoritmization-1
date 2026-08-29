#include <stdio.h>

// Zda cislo je prvocislo
int is_prime_number(int parameter){
  int a;
  if(!parameter){
    printf("Zadejte cislo ktere chete dozvedet zda je prvocislo:\n");
    if(scanf("%d", &a)!=1){
      printf("Neplatny vstup\n");
      return 1;
    }
  }
  a = parameter ? parameter : a;

  int isPrime = (a > 1);
  // printf("Kladni delitele:\n");
  for(int i=2;i*i<=a;i++){
    if(a % i == 0){
      // printf("%d\n", i);
      isPrime = 0;
      break;
    }
  }

  if(isPrime == 1){
    printf("Cislo %d je prvocislem\n", a);
  }else{
    printf("Cislo %d neni prvocislem\n", a);
  }

  return 0;
}

int print_primes_smaller_than(int parameter){
  for(int i=1;i<parameter;i++){
    is_prime_number(i);
  }
  return 0;
}

int main(){
  print_primes_smaller_than(100);
  return 0;
}