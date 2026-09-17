#include <stdio.h>
#include <stdlib.h>

struct array_struct {
  int *data;
  size_t size;
  size_t capacity;
};

struct array_struct create_empty_array(){
  struct array_struct arr;
  arr.data = malloc(sizeof(int) * 4);
  if(arr.data == NULL){
    arr.capacity = 0;
    arr.size = 0;
    return arr;
  }
  arr.size = 0;
  arr.capacity = 4;
  return arr;
}

void append_to_array(struct array_struct *arr, int item){
  if(arr->size == arr->capacity){
    int *tmp = realloc(arr->data, sizeof(int) * arr->capacity * 2);
    if(tmp != NULL){
      arr->data = tmp;
    }
    arr->capacity *= 2;
  }
  arr->data[arr->size++] = item;
}

void print_array(struct array_struct *arr){
  for(size_t i=0;i<arr->size;i++){
    printf("%d ", arr->data[i]);
  }
  printf("\n");
}

void bubble_sort_array(struct array_struct *arr){
  if(arr->size<2){
    return;
  }
  int already_sorted = 1;
  for(size_t i=0;i<arr->size-1;i++){
    already_sorted = 1;
    for(size_t j=0;j<arr->size-1-i;j++){
      if(arr->data[j] > arr->data[j+1]){
        int tmp = arr->data[j];
        arr->data[j] = arr->data[j+1];
        arr->data[j+1] = tmp;
        already_sorted = 0;
      }
    }
    if(already_sorted == 1){
      break;
    }
  }
}

void remove_last_array_item(struct array_struct *arr){
  if(arr->size > 0){
    arr->size--;
  }
}

void free_up_array_memory(struct array_struct *arr){
  free(arr->data);
  arr->capacity = 0;
  arr->size = 0;
}

int main(void){
  struct array_struct arr;
  arr = create_empty_array();
  append_to_array(&arr, 100);
  print_array(&arr);
  bubble_sort_array(&arr);
  remove_last_array_item(&arr);
  free_up_array_memory(&arr);
  return 0;
}