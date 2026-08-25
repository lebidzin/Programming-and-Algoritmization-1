#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MINS -10.0
#define MAXS  10.0

#define D 0.050

// Pomocná funkce pro vygenerování náhodného čísla v intervalu <min, max>
double random_double(double min, double max) {
  double scale = (double)rand() / (double)RAND_MAX;
  return min + scale * (max - min);
}

int main ( int argc, const char * argv [] ){
  if(argc >= 3 && strcmp(argv[1], "--seed") == 0){
    /* Inicializuje generator nahodnych cisel, pomoci seedu z prikazu terminalu */
    srand( (unsigned int)atoi(argv[2]) );
  }else{
    srand( time( NULL ) );
  }
  // Vygenerování 2D pozice cíle
  double target_x = random_double(MINS, MAXS);
  double target_y = random_double(MINS, MAXS);

  printf("DEBUG: Cíl je [%.3f, %.3f]\n", target_x, target_y);

  int steps_count = 0;
  double player_x_new = 0.000;
  double player_y_new = 0.000;
  // 0.0 0.0 pocatecne souradnice hrace
  double dx_prev = 0.0-target_x;
  double dy_prev = 0.0-target_y;
  double d_prev = sqrt(dx_prev*dx_prev+dy_prev*dy_prev);
  if(d_prev <= D){
    printf("Hori! Souradnice x y: %.3f %.3f Pocet kroku: %d\n", target_x, target_y, steps_count);
    return 0;
  }
  while(1){
    printf("Napiste nove souradnice v intervalu [-10.0; 10.0] x y:\n");
    if(scanf("%lf %lf", &player_x_new, &player_y_new) != 2 || abs(player_x_new)>10 || abs(player_y_new)>10){
      printf("Souradnice maji byt ve forme .3f a v intervalu [-10.0; 10.0]\n");
      return 1;
    };
    double dx_new = player_x_new-target_x;
    double dy_new = player_y_new-target_y;
    double d_new = sqrt(dx_new*dx_new+dy_new*dy_new);
    steps_count++;
    if(d_new <= D){
      printf("Hori! Souradnice x y: [%.3f %.3f] Pocet kroku: %d\n", target_x, target_y, steps_count);
      return 0;
    }else if(d_new < d_prev){
      printf("Prihoriva! Pocet kroku: %d\n", steps_count);
    }else if(d_new > d_prev){
      printf("Sama voda! Pocet kroku: %d\n", steps_count);
    }else if(d_new == d_prev){
      printf("Stejne souradnice! Zustali jste na miste! Pocet kroku: %d\n", steps_count);
    }
    d_prev = d_new;
  }

  return 0;
}