#include <stdio.h>

int main(void)
{
    char letter = NULL;
    while (letter != 13)
    {
        printf("Enter character: ");
        scanf("%c", &letter);

        if (letter >= 'A' && letter <= 'Z') 
        {
            letter = ((letter + 13) % 'Z' + 'A');
        }
        else
        {
            letter = ((letter + 13) % 'z' + 'a');
        }
        printf("%c", letter);
    }
}