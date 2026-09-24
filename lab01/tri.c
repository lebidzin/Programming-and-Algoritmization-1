#include <stdio.h>

int main() {
    int height;
    printf("Zadej výšku trojúhelníku: ");
    if(scanf("%d", &height) != 1) {
        printf("Špatný vstup, zadej číslo.\n");
        return 1;
    }

for (int row = 1; row <= height; row++) {
        for (int col = 1; col <= height; col++) {
        if(col == 1 || col == height || row==1 || row==height){
        	printf("+");
        }else{
        	printf(" ");
        	}
        }
        printf("\n");
    }

    return 0;
}
