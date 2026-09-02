chmod +x test.sh
./test.sh

Zde jsou sady testovacích dat navržené pro main.c (3D_vector program)

### Test 1: Základní matematika (`basic.in`)

Tento test ověřuje správnost matematických výpočtů a běžný průchod programem.

**Vstup:**

```text
a
3 4 0
c
1 2 3
4 5 6
e
1.5 2.5 -3
1.5 2.5 -3
q

```

**Očekávaný výsledek (ve zkratce):**

* **a:** Velikost vektoru <3, 4, 0> je `5.000000`.
* **c:** Skalární součin <1, 2, 3> a <4, 5, 6> je `32.000000` (1*4 + 2*5 + 3*6).
* **e:** Vektory jsou rovné.
* Při zadání `q` (nebo libovolného jiného neplatného znaku pro menu) se program korektně ukončí (návratová hodnota 0).

---

### Test 2: Směry, velikosti a křížový součin (`vectors.in`)

Ověřuje logiku úhlů, kolmosti a porovnávání pomocí tolerance.

**Vstup:**

```text
b
1 0 0
0 1 0
f
1 2 3
2 4 6
f
1 2 3
-1 -2 -3
g
3 4 0
0 -5 0

```

**Očekávaný výsledek:**

* **b:** Vektorový součin osy X a Y musí dát osu Z: `<0.000000, 0.000000, 1.000000>`.
* **f (první):** Mají stejný směr (druhý je dvojnásobkem prvního, skalární součin je kladný).
* **f (druhý):** NEmají stejný směr (leží na stejné přímce, ale míří opačně, skalární součin je záporný).
* **g:** Mají stejnou velikost (velikost obou je přesně 5).

---

### Test 3: Odolnost vůči chybám (`errors.in`)

Tento test odhalí, zda máš správně implementované čištění bufferu u všech vstupů.

**Vstup:**

```text
a
neplatny_vektor
3 4 0
d
1 2 3
chybna_konstanta
5

```

**Očekávaný chování programu:**

* **a:** Po zadání `neplatny_vektor` program vypíše chybu, nevykolejí se a počká na správný vstup `3 4 0` (velikost 5).
* **d:** Po načtení vektoru program narazí na `chybna_konstanta`. Musí vypsat chybu (pokud jsi tam ten tisk přidal) a následně vzít konstantu `5`. Výsledek bude `<5.000000, 10.000000, 15.000000>`.

Než spustíš ten třetí test, ujisti se, že jsi do větve `case 'd'` přidal tu chybějící funkci `clean_buffer()` z minulé zprávy, jinak se ti test zacyklí.