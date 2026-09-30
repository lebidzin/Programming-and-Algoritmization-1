#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool detect_reverse_string(char * string1, char * string2){
  int str1_len = strlen(string1);
  int str2_len = strlen(string2);

  if(str1_len != str2_len){
    return false;
  }

  for(int i=0;i<str1_len;i++){
    if(string1[i] != string2[str2_len-i-1]){
      return false;
    }
  }

  return true;
}

int main(void){
  // bool res = detect_reverse_string("hello", "olleh");
  bool res = detect_reverse_string("Ahoj Pepa.", ".opeP johA");
  printf("%s", res ? "true" : "false");
  printf("\n");
  return 0;
}