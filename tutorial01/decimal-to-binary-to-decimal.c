#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rev(char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    char t;

    while (l < r) {
      
        t = s[l];
        s[l] = s[r];
        s[r] = t;

        l++;
        r--;
    }
}

char* translateToBinary (int number) {
    char* binaryString = malloc(sizeof(char) * 33);
    int stringLen = 0;
    int k = number;

    if(number == 0){
        binaryString[stringLen++] = '0';
    }

    while (k >= 1){
        binaryString[stringLen++] = (k % 2 == 0) ? '0' : '1';
        k/=2;
    }
    binaryString[stringLen] = '\0';

    rev(binaryString);
    return binaryString;
}

int translateToDecimal (char* binaryString) {
    int result = 0;
    int base = 1;

    for(int i=strlen(binaryString)-1;i>=0;i--){
        if(binaryString[i] == '1'){
            result += base;
        }
        base *= 2;
    }

    return result;
}

int main(void) {
    printf("%s\n", translateToBinary(1));
    printf("%s\n", translateToBinary(45));
    printf("%s\n", translateToBinary(13));
    printf("%s\n", translateToBinary(27));
    printf("%d\n", translateToDecimal("10111"));
    printf("%d\n", translateToDecimal("1111"));
    return 0;
}