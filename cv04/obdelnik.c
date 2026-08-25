#include <stdio.h>

int printObdelnik(){
  int a,b;
  printf("Zadejte vysku(a) >1 a sirku(b) >1 obdelniku a b:\n");
  if(scanf("%d %d", &a, &b) != 2 || a <= 1 || b <= 1){
    printf("Vyska a sirka maji byt cela cisla >1\n");
    return 1;
  }

  for(int i=1;i<=a*b;i++){
    printf("*");
    if(i % b == 0 && i!=1){
      printf("\n");
    }
  }

  return 0;
}

int main(){
  printObdelnik();
  return 0;
}