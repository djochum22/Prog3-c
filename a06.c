#include <stdio.h>

char letter;

int main(void)
{
    printf("Enter character: ");
    scanf("%c", &letter);

    if (letter % 65 >= 1) {
        letter = ((letter + 13) / 'A' + 'A');
    }
    printf("%c", letter);
    
}