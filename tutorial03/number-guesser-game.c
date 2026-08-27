#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	/* Inicializuje generator nahodnych cisel. */
	srand( time( nullptr ) );

	/* Generuje nahodne cislo od 0 do 99. */
	int x = rand() % 100;

  int a,b;
  printf("***Hra Uhodni Nahodne Cislo od 0 do 99***\n");
  printf("Prvni hrac, zadejte cislo: \n");
  if(scanf(" %d", &a) != 1 || a < 0 || a > 99){
    printf("Neplatna volba 1 hrace\n");
    return 1;
  };
  printf("Druhy hrac, cislo: \n");
  if(scanf(" %d", &b) != 1 || b < 0 || b > 99){
    printf("Neplatna volba 2 hrace\n");
    return 1;
  };

  printf("Vygenerovane cislo bylo: %d\n", x);

  int dist_a = abs(x - a);
  int dist_b = abs(x - b);

  if (dist_a == dist_b) {
    printf("Remiza! Oba byli stejne blizko (rozdil %d).\n", dist_a);
  } else if (dist_a < dist_b) {
    printf("Prvni hrac vyhral! (rozdil %d vs %d)\n", dist_a, dist_b);
  } else {
    printf("Druhy hrac vyhral! (rozdil %d vs %d)\n", dist_b, dist_a);
  }

  return 0;
}