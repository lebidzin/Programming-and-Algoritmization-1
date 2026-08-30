#include <stdio.h>

// funkce, která zjistí, zda předaný trojúhelník je:
// pravoúhlý,
// rovnostranný,
// rovnoramenný.
int main(){
  long long a,b,c;
  printf("Zadejte strany trojuhelniku a b c:\n");
  if(scanf("%lld %lld %lld", &a, &b, &c)!=3 || a<=0 || b<=0 || c<=0){
    printf("Nespravny vstup\n");
    return 1;
  }

  if(!(a+b>c) || !(a+c>b) || !(b+c>a)){
    printf("Trojuhelnik se stranami %lld %lld %lld NEmuze existovat\n", a,b,c);
    return 1;
  }

  if(a == b && b == c){
    printf("Trojuhelnik se stranami %lld %lld %lld je ROVNOSTRANNY\n", a,b,c);
  }else if(a==b || b==c || a==c){
    printf("Trojuhelnik se stranami %lld %lld %lld je ROVNORAMENNY\n", a,b,c);
  }else if((a*a+b*b == c*c) || (b*b+c*c==a*a) || a*a+c*c==b*b){
    printf("Trojuhelnik se stranami %lld %lld %lld je PRAVOUHLY\n", a,b,c);
  }else{
    printf("Trojúhelník se stranami %lld %lld %lld je OBECNY (různoběžný a ne-pravoúhlý)\n", a,b,c);
  }

  return 0;
}