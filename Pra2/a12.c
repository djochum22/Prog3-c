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
    int pow = 1;
    unsigned z;
    unsigned output = 0;

    printf("Input: ");
    scanf("%u", &z);

    for (i = 0; i <= 15; i++)
    {
        if (z % 10 == 1)
        {
            output += pow;
        }
        z /= 10;
        pow *= 2;
    }

    return output;
}