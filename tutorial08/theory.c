// Co je to ukazatel (pointer)?: Pointer je adresa v pameti

// Kde jsme se již s ukazateli (pointery) potkali?: Volání scanf(): Předávání adresy pomocí operátoru & (např. scanf("%d", &x)), aby funkce mohla zapsat hodnotu do tvé proměnné.

// Kdy se použití ukazatelů (pointerů) hodí?: napriklad kdyz potrebujeme predat do funkce jako parametr puvodni promennou a uvnitr funkce menit puvodni promennou.
// take pro efektivitu (předání velké struktury ukazatelem je levné, nekopíruje se celá paměť)

// V čem se liší staticky a dynamicky alokované pole?: dynamicke alokovane pole, alokuji pamet at runtime
// Statické pole má fixní velikost danou v době překladu a žije na zásobníku (stacku)

// Jak můžu pole zvětšit?: pomoci realloc(), funguje výhradně na dynamicky alokovanou paměť na haldě

// Jak přistupujeme k atributům struktury, kterou předáváme pomocí ukazatele?: ->