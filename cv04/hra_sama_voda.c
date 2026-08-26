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

// Pomocna funkce pro vyhru hrace
// navratovy hodnoty: 0 - hrac jeste neni v cili; 1 - hrac vyhral a zvolil novou hru; 2 - hrac vyhral a zvolil konec;
int did_player_win(double d, double target_x, double target_y, int steps_count, int *best_score, int *wins_count, int games_count){
  if(d <= D){
    printf("Hori! Souradnice x y: %.3f %.3f. Pocet kroku: %d\n", target_x, target_y, steps_count);
    (*wins_count)++;
    if(*best_score == -1 || steps_count < *best_score){
      printf("Wow! Novy rekord tahu: %d; ", steps_count);
      if(*best_score == -1){
        printf("Predchozi rekord tahu: Zadny\n");
      }else{
        printf("Predchozi rekord tahu: %d\n", *best_score);
      }
      *best_score = steps_count;
    }else{
      printf("Stavajici rekord tahu: %d\n", *best_score);
    }
    char cont;
    printf("Zadejte 'a', pokud chete hrat znovu, 'n' pokud chete ukoncit\n");
    if(scanf(" %c", &cont)!=1){
      printf("Neplatny vstup\n");
      printf("Pocet hranych her: %d\n", games_count);
      return 2;
    }
    if(cont == 'a'){
      return 1;
    } else{
      printf("Pocet hranych her: %d\n", games_count);
      return 2;
    }
  }else{
    return 0;
  }
}

int main ( int argc, const char * argv [] ){
  if(argc >= 3 && strcmp(argv[1], "--seed") == 0){
    /* Inicializuje generator nahodnych cisel, pomoci seedu z prikazu terminalu */
    srand( (unsigned int)atoi(argv[2]) );
  }else{
    srand( time( NULL ) );
  }

  int best_score = -1;
  int games_count = 0;
  int wins_count = 0;
  while(1){
    // Vygenerování 2D pozice cíle
    double target_x = random_double(MINS, MAXS);
    double target_y = random_double(MINS, MAXS);

    games_count++;
    int steps_count = 0;
    double player_x_new = 0.000;
    double player_y_new = 0.000;
    // 0.0 0.0 pocatecne souradnice hrace
    double dx_prev = 0.0-target_x;
    double dy_prev = 0.0-target_y;
    double d_prev = sqrt(dx_prev*dx_prev+dy_prev*dy_prev);
    // 0 - pokracuje; 1 - pokracuje; 2 - stop
    int player_won_return = did_player_win(d_prev, target_x, target_y, steps_count, &best_score, &wins_count, games_count);
    if(player_won_return == 2){
      return 0;
    }else if(player_won_return == 1){continue;}
    while(1){
      printf("Napiste nove souradnice v intervalu [-10.0; 10.0] x y:\n");
      if(scanf("%lf %lf", &player_x_new, &player_y_new) != 2 || fabs(player_x_new)>MAXS || fabs(player_y_new)>MAXS){
        printf("Souradnice maji byt ve forme .3f a v intervalu [-10.0; 10.0]\n");
        return 1;
      }
      double dx_new = player_x_new-target_x;
      double dy_new = player_y_new-target_y;
      double d_new = sqrt(dx_new*dx_new+dy_new*dy_new);
      steps_count++;
      if(d_new <= D){
        player_won_return = did_player_win(d_new, target_x, target_y, steps_count, &best_score, &wins_count, games_count);
        if(player_won_return == 2){
          return 0;
        }else if(player_won_return == 1){break;}
      }else if(d_new < d_prev){
        printf("Prihoriva! Pocet kroku: %d\n", steps_count);
      }else if(d_new > d_prev){
        printf("Sama voda! Pocet kroku: %d\n", steps_count);
      }else if(d_new == d_prev){
        printf("Stejne souradnice! Zustali jste na miste! Pocet kroku: %d\n", steps_count);
      }
      d_prev = d_new;
    }
  }

  return 0;
}