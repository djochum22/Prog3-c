#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char input[201];
    int i = 0;
    int j = 1;

    char *such_string;

    while (fgets(input, 200, stdin) != NULL)
    {
        for (i = 1; i < argc; i++)
        {
            such_string = strstr(input, argv[i]);

            if (such_string == NULL)
            {
                continue;
            }
            else
            {
                while (isalpha(such_string[j]) && such_string[j] != '\0' && such_string[j] == argv[i][j])
                {
                    such_string[j] = '*';
                    j++;
                }
                j = 1;
            }
        }
        
        printf("%s\n", input);
    }


    return 0;
}