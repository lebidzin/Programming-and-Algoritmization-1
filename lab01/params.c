 #include <stdio.h>
 #include <stdlib.h>

int main (int argc, char *argv[]) {
    printf( "Hello World!\n" );
    printf("Pocet parametru: %d\n", argc);
    printf("Parametr 0: %s\n", argv[0]);
    if(argc > 1) printf("Parametr 1: %s\n", argv[1]);
    if(argc > 2) printf("Parametr 2: %s\n", argv[2]);
    if(argc > 3) printf("Parametr 3: %s\n", argv[3]);
    
    int i1;
    int i2;
    if(scanf("%d\n"))
    printf("Soucet: %d\n", i1+i2);
    		
    return 0;
}
