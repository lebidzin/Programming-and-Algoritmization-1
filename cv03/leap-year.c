#include <stdio.h>

int main(){
  int year;
  printf("Napiste rok, program vyhodnoti zda je prestupny: \n");
  if(scanf("%d", &year) != 1){
    printf("Napiste validni rok\n");
    return 1;
  }

  int is_leap = (year >= 1584) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

  if (is_leap) {
    printf("Rok %d je prestupny\n", year);
  } else {
    printf("Rok %d neni prestupny\n", year);
  }

  return 0;
}