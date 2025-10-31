#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char input;
    int i;
    char *alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    char *code[] = {"w", "g", "s", "n", "q", "c", "d", "v", "m", "e", "y", "l", "u", "z", "o", "a", "b", "h", "r", "j", "f", "k", "x", "i", "p", "t"};

    /* encode */
    if (strcmp(argv[1], "encrypt") == 0)
    {
        while (scanf("%c", &input) != EOF)
        {
            if (input >= 'a' && input <= 'z')
            {
                i = 0;
                while (input != *alphabet[i])
                {
                    i++;
                }
                printf("%c", *code[i]);
            }
            else
            {
                printf("%c", input);
            }
        }
    }

    /* decode */
    if (strcmp(argv[1], "decrypt") == 0)
    {
        while (scanf("%c", &input) != EOF)
        {
            if (input >= 'a' && input <= 'z')
            {
                i = 0;
                while (input != *code[i])
                {
                    i++;
                }
                printf("%c", *alphabet[i]);
            }
            else
            {
                printf("%c", input);
            }
        }
    }

    return 0;
}