#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;
    union un{
        double d;
        unsigned int i[2];
    } x;

    sscanf(argv[1], "%lf", &x.d);

    for (i = 31; i >= 0; i--)
    {
        putchar((x.i[1] & (1u << i)) ? '1' : '0');
    }

    for (i = 31; i >= 0; i--)
    {
        putchar((x.i[0] & (1u << i)) ? '1' : '0');
    }

    putchar('\n');

    return 0;
}
