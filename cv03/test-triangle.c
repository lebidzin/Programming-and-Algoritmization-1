#include <stdio.h>

int main(){
  int a, b, c;

  printf("Napiste 3 cela cisla a, b, c, reprezentujici strany trojuhelnika\n");
  if(scanf("%d %d %d", &a, &b, &c) != 3 || a<1 || b<1 || c<1){
    printf("Cisla maji byt cela a kladna\n");
    return 1;
  }

  if(a+b>c && b+c>a && c+a>b){
    printf("Trojuhelnik se strany %d, %d, %d lze sestrojit\n", a,b,c);
  }else{
    printf("Trojuhelnik se strany %d, %d, %d nelze sestrojit\n", a,b,c);
    return 1;
  }

  if(a==b && b==c){
    printf("Trojuhelnik se strany %d, %d, %d je rovnostranny\n", a,b,c);
  }else{
    printf("Trojuhelnik se strany %d, %d, %d neni rovnostranny\n", a,b,c);
  }

  if(a==b || a==c || b==c){
    printf("Trojuhelnik se strany %d, %d, %d je rovnoramenny\n", a,b,c);
  }else{
    printf("Trojuhelnik se strany %d, %d, %d neni rovnoramenny\n", a,b,c);
  }

  if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
    printf("Trojuhelnik se strany %d, %d, %d je pravouhly\n", a,b,c);
  }else{
    printf("Trojuhelnik se strany %d, %d, %d neni pravouhly\n", a,b,c);
  }

  return 0;
}