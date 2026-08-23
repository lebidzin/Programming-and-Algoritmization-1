#include <stdio.h>

void classifyNumbers(){
  int a,b,c;
  printf("Zadejte tri cisla a, b, c: ");
  if (scanf("%d %d %d", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
    printf("Chyba: Neplatny vstup. Zadejte tri cela cisla.\n");
    return;
  }
  int max = a;
  if (b > max) max = b;
  if (c > max) max = c;
  int min = a;
  if (b < min) min = b;
  if (c < min) min = c;
  int prostredni;
  if(a!=min && a!=max){
    prostredni=a;
  }
  if(b!=min && b!=max){
    prostredni=b;
  }
  if(c!=min && c!=max){
    prostredni=c;
  }
  printf("Maximum: %d, Minimum: %d, Prostredni: %d\n", max, min, prostredni);
}

int main(){
  classifyNumbers();
  return 0;
}