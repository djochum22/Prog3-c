#include <stdio.h>

int main(void)
{
    double x;
    double w1, w2;
    double abstand = 0;

    printf("Input X: ");
    scanf("%lf", &x);

    w1 = (1 + x) / 2;

    do
    {
        w2 = (w1 + (x / w1)) / 2;
        abstand = -(w2 - w1);
        w1 = w2;
    } while (abstand > 0.0000001 && x != 0);

    printf("Output: %6.4f", w1);
}