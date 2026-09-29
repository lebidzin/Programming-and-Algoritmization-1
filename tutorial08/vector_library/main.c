#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
  const double *da = (const double *)a;
  const double *db = (const double *)b;
  if(*da > *db){
    return 1;
  }else if(*da < *db){
    return -1;
  }else{
    return 0;
  }
}

struct vec{
  double * data;
  size_t size;
  size_t capacity;
};

struct vec create_vec(){
  struct vec vec1;
  vec1.data = NULL;
  vec1.size = 0;
  vec1.capacity = 0;
  return vec1;
}

int realloc_vec(struct vec *vec1, size_t N){
  double * tmp = realloc(vec1->data, (N * sizeof(double)));
  if(tmp == NULL){
    return 1;
  }else{
    vec1->data = tmp;
    vec1->capacity = N;
    return 0;
  };
}

int add_number_to_the_end(struct vec *vec1, double num){
  if(vec1->size+1 > vec1->capacity){
    if(vec1->capacity == 0){
      if(realloc_vec(vec1, 4) == 1){
        return 1;
      };
    }else{
      if(realloc_vec(vec1, vec1->capacity * 2) == 1){
        return 1;
      };
    }
  }
  vec1->data[vec1->size++] = num;
  return 0;
}

void remove_number_from_the_end(struct vec *vec1){
  if(vec1->size > 0){
    vec1->size--;
    if(vec1->size < (vec1->capacity/4)){
      realloc_vec(vec1, vec1->capacity/2);
    }
  }
}

void print_vec(struct vec *vec1){
  for(size_t i=0;i<vec1->size;i++){
    printf("%.2lf\n",vec1->data[i]);
  }
}

void sort_vec(struct vec *vec1){
  qsort(vec1->data, vec1->size, sizeof(double), comp);
}

void clean_array(struct vec *vec1){
  free(vec1->data);
  vec1->data = NULL;
  vec1->size = 0;
  vec1->capacity = 0;
} 

int main(void){
  struct vec vec1 = create_vec();
  if(add_number_to_the_end(&vec1, 10) == 1){
    printf("Chyba\n");
    return 1;
  };
  if(add_number_to_the_end(&vec1, 9) == 1){
    printf("Chyba\n");
    return 1;
  };
  if(add_number_to_the_end(&vec1, 200) == 1){
    printf("Chyba\n");
    return 1;
  };
  if(add_number_to_the_end(&vec1, 130) == 1){
    printf("Chyba\n");
    return 1;
  };
  print_vec(&vec1);
  printf("-----");
  sort_vec(&vec1);
  print_vec(&vec1);
  clean_array(&vec1);
  return 0;
}