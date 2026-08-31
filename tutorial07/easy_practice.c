#include <stdio.h>
#include <stdlib.h>

int* fill_array(int n, int a){
  int *array = malloc(sizeof(int)*n);
  for(int i=0;i<=n-1;i++){
    array[i]=a+i;
  }
  return array;
}

int* fill_array_random_values(int n){
  int *array = malloc(sizeof(int)*n);
  for(int i=0;i<=n-1;i++){
    int value = rand();
    array[i]=value;
  }
  return array;
}

void print_array(int *array, size_t size){
  for(size_t i=0;i<size;i++){
    printf("[%zu]: %d\n", i, array[i]);
  }
}

int check_is_array_reverse(int *array1, size_t size1, int *array2, size_t size2){
  if(size1 != size2){
    return 0;
  }
  for(size_t i=0;i<size1;i++){
    if(array1[i] != array2[size1-1-i]){
      return 0;
    }
  }
  return 1;
}

int main(){
  size_t array1_size = 10;
  int *array1 = fill_array(array1_size, 5);
  size_t array2_size = 10;
  int *array2 = fill_array_random_values(array2_size);
  print_array(array2, array2_size);
  free(array1);
  free(array2);

  int is_reverse = check_is_array_reverse(array1, array1_size, array2, array2_size);
  printf("Je reverznim obrazem: %d", is_reverse);

  return 0;
}