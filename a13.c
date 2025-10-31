#include <stdio.h>

int main(void)
{
    int nums[20];
    int input = 0;
    int i = 0;
    int j;
    int k;

    while ((scanf("%i", &input) != EOF) && i <= 19)
    {
        nums[i] = input;
        i++;
    }

    for (j = 0; j <= i; j++)
    {
        for (k = j; k <= i; k++)
        {
            if (nums[j] > nums[k])
            {
                input = nums[j];
                nums[j] = nums[k];
                nums[k] = input;
            }
        }
    }

    for (j = 0; j <= i; j++)
    {
        printf("%6i\n", nums[j]);
    }

    return 0;
}