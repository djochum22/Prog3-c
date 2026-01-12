#include <stdio.h>

int main(void) {
    int c = 100, l = 50, x = 10, v = 5, i = 1;
    int input = 0;
    int j = 0;

    scanf("%d", &input);

    while(input != 0) {
        if (input >= c) {
            for(j = 0; j < input / c; j++) {
                printf("C");
                input -= c;
            }
        } else if (input >= l) {
            for(j = 0; j < input / l; j++) {
                printf("L");
                input -= l;
            }
        } else if (input >= x) {
            for(j = 0; j < input / x; j++) {
                printf("X");
                input -= x;
            }
        } else if (input >= v) {
            for(j = 0; j < input / v; j++) {
                printf("V");
                input -= v;
            }
        } else if (input >= i) {
            for(j = 0; j < input / i; j++) {
                printf("I");
                input -= i;
            }
        }
    }
    
    printf("\n");
    
    return 0;
}