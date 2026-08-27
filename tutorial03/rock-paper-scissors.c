#include <stdio.h>
#include <ctype.h>

int je_platna_volba(char c) {
  return c == 'K' || c == 'N' || c == 'P' ||
         c == 'k' || c == 'n' || c == 'p';
}

int main(){
  char a,b;
  printf("***Hra Kamen, Nuzky, Papir***\n");
  printf("Prvni hrac, zadejte pismeno(odpovidajici jednotlivym volbam): \n");
  printf("K, N, P\n");
  if(scanf(" %c", &a) != 1 || !je_platna_volba(a)){
    printf("Neplatna volba 1 hrace\n");
    return 1;
  };
  printf("Druhy hrac, zadejte pismeno(odpovidajici jednotlivym volbam): \n");
  printf("K, N, P\n");
  if(scanf(" %c", &b) != 1 || !je_platna_volba(b)){
    printf("Neplatna volba 2 hrace\n");
    return 1;
  };

  a = toupper(a);
  b = toupper(b);

  if(a == b){
    printf("Remiza\n");
    return 0;
  }

  if((a == 'K' && b == 'N') || 
  (a == 'N' && b == 'P') || 
  (a == 'P' && b == 'K')){
    printf("Prvni hrac vyhral\n");
  }else{
    printf("Druhy hrac vyhral\n");
  }

  return 0;
}