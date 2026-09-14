#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int * create_and_allocate_array(size_t n){
  int *array = malloc(n * sizeof(int));
  return array;
}

void set_array_values_predefined(int *arr, size_t n, int val){
  if(arr == NULL){
    return;
  }
  for(size_t i=0;i<n;i++){
    arr[i] = val;
  }
}

void set_array_values_a_b(int *arr, size_t n, int a, int b){
  if(arr == NULL){
    return;
  }
  if(a>b){
    int tmp = a;
    a = b;
    b = tmp;
  }
  for(size_t i=0;i<n;i++){
    arr[i] = a + rand() % (b - a + 1);
  }
}

void print_array(const int *arr, size_t n){
  if(arr == NULL){
    return;
  }
  for(size_t i=0;i<n;i++){
    printf("%d; ",arr[i]);
  }
  printf("\n");
}

void free_up_array_memory(int *arr){
  if(arr == NULL){
    return;
  }
  free(arr);
}

int main(void){
  srand(time(NULL));
  size_t n = 10;
  int *arr = create_and_allocate_array(n);

  int a = 10;
  int b = 100;
  set_array_values_a_b(arr, n, a, b);

  print_array(arr, n);
  free_up_array_memory(arr);

  return 0;
}