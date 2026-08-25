#include <stdio.h>

int main(){
  int a = 100;
  int b = 130;
  // for(int i=a;i<=b;i++){
  //   printf("%d ", i);
  // }
  // for(int i=b;i>=a;i--){
  //   printf("%d ", i);
  // }
  // for(int i=a;i<=b;i++){
  //   if(i % 2 != 0){
  //     printf("%d ", i);
  //   }
  // }
  int k = 3;
  for(int i=a;i<=b;i++){
    if(i % k == 0){
      printf("%d ", i);
    }
  }
}