#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_rotation(const char * str1, const char * str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if (len1 != len2) {
    return false;
  }
  if(len1 == 0 && len2 == 0){
    return true;
  }
  for(size_t k=0;k<=len1-1;k++){
    size_t i;
    for(i=0;i<len2;i++){
      if(str1[(i+k)%len2]!=str2[i]){
        break;
      }
    }
    if(i==len2){
      return true;
    }
    k++;
  }
  return false;
}

int main(void){
  bool res = is_rotation("abcd", "dcba");
  printf("Result: %s\n", res ? "true" : "false");
  
  return EXIT_SUCCESS;
}