// K čemu slouží funkce? - Funkce slouzi k napsani kodu pro opakovane pouziti. Oddeluji kod kteri vykonava konkretni funkci. Rozdeluje komplexni problem na mensi

// K čemu slouží struktury? - Struktury jsou neco jako objetky pro ukladani dat. Muzeme ulozit do nich vice typu dat najednou (na rozdil od arrayu). K jednotlivym datum pristupuje pres operator tecky(.)

#include <stdio.h>

void increment ( int i ) {
	i += 1;
}

int main () {
	int x = 0;
	increment( x );
	printf( "%d\n", x );
	return 0;
}

// vypise 0, protoze do funkce "increment" predavame jenom kopie x