#include <stdio.h>

int main(){
  const char *jednotky[] = {
    "jedna", "dva", "tri", "ctyri", "pet", "sest", "sedm", "osm", "devet"
  };
  const char *cisla[] = {
    "deset", "jedenact", "dvanact", "trinact", "ctyrnact", "patnact", "sestnact", "sedmnact", "osmnact", "devatnact"
  };
  const char *desitky[] = {
    "dvacet", "tricet", "ctyricet", "padesat", "sedesat", "sedmdesat", "osmdesat", "devadesat"
  };
  const char *stovky[] = {
    "sto", "dve ste", "tri sta", "ctyri sta", "pet set", "sest set", "sedm set", "osm set", "devat set"
  };
  const char *tisice[] = {
    "tisic", "dva tisice", "tri tisice", "ctyri tisice", "pet tisic", "sest tisic", "sedm tisic", "osm tisic", "devat tisic"
  };

  int x;
  printf("*** Zdravim, napiste cislo, ktere chcete dozvedet, jak se pise, z intervalu 0 - 9999 ***\n");
  if(scanf("%d", &x)!=1 || x<0 || x>9999){
    printf("Zadejte platne cislo\n");
    return 1;
  }

  if(x==0){
    printf("CISLO JE: nula");
    return 0;
  }

  int tisiceI = x / 1000;
  int stovkyI = (x % 1000) / 100;
  int desitkyI = (x % 100) / 10;
  int jednotkyI = x % 10;

  printf("CISLO JE:\n");
  if(tisiceI > 0){
    printf("%s ", tisice[tisiceI-1]);
  }

  if(stovkyI > 0){
    printf("%s ", stovky[stovkyI-1]);
  }

// Osetreni desitek a jednotek
  if (desitkyI == 1) {
    // 10 az 19 (nact)
    printf("%s", cisla[jednotkyI]);
  } else {
    if (desitkyI >= 2) {
      printf("%s ", desitky[desitkyI - 2]);
    }
    if (jednotkyI > 0) {
      printf("%s", jednotky[jednotkyI - 1]);
    }
  }

  printf("\n");

  return 0;
}