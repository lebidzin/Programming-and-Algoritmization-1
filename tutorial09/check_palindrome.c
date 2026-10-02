#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char * read_line(){
  size_t capacity = 16;
  char * str;
  char * tmp = malloc(capacity);
  if(tmp != NULL){
    str = tmp;
  }else{
    return NULL;
  }
  size_t len = 0;
  int c;
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

bool check_palindrome(char * str){
  size_t len = strlen(str);
  for(size_t i=0;i<len;i++){
    str[i]=tolower(str[i]);
  }

  for(size_t i=0;i<len/2;i++){
    // printf("i: %zu; len-i-1: %zu\n", i, len-i-1);
    if(str[i] != str[len-i-1])
      return false;
  }

  return true;
}

int main(void){
  char * line = read_line();
  if(line == NULL){
    printf("Chyba alokace pameti nebo chybny vstup\n");
    return EXIT_FAILURE;
  }

  bool res = check_palindrome(line);
  printf("Vysledek: %s\n", res ? "true" : "false");

  free(line);
  return EXIT_SUCCESS;
}