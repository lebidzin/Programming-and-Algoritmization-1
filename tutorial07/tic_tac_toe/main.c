#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 15

void print_board(char *board, int N){
  for(int i=1;i<=N;i++){
    printf("%2d ", i);
  }
  printf("\n");
  printf("|");
  for(int i=0;i<N;i++){
    printf("%c| ", board[i]);
  }
  printf("\n");
}

bool check_win(char *board, int N){
  for(int i=0;i<=N-3;i++){
    if(board[i]=='X'&&board[i+1]=='X'&&board[i+2]=='X'){
      return true;
    }
  }
  return false;
}

int read_user_input(char *board,int N){
  int input;
  printf("Zadejte index kam chcete postavit 'X':\n");
  while(scanf("%d",&input)!=1 || input > N || input < 1 || board[input-1]=='X'){
    printf("Nevalidni input\n");
    while (getchar() != '\n');
  };
  return input;
}

int get_free_elements(int *array, char *board, int N){
  int array_index = 0;
  for(int i=0;i<N;i++){
    if(board[i]==' '){
      array[array_index++] = i;
    }
  }
  // Pocet nalezenych volnych indexu
  return array_index;
}

bool check_for_free_spaces(char *board, int N){
  for(int i=0;i<N;i++){
    if(board[i]!='X'){
      return true;
    }
  }
  return false;
}

int pc_try_put_x_on_every_space(char *board, int N){
  for(int i=0;i<N;i++){
    if(board[i] == ' '){
      board[i] = 'X';
      if(check_win(board, N)){
        board[i] = ' ';
        return i;
      };
      board[i] = ' ';
    }
  }
  return -1;
}

int pc_avoid_let_player_win(char *board, int N){
  int res;
  for(int i=0;i<N;i++){
    if(board[i]==' '){
      board[i] = 'X';
      res = pc_try_put_x_on_every_space(board,N);
      if(res == -1){
        board[i] = ' ';
        return i;
      }
      board[i] = ' ';
    }
  }
  return -1;
}

int main(){
  srand(time(NULL));

  int N;
  char board[MAXN];
  int current_player = 0;
  int user_input;
  int free_indices[MAXN];
  
  printf("Zadejte delku hraciho planu:\n");
  while(scanf("%d",&N)!=1 || N>MAXN || N<3){
    printf("N ma byt: <= %d a >= 3\n", MAXN);
    while (getchar() != '\n');
  }
  
  for(int i=0;i<N;i++){
    board[i]=' ';
  }

  print_board(board, N);
  while(!check_win(board, N)){
    if(check_for_free_spaces(board, N)){
      if(current_player == 0){
        user_input = read_user_input(board, N);
        board[user_input-1]='X';
        current_player=1-current_player;
      }else if(current_player == 1){
        printf("Ted je na rade pocitac:\n");
        printf("Pocitac mysli...\n");
        sleep(1);
        int computer_chose_index;

        int immidiate_win_index = pc_try_put_x_on_every_space(board, N);
        if(immidiate_win_index != -1){
          computer_chose_index = immidiate_win_index;
        }else{
          int tmp = pc_avoid_let_player_win(board, N);
          if(tmp != -1){
            computer_chose_index = tmp;
          }else{
            int K = get_free_elements(free_indices, board, N);
            computer_chose_index = free_indices[rand()%K];
          };
        }

        board[computer_chose_index]='X';
        printf("Pocitac zahral na index=%d\n",computer_chose_index+1);
        current_player=1-current_player;
      }
    }else{
      printf("Remiza\n");
      return 0;
    }
    print_board(board, N);
  }

  if(1-current_player == 0){
    printf("Jste vyhrali! GRATULUJEME!!!\n");
  }else{
    printf("Pocitac vyhral:(\n");
  }

  return 0;
}