#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* readNNumber(int *out_pocet){
  int n;
  printf("Uvedte prosim cislo N > 0: \n");
  if(scanf("%d", &n)!=1 || n < 1){
    printf("N ma byt cele, kladne cislo\n");
    return NULL;
  };

  int *pole = malloc(n * sizeof(int));
  if(!pole) return NULL;

  printf("Uvedte n celych cisel: \n");
  for(int i=0;i<n;i++){
    if(scanf("%d", &pole[i]) != 1){
      printf("Input ma byt celym cislem\n");
      free(pole);
      return NULL;
    }
  }

  int pocet = n;
  int soucet = 0;
  int minimum = pole[0];
  int maximum = pole[0];
  double prumer;
  
  int k = 3;
  
  for(int i=0; i<n;i++){
    if(pole[i] > k || pole[i] % k == 0){
      soucet+=pole[i];
      if(pole[i] < minimum){
        minimum = pole[i];
      }
      if(pole[i] > maximum){
        maximum = pole[i];
      }
    }
  }
  prumer = (double)soucet/n;

  printf("Pocet: %d, Soucet: %d, Minimum: %d, Maximum: %d, Prumer cisel: %f", pocet, soucet, minimum, maximum, prumer);
  *out_pocet = n;
  return pole;
}

int* readUntil0(int *out_pocet){
  int kapacita = 100;
  int pocet = 0;
  int *pole = malloc(sizeof(int) * kapacita);
  if(!pole) return NULL;

  int temp;
  printf("Zadavajte cela cisla, kdyz chcete ukoncit uvedte 0: \n");
  while(scanf("%d", &temp) == 1 && temp != 0){
    if(pocet == kapacita){
      kapacita*=2;
      int *tmp = realloc(pole, kapacita * sizeof(int));
      if (!tmp) {
        free(pole);
        return NULL;
      }
      pole = tmp;
    }
    pole[pocet++] = temp;
  }

  if(pocet == 1){
    return pole;
  }

  int is_increasing = 1;
  int is_decreasing = 1;
  int is_constant = 1;

  int is_arithmetic = 1;
  int d = pole[1] - pole[0];

  int is_geometric = 1;

  for(int i=0; i<pocet-2;i++){
    if(pole[i+1] <= pole[i]){
      is_increasing = 0;
    }
    if(pole[i+1] >= pole[i]){
      is_decreasing = 0;
    }
    if(pole[i+1] != pole[i]){
      is_constant = 0;
    }
    if((pole[i+1] - pole[i]) != d){
      is_arithmetic = 0;
    }
    if(((long long)pole[i]*pole[i+2])!=((long long)pole[i+1]*pole[i+1])){
      is_geometric = 0;
    }
  }

  printf("Posloupnost je - Rostouci: %d, Klesajici: %d, Konstantni: %d, Aritmeticka: %d, Geometricka: %d\n", is_increasing, is_decreasing, is_constant, is_arithmetic, is_geometric);
  *out_pocet = pocet;
  return pole;
}

int* readUntilEOF(int *out_pocet){
  int kapacita = 100;
  int *pole = malloc(sizeof(int) * kapacita);
  int pocet = 0;

  int temp;
  printf("Uvedte cela cisla do konce vstupu EOF(Ctrl + D)\n");
  while(scanf("%d", &temp) == 1){
    if(pocet == kapacita){
      kapacita*=2;
      int *tmp = realloc(pole, kapacita * sizeof(int));
      if (!tmp) {
        free(pole);
        return NULL;
      }
      pole = tmp;
    }
    pole[pocet++] = temp;
  }

  int* sortedPole = malloc(pocet * sizeof(int));

  for(int i=0; i<pocet;i++){
    sortedPole[i] = pole[i];
  }

  for(int i=0; i<pocet-1;i++){
    int swapped = 0;
    for(int j=0; j<pocet-1-i;j++){
      if(sortedPole[j] > sortedPole[j + 1]){
        int tmp = sortedPole[j];
        sortedPole[j] = sortedPole[j+1];
        sortedPole[j+1] = tmp;
        swapped = 1;
      }
    }
    if(swapped == 0){
      break;
    }
  }

  printf("Druhe nejmensi cislo: %d\n", sortedPole[1]);
  *out_pocet = pocet;
  return pole;
}

int main(){
  int out_pocet;
  int* arr = readUntilEOF(&out_pocet);
  for(int i=0; i<out_pocet;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}