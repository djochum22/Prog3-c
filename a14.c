#include <stdio.h>

void generateSquare(unsigned input);

int main(void)
{
    unsigned input;

    do 
    {
        printf("Insert number: ");
        scanf("%u", &input);
    } while (!(input % 2) || input > 9);
    
    generateSquare(input);

    return 0;
}

void generateSquare(unsigned input)
{
    unsigned square[9][9] = {0};
    int i, j;
    int col = input / 2;
    int row = input / 2;

    for (i = 1; i <= input * input; i++)
    {
        if (square[row][col]) 
        {
            if (!square[(row + 1) % input][(col - 1 + input) % input])
            {
                row = (row + 1) % input;
                col = (col - 1 + input) % input;
            }
            else
            {
                row = (row + 2) % input;
            }
        }
    
        square[row][col] = i;
    }

    for (i = 0; i < input; i++)
    {
        for (j = 0; j < input; j++)
        {
            printf("%3u", square[i][j]);
        }
        printf("\n");
    }
}