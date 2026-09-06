#include <stdio.h>
#include <stdbool.h>

struct Zlomek{
  int numerator;
  int denominator;
};


bool read_fraction(struct Zlomek *zlomek){
  if(zlomek == NULL){
    return false;
  }
  printf("Zadejte numerator\n");
  int scanf_res_1 = scanf("%d", &zlomek->numerator);
  printf("Zadejte denominator\n");
  int scanf_res_2 = scanf("%d", &zlomek->denominator);
  return (scanf_res_1 == 1 && scanf_res_2 == 1 && zlomek->denominator != 0);
}

int main(){
  struct Zlomek zlomek = {0, 1};
  bool read_fraction_res = read_fraction(&zlomek);
  if(read_fraction_res){
    printf("Nacteni zlomku se podarilo: %d/%d\n", zlomek.numerator, zlomek.denominator);
  }else{
    printf("Nacteni zlomku se nepodarilo\n");
  }
  return 0;
}