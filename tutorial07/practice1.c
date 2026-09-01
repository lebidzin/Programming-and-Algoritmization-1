#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *array, size_t size){
  for(size_t i=0;i<size;i++){
    printf("[%zu]: %d\n", i, array[i]);
  }
}

int* shuffle_array_values(int *array, size_t size){
  for(int i=size-1;i>=1;i--){
    int j = rand() % (i+1);
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }
  return array;
}

int* shuffle_array_even_odd(int *array, size_t size){
  if(size == 0){
    return array;
  }
  size_t l = 0;
  size_t r = size-1;
  while(l<r){
    if(array[l] % 2 == 0){
      l++;
    }else if(array[r] % 2 != 0){
      r--;
    }else{
      int tmp = array[l];
      array[l] = array[r];
      array[r] = tmp;
      l++;
      r--;
    }
  }
  return array;
}

int* shuffle_array_even_odd_smaller(int *array, size_t size){
  for(size_t i=0;i<size;i+=2){
    if(i+1<size){
      if(array[i] > array[i+1]){
        int tmp = array[i];
        array[i] = array[i+1];
        array[i+1] = tmp;
      }
    }
  }
  return array;
}

int* bubble_sort_array(int *array, size_t size){
  if(size<2){
    return array;
  }
  int already_sorted = 1;
  for(size_t i=0;i<size-1;i++){
    already_sorted = 1;
    for(size_t j=0;j<size-1-i;j++){
      if(array[j] > array[j+1]){
        int tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
        already_sorted = 0;
      }
    }
    if(already_sorted == 1){
      break;
    }
  }
  return array;
}

int main(){
  srand(time(0));
  int array[] = {3, 2, 4, 5, 1, 0, -1};
  size_t array_size = 7;
  // shuffle_array_values(array, array_size);
  // shuffle_array_even_odd(array, array_size);
  // shuffle_array_even_odd_smaller(array, array_size);
  bubble_sort_array(array, array_size);
  print_array(array, array_size);
  return 0;
}