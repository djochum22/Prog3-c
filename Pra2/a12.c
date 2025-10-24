#include <stdio.h>

void writebit(unsigned z);
unsigned readbit(void);

int main(void)
{
    int a, b;

    
    printf("A: ");
    scanf("%d", &a);

    printf("B: ");
    scanf("%d", &b);
    */
   readbit();
}

void writebit(unsigned z)
{
    int i = 0;

    for (i = 15; i >= 0; i--)
    {
        printf("%d", (z & 1 << i) != 0);
    }
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
        output += ((z & 1 << i) != 0);
    }

    return output;
}