#include <stdio.h>

int main(void)
{
    int n,i,j = 0;
    int matrix[9][9];
    int height = 0;
    int length = 0;

    while ((n % 2 != 1) && n <= 9)
    {
        printf("Size: ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }

    height = n/2;
    length = n/2;

    matrix[height][length] = 1;

    for (i = 2; i <= (n * n); i++)
    {
        if (matrix[(height + 1) % n][(length - 1 + n) % n] == 0)
        {
            height = (height + 1) % n;
            length = (length - 1 + n) % n;
            
            matrix[height][length] = i;
        } else {
            matrix[(height += 2) % n][length] = i;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}