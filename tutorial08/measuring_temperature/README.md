Měření teploty

Naimplementujte aplikaci pro zpracování statistických dat o teplotách. Na vstupu vám uživatel zadá teploty pro každý den jako desetinná čísla, data z měření jsou ukončena 0 (není znám jejich počet). Poté následuje seznam dotazů, ten je ukončen EOF. Dotazy jsou ve formátu (from;to>. Konkrétně pro <0;7) to znamená, že nás zajímají statistiky pro den 0 (včetně) až do dne 7 (ten již ve výběru nebude). Pro tyto dny chceme vypsat minimum, maximum a průměrnou teplotu.

Není dobrý nápad ukládat si dotazy, těch může být opravdu mnoho a nemusí nám stačit paměť. Navíc uživatel nechce čekat až zadá všechny vstupy a chce výsledky dostávat průběžně.

Ukázka vstupu a výstupu

Aby byl program zobrazen jako interaktivní aplikace, jsou vstupy uvozeny znakem $ a výstupy :. Tyto znaky na vstup a výstup nedávejte.

$ 1 2 3 4 5
$ 6 7 8
$ 9 10 0
$ <0;4>
: min=1, max=5, avg=3
$ <0;3)(0;2)
: min=1, max=3, avg=2
: min=2, max=2, avg=2
$ [0;3]
: Nespravny vstup.