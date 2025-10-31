#include <stdio.h>

int main(void)
{
    char letter = '\0';

    do
    {
        scanf("%c", &letter);

        if (letter >= 'A' && letter <= 'Z') 
        {
            letter = ((letter - 'A' + 13) % 26 + 'A');
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            letter = ((letter - 'a' + 13) % 26 + 'a');
        }

        printf("%c", letter);
    } while (letter != 10);

    return 0;
}