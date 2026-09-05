#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
  int int_a = *(const int *)a;
  int int_b = *(const int *)b;
  return int_a - int_b;
}

int is_rotation(const int *arr1, size_t size1, const int *arr2, size_t size2) {
  if (size1 != size2) {
    return 0;
  }
  if(size1 == 0 && size2 == 0){
    return 1;
  }
  for(size_t k=0;k<=size1-1;k++){
    size_t i;
    for(i=0;i<size2;i++){
      if(arr1[(i+k)%size1]!=arr2[i]){
        break;
      }
    }
    if(i==size2){
      return 1;
    }
    k++;
  }
  return 0;
}

bool are_same_values(int *arr1, size_t size1, int *arr2, size_t size2){
  qsort(arr1, size1, sizeof(int), compare); 
  qsort(arr2, size2, sizeof(int), compare); 
  size_t i = 0;
  size_t k = 0;
  int val;
  while(i<size1 && k<size2){
    if(arr1[i] != arr2[k]){
      return false;
    }
    val = arr1[i];
    while(i<size1 && arr1[i] == val){
      i++;
    }
    while(k<size2 && arr2[k] == val){
      k++;
    }
  }
  return (i == size1 && k == size2);
}

bool is_anagram(int *arr1, size_t size1, int *arr2, size_t size2){
  if(size1 != size2){
    return false;
  }
  qsort(arr1, size1, sizeof(int), compare); 
  qsort(arr2, size2, sizeof(int), compare); 
  for(size_t i = 0;i<size1;i++){
    if(arr1[i]!=arr2[i]){
      return false;
    }
  }
  return true;
}

int main(void) {
  int arr1[] = {1, 2, 3, 4};
  size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
  int arr2[] = {3,4,1,2};
  size_t size2 = sizeof(arr2)/sizeof(arr2[0]);
  int is_rot = is_rotation(arr1, size1, arr2, size2);
  printf("Jsou pole rotace? A-ano, N-ne: %c\n", is_rot==1?'A':'N');

  int arr3[] = {1,2,3,1,4};
  size_t size3 = sizeof(arr3)/sizeof(arr3[0]);
  int arr4[] = {3,1,2,3,4,4};
  size_t size4 = sizeof(arr4)/sizeof(arr4[0]);
  int are_same_vals = are_same_values(arr3, size3, arr4, size4);
  printf("Jsou slozeny ze stejnych hodnot? A-ano, N-ne: %c\n", are_same_vals?'A':'N');

  int arr5[] = {1,2,3,1};
  size_t size5 = sizeof(arr5)/sizeof(arr5[0]);
  int arr6[] = {3,1,2,3};
  size_t size6 = sizeof(arr6)/sizeof(arr6[0]);
  int is_anag = is_anagram(arr5, size5, arr6, size6);
  printf("Je jeden anagramem druheho? %s\n", is_anag?"Ano":"Ne");

  return 0;
}