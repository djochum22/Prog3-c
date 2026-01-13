#include <stdio.h>

int main(void)
{
    char input;
    
    printf("Text: ");
    while(scanf("%c", &input))
    {
        if (input >= 65 && input <= 90)
        {
            printf("%c", ((input + 13 - 65) % 26 + 65));
        }
        else if ((input >= 97 && input <= 122))
        {
            printf("%c", ((input + 13 - 97) % 26 + 97));
        }
        else
        {
            printf("%c", input);
        }
        
    }
    
    return 0;
}