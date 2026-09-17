#include <stdio.h>
#include <stdlib.h>

void populate_pascals_triangle(int ***matrix, int n){
  int rows = n;

  *matrix = (int **)malloc(rows * sizeof(int *));
  if (*matrix == NULL) {
    return;
  }

  // Alokace samotných sloupců pro každý řádek
  for (int i = 0; i < rows; i++) {
    (*matrix)[i] = (int *)malloc((i+1) * sizeof(int));
    if ((*matrix)[i] == NULL) {
      return;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(j==0 || j==i){
        (*matrix)[i][j]=1;
      }else{
        (*matrix)[i][j]=(*matrix)[i-1][j-1] + (*matrix)[i-1][j];
      }
    }
  }
}

void free_triangle_memory(int **matrix, int rows){
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(*matrix);
}

void print_pascals_triangle(int **matrix, int rows){
  printf("Moje dynamická matice:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%2d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(void){
  int **matrix;
  int n = 10;
  populate_pascals_triangle(&matrix, n);
  print_pascals_triangle(matrix, n);
  return 0;
}