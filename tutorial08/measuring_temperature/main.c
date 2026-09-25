#include <stdio.h>
#include <stdlib.h>

#define init_array_size 10

int read_temp_statistics(double **array){
  *array = malloc(sizeof(double)*init_array_size);
  int capacity = init_array_size;
  int array_size = 0;
  printf("Zadejte data o teplotach, aby ukoncit zadejte '0'\n");
  double tmp;
  while(scanf("%lf", &tmp) == 1 && tmp != 0){
    (*array)[array_size++] = tmp;
    if(array_size == capacity){
      *array = realloc(*array, capacity*2*sizeof(double));
      capacity *= 2;
    }
  }
  return array_size;
}

struct days_of_interest{
  int start;
  int end;
};

// Návratová hodnota indikuje stav: 1 = OK, 0 = neplatný formát, -1 = EOF
int read_days_of_interest(struct days_of_interest *data) {
    char l_bracket, r_bracket;
    int res = scanf(" %c %d ; %d %c", &l_bracket, &data->start, &data->end, &r_bracket);
    
    if (res == EOF) return -1;
    if (res != 4) return 0;
    if ((l_bracket != '(' && l_bracket != '[') || 
        (r_bracket != ')' && r_bracket != ']')) return 0;

    if (l_bracket == '(') data->start += 1;
    if (r_bracket == ')') data->end -= 1;
    return 1;
}

struct min_max_average{
  double min;
  double max;
  double average;
};

int calculate_max_min_average(double *array, int size, struct days_of_interest days_of_inter, struct min_max_average * min_max_aver){
  if(size < 3 || days_of_inter.start > days_of_inter.end){
    return 1;
  }
  if(days_of_inter.start < 0 || days_of_inter.end < 0 || days_of_inter.end >= size){
    return 1;
  }
  min_max_aver->min = array[days_of_inter.start];
  min_max_aver->max = array[days_of_inter.start];
  double sum = 0;
  for(int i=days_of_inter.start;i<=days_of_inter.end;i++){
    sum += array[i];
    if(array[i] > min_max_aver->max){
      min_max_aver->max = array[i];
    }else if(array[i] < min_max_aver->min){
      min_max_aver->min = array[i];
    }
  }
  min_max_aver->average = sum / (days_of_inter.end - days_of_inter.start + 1);
  return 0;
}

int main(void){
  double *array = NULL; 
  int array_size;
  struct min_max_average min_max_aver;
  struct days_of_interest days_of_inter;
  array_size = read_temp_statistics(&array);
  while(1){
    printf("$ ");
    fflush(stdout);
    if(read_days_of_interest(&days_of_inter) == 1){
      printf("Nespravny vstup\n");
      break;
    };
    if(calculate_max_min_average(array, array_size, days_of_inter, &min_max_aver) == 1){
      printf("Neni mozne spocitat min_max_average pro ZADANE hodnoty\n");
      break;
    };
    printf("min=%.0lf, max=%.0lf, avg=%.0lf\n", min_max_aver.min, min_max_aver.max, min_max_aver.average);
  }
  free(array);
  return 0;
}