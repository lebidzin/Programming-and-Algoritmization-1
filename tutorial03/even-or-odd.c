#include <stdio.h>

int main(){
  int number;
  printf("Napiste cislo: \n");
  scanf("%d", &number);
  if(number % 2 == 0){
    printf("Cislo %d je Sude\n", number);
  }else{
    printf("Cislo %d je Liche\n", number);
  }
  if(number >= 0){
    printf("Cislo %d je Kladne\n", number);
  }else{
    printf("Cislo %d je Zaporne\n", number);
  }
  return 0;
}