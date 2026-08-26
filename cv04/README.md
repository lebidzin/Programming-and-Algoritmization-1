```markdown
# Hra „Samá voda, přihořívá“ (2D)

Konzolová hra v jazyce C, kde hráč hledá náhodně vygenerovaný cíl v 2D prostoru na intervalu $\langle -10.0, 10.0 \rangle$. Program po každém kroku vyhodnocuje změnu vzdálenosti a navádí hráče hláškami *Prihoriva*, *Sama voda*, případně *Hori!* při dosažení cíle.

---

## Překlad programu

Program přeložte pomocí standardního C kompilátoru:

```bash
gcc -Wall -pedantic hra_sama_voda.c -lm -o hra_sama_voda

```

---

## Spuštění

* **Běžný režim (náhodný seed dle času):**
```bash
./hra_sama_voda

```


* **Deterministický režim (fixní seed pro testování):**
```bash
./hra_sama_voda --seed 42

```



---

## Testování programu

Testování probíhá porovnáním výstupu programu s referenčním souborem pomocí nástroje `diff`. Pokud je výstup příkazu `diff` prázdný, test proběhl úspěšně.

### Test 000 – Základní běh

```bash
./hra_sama_voda < hra_sama_voda_000.in > hra_sama_voda_000.out
diff hra_sama_voda_000.out hra_sama_voda_000.ref

```

*Pokud je výstup prázdný $\Rightarrow$ program funguje správně.*

### Test 001 – Běh s fixním seedem

```bash
./hra_sama_voda --seed 42 < hra_sama_voda_001.in > hra_sama_voda_001.out
diff hra_sama_voda_001.out hra_sama_voda_001.ref

```

*Pokud je výstup prázdný $\Rightarrow$ program funguje správně.*

```

```

DEBUG: Cíl je [-9.993, 0.492]