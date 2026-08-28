#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// E=10^-9
#define E 0.000000001

int read_coefficient(double *coefficient, char **ptr, const char *separator){
  char *endptr;
  int separator_len = strlen(separator);
  *coefficient = strtod(*ptr, &endptr);
  if(*ptr != endptr){
    *ptr = endptr;
  }else{
    return 1;
  }
  while (isspace((unsigned char)**ptr)) { (*ptr)++; }
  if(strncmp(*ptr, separator, separator_len) == 0){
    (*ptr)+=separator_len;
  }else{
    return 1;
  }
  while (isspace((unsigned char)**ptr)) { (*ptr)++; }
  if (**ptr == '+') { (*ptr)++; }
  return 0;
}

// Kvadraticka kalkulacka
int main(void){
  double a,b,c,d,e,f;
  printf("Zadejte kvadratickou rovnici ve tvaru a x^2 + b x + c = d x^2 + e x + f\n");

  char buffer[256];
  char *ptr=buffer;

  if(fgets(buffer, sizeof(buffer), stdin) == NULL){
    printf("Nespravny vstup.\n");
    return 1;
  }
  if(read_coefficient(&a, &ptr, "x^2") != 0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  if(read_coefficient(&b, &ptr, "x") != 0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  if(read_coefficient(&c, &ptr, "=")!=0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  if(read_coefficient(&d, &ptr, "x^2")!=0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  if(read_coefficient(&e, &ptr, "x")!=0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  if(read_coefficient(&f, &ptr, "")!=0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  if(*ptr != '\0'){
    printf("Nespravny vstup.\n");
    return 1;
  }

  double x1,x2;
  a = a-d;
  b = b-e;
  c = c-f;
  if(fabs(a)<E){
    if(fabs(b) < E){
      if(fabs(c) < E){
        printf("Nekonecne mnoho reseni, x in R\n");
        return 0;
      }else{
        printf("b=0, c!=0 => zadne reseni\n");
        return 0;
      }
    }else{
      x1 = -c/b;
      printf("x=%f\n", x1);
      return 0;
    }
  }
  // Diskriminant:
  double D = b*b - 4*a*c;
  // D==0: Jeden dvojnásobný reálný kořen:
  if(fabs(D)<E){
    x1 = -b/(2*a);
    printf("x=%f\n", x1);
  // D>0: Dva reálné různé kořeny
  }else if(D>0){
    x1 = (-b+sqrt(D))/(2*a);
    x2 = (-b-sqrt(D))/(2*a);
    if(x1 < x2){
      printf("x1=%f; x2=%f\n", x1, x2);
    }else{
      printf("x1=%f; x2=%f\n", x2, x1);
    }
  // D<0: Rovnice nemá řešení v oboru reálných čísel (kořeny jsou komplexní):
  }else{
    printf("Neexistuje reseni v R\n");
    // Realny cast:
    double Re = -b/(2*a);
    // Imaginarni cast:
    double Im = sqrt(fabs(D))/fabs(2*a);
    printf("x1=%f+%fi; x2=%f-%fi\n", Re, Im, Re, Im);
  }

  return 0;
}