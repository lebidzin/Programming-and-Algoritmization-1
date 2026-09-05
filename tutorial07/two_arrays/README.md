# Porovnávání polí v jazyce C

Implementace funkcí pro porovnávání celočíselných polí z pohledu cyklické rotace, množinové shody hodnot a multimnožinové shody (anagramu).

## Přehled funkcí

* **Rotace polí (`is_rotation`)**
  * Zjišťuje, zda je jedno pole cyklickým posunem druhého se zachováním pořadí prvků.
  * `{1, 2, 3, 4}` a `{3, 4, 1, 2}` → `true`
  * `{1, 2, 3, 4}` a `{4, 3, 2, 1}` → `false`

* **Množinová shoda (`are_same_values`)**
  * Ověřuje, zda pole obsahují totožnou množinu unikátních hodnot bez ohledu na četnost opakování.
  * `{1, 2, 3, 1}` a `{3, 1, 2, 3}` → `true`
  * `{1, 2, 3, 1, 4}` a `{3, 1, 2, 3}` → `false`

* **Anagram (`is_anagram`)**
  * Ověřuje, zda je jedno pole přesmyčkou druhého (záleží na hodnotách i na přesném počtu výskytů každého prvku).
  * `{1, 2, 3, 3, 2}` a `{2, 3, 1, 2, 3}` → `true`
  * `{1, 2, 3, 1}` a `{3, 1, 2, 3}` → `false`

## Kompilace a spuštění

Pro překlad se doporučuje použít přepínače `-Wall -Wextra -pedantic` pro kontrolu standardu a zachycení případných chyb:

```bash
gcc -Wall -Wextra -pedantic main.c -o main