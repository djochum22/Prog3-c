#include <stdio.h>

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

    return 0;
}

void writebit(unsigned z)
{
    int i;

    for (i = 0; i < 16; i++)
    {
        printf("%d", (z & 1 << i) != 1);
    }
    printf("\n");
}

unsigned readbit(void)
{
    unsigned input;
    int i;
    int pow = 1;
    unsigned output;

    printf("input: ");
    scanf("%d", &input);

    for(i = 0; i < 16; i++)
    {
        if (input % 10 == 1)
        {
            output += pow;
        }

        input /= 10;
        pow *= 2;
    }

    return output;
}