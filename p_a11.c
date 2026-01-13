#include <stdio.h>

int main(void)
{
    float input;
    double last_num;
    double answer = 0;

    printf("Input: ");
    scanf("%f", &input);

    answer = (1 + input) / 2;
    do
    {
        last_num = answer;
        answer = (last_num + (input / last_num)) / 2; 
    } while (last_num - answer >= 0.0000001);
    
    printf("Answer: %10.4f\n", answer);
}