#include <stdio.h>

int main(void)
{
    /* poiner a and pointer b are referencing NULL. v is a vektor of size 17. c is a pointer that is also referencing NULL */
    char *a = NULL;
    int *b = NULL, v[17];
    double *c = NULL;

    /* we are printing the addresses all of the pointers plus the n bytes for the number that is added after the address */
    printf("\n%ld %ld %ld\n%ld %ld %ld\n\n",
           (long)(a + 1), (long)(b + 1), (long)(c + 1),
           (long)(a + 5), (long)(b + 7), (long)(c + 17));

    /* here we are printing the first the address of v so the beginning of the vektor , following we are printing the address of the address of v[0] and then the address of v[10] */
    printf("%p %p %p\n", (void *)v, (void *)&v[0], (void *)&v[10]);

    return 0;
}