#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char time[6];
  printf("Prosim napiste cas ve formatu HH:MM: \n");
  if (scanf("%5s", time) != 1) {
    printf("Nespravne zadany cas, ma byt ve formatu HH:MM");
    return 1;
  }

  char *sep = strchr(time, ':');
  if (sep == NULL) {
    printf("Chyba: Chybí oddělovač ':'\n");
    return 1;
  }
  *sep = '\0';            // Přeruší řetězec na místě dvojtečky
  int h1 = atoi(time);
  int m1 = atoi(sep+1);

  char time2[6];
  printf("Prosim napiste druhy cas ve formatu HH:MM: \n");
  if (scanf("%5s", time2) != 1) {
    printf("Nespravne zadany cas, ma byt ve formatu HH:MM");
    return 1;
  }

  char *sep2 = strchr(time2, ':');
  if (sep2 == NULL) {
    printf("Chyba: Chybí oddělovač ':'\n");
    return 1;
  }
  *sep2 = '\0';            // Přeruší řetězec na místě dvojtečky
  int h2 = atoi(time2);
  int m2 = atoi(sep2+1);

  if (h1 < 0 || h1 > 23 || m1 < 0 || m1 > 59 ||
    h2 < 0 || h2 > 23 || m2 < 0 || m2 > 59) {
    printf("Chyba: Neplatné hodnoty hodin nebo minut.\n");
    return 1;
  }

  int minutes1 = h1*60+m1;
  int minutes2 = h2*60+m2;
  int minutesResult;
  if(minutes1 > minutes2){
    minutesResult = minutes1-minutes2;
  }else{
    minutesResult = minutes2-minutes1;
  }

  printf("Rozdil v case je %02d:%02d\n", minutesResult/60, minutesResult%60);
  return 0;
}