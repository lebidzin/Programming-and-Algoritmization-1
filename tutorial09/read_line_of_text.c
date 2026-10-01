#include <stdio.h>
#include <stdlib.h>

char * read_line(){
  int capacity = 16;
  char * str;
  char * tmp = malloc(capacity);
  if(tmp != NULL){
    str = tmp;
  }else{
    return NULL;
  }
  size_t len = 0;
  size_t c;
  while(1){
    c = getchar();
    if(c == '\n' || c == EOF){
      break;
    }
    if(len + 1 >= capacity){
      capacity *= 2;
      char * tmp;
      tmp = realloc(str, capacity);
      if(tmp != NULL){
        str = tmp;
      }else{
        free(str);
        return NULL;
      }
    }
    str[len] = c;
    len++;
  }
  if(c == EOF && len == 0){
    free(str);
    return NULL;
  }
  str[len] = '\0';
  return str;
}

int main(void){
  char * line = read_line();
  if(line == NULL){
    printf("Chyba alokace pameti nebo chybny vstup\n");
  }
  printf("%s\n", line);
  free(line);
  return 0;
}