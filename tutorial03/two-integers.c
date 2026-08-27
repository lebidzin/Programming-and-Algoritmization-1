#include <stdio.h>

int main(){
  int a, b;
  printf("Napiste dva cela cisla: \n");
  if(scanf("%d %d", &a, &b) != 2){
    printf("Nevalidni vstup, napiste dva cela cisla\n");
    return 1;
  }

  if(a<=b){
    printf("Serazene cisla (vzestupne): %d, %d\n", a, b);
  }else{
    printf("Serazene cisla: %d, %d\n", b, a);
  }

  double prumer = (a+b)/2.0;
  printf("Prumer a i b je: %.2f\n", prumer);

  int temp;
  temp = a;
  a = b;
  b = temp;
  printf("Prochozeni obsah promennych a i b: %d %d\n", a, b);

  return 0;
}