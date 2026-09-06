#include <stdio.h>

void swap_values_of_variables(double *val1, double *val2){
  double tmp = *val1;
  *val1 = *val2;
  *val2 = tmp;
}

int main(){
  double val1 = 2.001;
  double val2 = 3.333;
  swap_values_of_variables(&val1, &val2);
  printf("Promenna 1: %lf, promenna2: %lf\n", val1, val2);
  return 0;
}