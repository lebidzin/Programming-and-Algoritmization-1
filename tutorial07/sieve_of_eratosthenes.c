#include <stdio.h>
#include <stdbool.h>

// Sieve of Eratosthenes
void sieve_of_eratosthenes(int N){
  if(N<2){
    return;
  }
  bool array[N];
  for(int i=0;i<N;i++){
    array[i]=true;
  }
  array[0]=false;
  array[1]=false;

  for(int p=2;p*p<=N;p++){
    if(array[p]){
      for(int k=p*p;k<N;k+=p){
        array[k] = false;
      }
    }
  }

  for(int i=2;i<N;i++){
    if(array[i] == true){
      printf("Prvocislo = %d\n", i);
    }
  }
}

int main(){
  sieve_of_eratosthenes(200);
  return 0;
}