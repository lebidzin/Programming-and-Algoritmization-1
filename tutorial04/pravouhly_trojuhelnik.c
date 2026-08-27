#include <stdio.h>

int printPravouhlyTrojuhelnik(){
  int a;
  printf("Zadejte vysku(a) >1 praovhleho trojuhelniku a:\n");
  if(scanf("%d", &a) != 1 || a <= 1){
    printf("Vyska ma byt cele cislo >1\n");
    return 1;
  }

  for(int i=1;i<=a;i++){
    for(int j=1;j<=i;j++){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

int main(){
  printPravouhlyTrojuhelnik();
  return 0;
}