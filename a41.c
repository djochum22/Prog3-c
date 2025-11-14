#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int k = 1;
    int count = 0;
    char zeichen[200];
    char output[200];
    char *words[50];
    char *tok = NULL;

    scanf("%s", &zeichen);

    strcpy(output, zeichen);
    tok = strtok(zeichen, " ");

    while (tok != NULL)
    {
        words[i++] = tok;
        tok = strtok(NULL, " ");
        count++;
    }
    
    for (i = 1; i < argc; i++)
    {
        for (j = 0 ; j < count; j++)
        {
            if (strcmp(words[j], argv[i]) == 0)
            {
                while (isalpha(words[j][k]))
                {
                    words[j][k] = '*';
                    k++;
                }
                k = 0;
            }
        }
    }

    i = 0;
    j = 0;
    while (output[i] != '\0')
    {
        if (isalpha(output[i]))
        {
            output[i] = words[j][i];
            j++;
        }
        i++;

    }

    printf("%s", output);
    
    return 0;
}