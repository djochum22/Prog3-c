#include <stdio.h>

int main(void)
{
    int nums[20];
    int i = 0, j, k;
    int input;

    while ((scanf("%d", &input) != EOF) && i < 20)
    {
        nums[i] = input;
        i++;
    }

    for (j = 0; j < i; j++)
    {
        for (k = j; k < i; k++)
        {
            if (nums[k] < nums[j])
            {
                input = nums[j];
                nums[j] = nums[k];
                nums[k] = input;
            }
        }
    }

    for (j = 0; j < i; j++)
    {
        printf("%d ", nums[j]);
    }

    return 0;
}

