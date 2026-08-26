```markdown
# Programování a algoritmizace (C)

Repozitář obsahuje zdrojové kódy, úlohy ze cvičení a testovací skripty pro předmět Programování a algoritmizace. Zaměřuje se na návrh algoritmů, jejich zápis v jazyce C, nízkoúrovňovou práci s pamětí a efektivitu řešení.

---

## O předmětu

Cílem je zvládnout základy procedurálního programování a algoritmického myšlení v jazyce C:
* Práce se základními, ukazatelovými a strukturovanými datovými typy
* Správa paměti (statická i dynamická alokace)
* Rekurze a analýza časové/paměťové složitosti
* Základní vyhledávací a řadicí algoritmy
* Práce s dynamickými datovými strukturami (jednosměrné a obousměrné spojové seznamy)

---

## Přehled cvičení

| Týden | Téma cvičení | Klíčové koncepty |
| :--- | :--- | :--- |
| **01** | Učebna, kompilace a číselné soustavy | GCC/Clang, binární a hexadecimální reprezentace |
| **02** | Celočíselné proměnné, vstup a výstup | `printf`, `scanf`, formátovací specifikátory, celočíselné typy |
| **03** | Podmíněné příkazy | Větvení kódu, `if` / `else`, `switch`, logické výrazy |
| **04** | Cykly a posloupnosti | `for`, `while`, `do-while`, iterace |
| **05** | Racionální typy, použití funkcí a ošetření vstupu | Plovoucí řádová čárka (`double`), modularizace, validace I/O |
| **06** | Funkce a struktury | Uživatelské typy (`struct`), předávání parametrů hodnotou |
| **07** | Staticky alokovaná pole | 1D a 2D pole, práce s indexy, meze polí |
| **08** | Ukazatele a dynamická alokace paměti | Pointerová aritmetika, `malloc`, `calloc`, `realloc`, `free` |
| **09** | Řetězce | Textové řetězce zakončené `\0`, manipulace a knihovna `<string.h>` |
| **10** | Rekurze | Rekurzivní rozklad problémů, bázové podmínky, zásobník volání |
| **11** | Časové složitosti algoritmů | Asymptotická složitost $\mathcal{O}(n)$, řazení, vyhledávání |
| **12** | Spojové struktury | Jednosměrně a obousměrně vázané lineární seznamy |

---

## Překlad a testování

Jednotlivé programy se překládají pomocí standardního C kompilátoru:

```bash
g++ -Wall -pedantic main.c -o program

```

### Testování vstupů a výstupů

Pro ověření správnosti programů se využíváji porovnání referenčních testovacich dat:

```bash
./program < test_01.in > test_01.out
diff test_01.out test_01.ref

```

*Pokud příkaz `diff` nevrátí žádný výstup, program splnil testovací scénář.*

```

```