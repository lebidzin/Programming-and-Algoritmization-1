# 1D Piškvorky

Konzolová implementace jednorozměrné varianty klasické hry piškvorky.

---

## Pravidla hry

- **Herní plán:** Jednorozměrné pole o délce $N$ políček (vstupní parametr, maximálně definovaná konstanta `MAXN`).
- **Symbol:** Oba hráči hrají se stejným symbolem – křížkem (`X`).
- **Průběh:** Hráči se střídají v tazích a umisťují svůj křížek do volného políčka.
- **Cíl hry:** Vyhrává ten hráč, který jako první vytvoří souvislou řadu alespoň **3 křížků vedle sebe** (`XXX`).

---

## Ukázka hry

```text
             1 2 3 4 5 6 7 8
Player A => | | | |X| | | | |
Player B => | | | |X| | |X| |
Player A => |X| | |X| | |X| |
Player B => |X| | |X| | |X|X|
Player A => |X| | |X| |X|X|X| => Winner