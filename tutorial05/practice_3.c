#include <stdio.h>
#include <math.h>

// E=10^-9
#define E 0.000000001

int main(){
  //Program vypise zda se kružnice protínají, jedna je částí druhé, dotýkají se (vnitřní a vnější dotyk), jsou ekvivalentní nebo se neprotínají. 
  double x1,y1,r1;
  printf("Zadejte souradnice 'x', 'y' a polomer 'r' prvni kruznice:(format: x y r)\n");
  if(scanf("%lf %lf %lf", &x1, &y1, &r1)!=3 || r1<=0){
    printf("Zadejte platne souradnice a polomer(>0)\n");
    return 1;
  }

  double x2,y2,r2;
  printf("Zadejte souradnice 'x', 'y' a polomer 'r' druhe kruznice:(format: x y r)\n");
  if(scanf("%lf %lf %lf", &x2, &y2, &r2)!=3 || r2<=0){
    printf("Zadejte platne souradnice a polomer(>0)\n");
    return 1;
  }

  double d = hypot(x2-x1,y2-y1);

  if(d<E && fabs(r1-r2)<E){
    printf("Ekvivalentní (totožné kružnice)[x1,y1]: [%f,%f]; r1: %f; [x2;y2]: [%f,%f]; r2: %f\n", x1, y1, r1, x2, y2, r2);
  }else if(d+E<fabs(r1-r2)){
    printf("Jedna kružnice leží uvnitř druhé (bez dotyku): [x1,y1]: [%f,%f]; r1: %f; [x2;y2]: [%f,%f]; r2: %f\n", x1, y1, r1, x2, y2, r2);
  }else if(fabs(d-fabs(r1-r2))<E){
    printf("Vnitřní dotyk kruznice: [x1,y1]: [%f,%f]; r1: %f; [x2;y2]: [%f,%f]; r2: %f\n", x1, y1, r1, x2, y2, r2);
  }else if(fabs(r1-r2)<d && d<fabs(r1+r2)){
    printf("Kruznice se protínají: [x1,y1]: [%f,%f]; r1: %f; [x2;y2]: [%f,%f]; r2: %f\n", x1, y1, r1, x2, y2, r2);
  }else if(fabs(d-fabs(r1+r2))<E){
    printf("Kruznice vnější dotyk: [x1,y1]: [%f,%f]; r1: %f; [x2;y2]: [%f,%f]; r2: %f\n", x1, y1, r1, x2, y2, r2);
  }else if(d > r1+r2){
    printf("Kruznice míjejí se vně (neprotínají se):: [x1,y1]: [%f,%f]; r1: %f; [x2;y2]: [%f,%f]; r2: %f\n", x1, y1, r1, x2, y2, r2);
  }

  return 0;
}