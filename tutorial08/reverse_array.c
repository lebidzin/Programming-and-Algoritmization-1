#include <stdio.h>

void print_array(int *array, size_t size){
  for(size_t i=0;i<size;i++){
    printf("[%zu]: %d\n", i, array[i]);
  }
}

void reverse_array(int *arr, size_t size){
  if(!arr || size<=1){
    return;
  }

  int *l = arr;
  int *r = arr+size-1;
  while(l < r){
    int tmp = *l;
    *l = *r;
    *r = tmp;
    l++;
    r--;
  }
}

int main(){
  int array[] = {1,2,3,4};
  size_t arr_size = sizeof(array)/sizeof(array[0]);
  reverse_array(array, arr_size);
  print_array(array, arr_size);
  return 0;
}