# Zlomková kalkulačka (Fraction Calculator)

Konzolová aplikace a knihovna v jazyce C pro přesné aritmetické výpočty se zlomky v základním tvaru bez zaokrouhlovacích chyb čísel s plovoucí řádovou čárkou.

## Funkcionalita

* **Podporované operace:**
* Sčítání (`+`): `a/b + c/d`
* Odčítání (`-`): `a/b - c/d`
* Násobení (`*`): `a/b * c/d`
* Dělení (`/`): `a/b : c/d`
* Rychlé umocňování (`^`): efektivní algoritmus *Square and Multiply* s časovou složitostí $O(\log n)$ pro kladné i záporné exponenty.


* **Automatická normalizace:** Zkrácení zlomku na základní tvar pomocí Eukleidova algoritmu (NSD/GCD) a standardizace znamének (kladný jmenovatel).
* **64bitová aritmetika:** Použití typu `long long` pro čitatele i jmenovatele pro snížení rizika celočíselného přetečení.
* **Validace vstupů:** Detekce dělení nulou a neplatně zadaných hodnot.

## Překlad

Kompilace pomocí GCC nebo Clangu se zapnutými varováními:

```bash
gcc -Wall -pedantic fractions_calculator.c -o fractions_calculator

```

## Spuštění a příklady

Aplikace funguje v interaktivním režimu. Vstupy jsou uvozeny znakem `$`, výsledky znakem `:`.

```text
$ + 1/2 1/4
: 3/4
$ - 4/8 2/8
: 1/4
$ * 2/3 3/4
: 1/2
$ / 1/2 2/3
: 3/4
$ ^ 1/2 3
: 1/8
$ ^ 1/2 -2
: 4/1

```

## Popis klíčových komponent

* **`struct Fraction`** – Datová struktura pro uložení čitatele (`numerator`) a jmenovatele (`denominator`).
* **`normalize_fraction`** – Zajišťuje zkrácení na základní tvar a přesun případného záporného znaménka do čitatele.
* **`find_gcd`** – Implementace Eukleidova algoritmu pro výpočet největšího společného dělitele.
* **`calc_xn_square_multiply`** – Algoritmus pro rychlé mocnění zlomků.
* **`read_fraction` / `print_fraction**` – Funkce pro bezpečné načítání a formátovaný výstup zlomků.