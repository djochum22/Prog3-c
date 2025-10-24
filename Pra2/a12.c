#include <stdio.h>
#include <math.h>

void writebit(unsigned z);
unsigned readbit(void);

int main(void)
{
    unsigned a, b;
    
    a = readbit();
    b = readbit();
    
    printf("Oder: ");
    writebit(a | b);

    printf("And: ");
    writebit(a & b);

    printf("XOR: ");
    writebit(a ^ b);
}

void writebit(unsigned z)
{
    int i = 0;

    for (i = 15; i >= 0; i--)
    {
        printf("%d", (z & 1 << i) != 0);
    }
    printf("\n");
}

unsigned readbit(void)
{
    int i;
    unsigned z;
    unsigned output;

    printf("Input: ");
    scanf("%16u", &z);

    for (i = 15; i >= 0; i--)
    {
        z %= 10;
        output += ((z & 1 >> i) != 0);
        z /= 10;
    }

    return output;
}