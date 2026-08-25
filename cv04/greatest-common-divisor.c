#include <stdio.h>
#include <stdlib.h>

int naive(){
  int a,b;
  printf("Zadejte dva celych cisla a, b u kterych chcete dozvedet nejvetsi spolecny delitel\n");
  if(scanf("%d, %d", &a, &b) != 2 ){
    printf("Zadejte dva celych cisla a, b");
    return 1;
  };

  int gcd = 1;
  int minimum = a < b ? a : b;
  for(int i=minimum;i>=2;i--){
    if(a % i == 0 && b % i == 0){
      gcd = i;
      break;
    }
  }

  printf("Nejvetse spolecny delitel cisel %d a %d je: %d", a, b, gcd);
  return 0;
}

int euclidianSubtracting(){
  int a,b;
  printf("Zadejte dva celych cisla a, b u kterych chcete dozvedet nejvetsi spolecny delitel\n");
  if(scanf("%d, %d", &a, &b) != 2 ){
    printf("Zadejte dva celych cisla a, b");
    return 1;
  };

  int minimum = a < b ? a : b;
  int maximum = a > b ? a : b;
  while(minimum != maximum){
    if(maximum > minimum){
      maximum -= minimum;
    }else if(minimum > maximum){
      minimum -= maximum;
    }
  }
  int gcd = minimum;

  printf("Nejvetse spolecny delitel cisel %d a %d je: %d\n", a, b, gcd);
  return 0;
}

int euclidianRemainder(){
  int a,b;
  printf("Zadejte dva celych cisla a, b u kterych chcete dozvedet nejvetsi spolecny delitel\n");
  if(scanf("%d, %d", &a, &b) != 2 ){
    printf("Zadejte dva celych cisla a, b\n");
    return 1;
  };

  int minimum = a < b ? a : b;
  int maximum = a > b ? a : b;
  while(minimum != 0){
    int temp = maximum % minimum;
    maximum = minimum;
    minimum = temp;
  }
  int gcd = maximum;

  printf("Nejvetse spolecny delitel cisel %d a %d je: %d\n", a, b, gcd);
  return 0;
}

int main(){
  // naive();
  // euclidianSubtracting();
  euclidianRemainder();
  return 0;
}