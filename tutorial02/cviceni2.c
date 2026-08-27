#include <stdio.h>
#include <math.h>
// Teoreticke ulohy

void calcOverflow(){
  int a = 1234567890;
  int b = 2000000000;
  long long sum = (long long)a+b;
  printf("%lld\n", sum);
}

void calcArithmetic(){
  int a = 5 + 3 * 4;
  int b = 5 / 3;
  int c = 7 / 0;
  printf("%d %d %d\n", a, b, c);
}

void calcArithmetic2(){
  int b2 = 7;
  int c2 = 7;

  int a = 7;
  int b1 = ( b2 = 7 ); // vzdy bude b1=7
  int c1 = ( c2 == 7 ); // diskutujte možnosti pro c2 rovno 7, 5, 0. | bude 1, 0, 0
  int d = 5; d += 4;   // d = 9
  int e = 4; e *= 1 - 2;  // -4
  int f = 15 - 6 / 2 * 3;  // 6

  printf("%d\n%d\n%d\n%d\n%d\n%d\n", a, b1, c1, d, e, f);
}

void calcArithmetic3(){
  int a = -100000000;  // spravne zapsany, vysledek bude totiz cislo
  unsigned int b = -20;   // vysledek 2^32-20
  int long unsigned c = 28L;  // nevim co znamena L na konci, vysledek 28??
  int d = 2; d += d + d * ++d; // <nedefinovaná hodnota> ++d modifikace a soucasne cteni
  int e = 2; e += e;  // 4

  printf("%d\n%u\n%lu\n%d\n%d\n", a, b, c, d, e);
}

void helloProgrammer(){
  printf("Ahoj, programatore");
}

void vykresliSmajlika(){
  printf("o o\n");
  printf(" ? \n");
  printf("\\__/\n");
  printf(" U \n");
}
long long calculateFactorial(int n){
  if(n <= 1){
    return 1;
  }
  return n * calculateFactorial(n-1);
}

void calculateRectangle(){
  int a;
  int b;
  printf("Napiste vetsi stranu:\n");
  scanf("%d", &a);
  printf("Napiste mensi stranu:\n");
  scanf("%d", &b);
  int obvod = a*2+b*2;
  int obsah = a*b;
  printf("Povrch: %d\n. Objem %d\n", obvod, obsah);
}

void pocitejKvadr(){
  int a;
  int b;
  int c;
  printf("Zadejte strany kvadru a, b, c: ");
  if (scanf("%d %d %d", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
    printf("Chyba: Neplatny vstup. Zadejte tri kladna cela cisla.\n");
    return;
  }

  int povrch = 2*(a*b+b*c+a*c);
  long long objem = (long long)a*b*c;

  printf("Povrch: %d\nObjem: %lld\n", povrch, objem);
}

void posloupnost(){
  int n;
  printf("Zadejte jaky clen posloupnosti chcete(n)?\n");
  if((scanf("%d", &n ) != 1) || n < 1){
    printf("Chyba, clen posloupnosti neexistuje\n");
    return;
  }

  int a1 = n;
  int a2 = 2*n-1;
  int a3 = 4 * n - 3; 
  int a4 = 1;
  for(int i=0;i<n;i++){
    a4+=i;
  }
  long long a5 = pow(2, n-1);

  printf("Prvni posloupnost: %d\n", a1);
  printf("Druha posloupnost: %d\n", a2);
  printf("Treti posloupnost: %d\n", a3);
  printf("Ctvrti posloupnost: %d\n", a4);
  if (n <= 62) {
        printf("5. posloupnost: %lld\n", a5);
    } else {
        printf("5. posloupnost: Preteceni 64bitoveho typu\n");
    }
}

void vyhodnotiTrojuhelnik(){
  int a;
  int b;
  int c;
  printf("Zadejte strany trojuhelniku a, b, c: ");
  if (scanf("%d %d %d", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
    printf("Chyba: Neplatny vstup. Zadejte tri kladna cela cisla.\n");
    return;
  }

  printf("Trojuhelnik se strany a: %d, b: %d, c: %d\n", a, b, c);
  if ((a*a + b*b == c*c) ||
    (a*a + c*c == b*b) ||
    (b*b + c*c == a*a)) {
    printf("Pravouhly\n");
}else{
    printf("Nepravouhly\n");
  }
}

int main(){
  // printf("%lld\n",calculateFactorial(12));
  vyhodnotiTrojuhelnik();
  return 0;
}