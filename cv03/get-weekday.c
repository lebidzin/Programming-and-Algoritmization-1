#include <stdio.h>

int pocet_dni_v_mesici(int m, int y) {
  int dny[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m == 2 && je_prestupny(y)) {
    return 29;
  }
  return dny[m - 1];
}

int main(void) {
  int d, m, y;
  const char *dny_v_tydnu[] = {
    "Sobota", "Nedele", "Pondeli", "Utery", "Streda", "Ctvrtek", "Patek"
  };

  printf("Zadejte datum (den mesic rok):\n");
  if (scanf("%d %d %d", &d, &m, &y) != 3) {
    printf("Neplatny vstup.\n");
    return 1;
  }

  if (y < 1584 || m < 1 || m > 12 || d < 1 || d > pocet_dni_v_mesici(m, y)) {
    printf("Neplatne datum.\n");
    return 1;
  }

  // Úprava pro leden a únor (přechod na 13. a 14. měsíc předchozího roku)
  int z_m = m;
  int z_y = y;
  if (z_m < 3) {
    z_m += 12;
    z_y -= 1;
  }

  int q = d;
  int K = z_y % 100;
  int J = z_y / 100;

  // Zellerova kongruence
  int h = (q + (13 * (z_m + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;

  // Ošetření záporného zbytku po dělení v C
  h = (h + 7) % 7;

  printf("Datum %02d.%02d.%d pripada na: %s\n", d, m, y, dny_v_tydnu[h]);

  return 0;
}