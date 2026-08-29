#include <stdio.h>
#include <math.h>

int print_stars(int amount){
  if(!amount){
    return 1;
  }
  for(int i=0;i<amount;i++){
    printf("*");
  }
  printf("\n");
  return 0;
}

int print_rectangle(int a, int b){
  if(!a || !b){
    return 1;
  }
  for(int i=0;i<a;i++){
    print_stars(b);
  }
  return 0;
}
int print_triangle(int height){
  if(!height){
    return 1;
  }
  for(int i=1;i<=height;i++){
    print_stars(i);
  }
  return 0;
}

int print_minimum(int a, int b){
  if(a<b){
    printf("%d\n", a);
  }else{
    printf("%d\n", b);
  }
  return 0;
}

struct point_in_space{
  double x;
  double y;
};

int calc_distance(struct point_in_space a, struct  point_in_space b){
  double dx = b.x-a.x;
  double dy = b.y-a.y;

  double distance = hypot(dx, dy);

  printf("Vzdalenost: %f\n", distance);
  return 0;
}

int main(void){
  print_stars(10);
  print_rectangle(2, 4);
  print_triangle(3);
  struct point_in_space a;
  a.x = 1;
  a.y = 2;
  struct point_in_space b;
  b.x = 3;
  b.y = 4;
  calc_distance(a, b);
  return 0;
}