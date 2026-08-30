#include <stdio.h>
#include <math.h>

// E=10^-9
#define E 1e-9

// Funkce, která zjistí, zda dvě přímky se protínají, jsou identické nebo jsou rovnoběžné.
int test_two_lines(double a1, double b1, double c1,double a2, double b2, double c2){
  double D = a1*b2-a2*b1;
  double D1 = a1*c2-a2*c1;
  double D2 = b1*c2-b2*c1;

  if((fabs(a1)<E && fabs(b1)<E) || (fabs(a2)<E && fabs(b2)<E)){
    printf("Neplatna rovnice primky v rovine\n");
    return 1;
  }

  if(fabs(D)>E){
    printf("Různoběžné přímky (D!=0), přímky se protínají v právě jednom bodě\n");
  }else{
    if(fabs(D1)<E && fabs(D2)<E){
      printf("Přímky jsou identické (totožné)(D=0)\n");
    }else{
      printf("Přímky jsou rovnoběžné různé(D=0)\n");
    }
  }
  return 0;
}

int main(){
  double a1,b1,c1;
  printf("Zadejte KOEFICIENTY PRVNI rovnice ax+by+c=0 - a b c:\n");
  if(scanf("%lf %lf %lf", &a1,&b1,&c1)!=3){
    printf("Neplatny vstup\n");
    return 1;
  }
  double a2,b2,c2;
  printf("Zadejte KOEFICIENTY DRUHE rovnice ax+by+c=0 - a b c:\n");
  if(scanf("%lf %lf %lf", &a2,&b2,&c2)!=3){
    printf("Neplatny vstup\n");
    return 1;
  }
  test_two_lines(a1,b1,c1,a2,b2,c2);
  return 0;
}