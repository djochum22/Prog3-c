#include <stdio.h>

int c = 100;
int l = 50;
int x = 10;
int v = 5;
int i = 1;

int main(void)
{
    int input;
    int anzahl_c = 0, anzahl_l = 0, anzahl_x = 0, anzahl_v = 0, anzahl_i = 0;

    printf("Input number: ");
    scanf("%d", &input);

    anzahl_c = input / c;
    input %= c;

    anzahl_l = input / l;
    input %= l;

    anzahl_x = input / x;
    input %= x;

    anzahl_v = input / v;
    input %= v;

    anzahl_i = input / i;
    input %= i;

    for (anzahl_c; anzahl_c > 0; anzahl_c--) {
        printf("C");
    }

    for (anzahl_l; anzahl_l > 0; anzahl_l--) {
        printf("L");
    }

    for (anzahl_x; anzahl_x > 0; anzahl_x--) {
        printf("X");
    }
    
    for (anzahl_v; anzahl_v > 0; anzahl_v--) {
        printf("V");
    }

    for (anzahl_i; anzahl_i > 0; anzahl_i--) {
        printf("I");
    }
}

