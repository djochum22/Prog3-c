#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    char zeichen[200];
    char *ptr;

    fgets(zeichen, 200, stdin);
    
    for (i = 1; i < argc; i++)
    {
        ptr = strstr(zeichen,argv[i]);
        while (ptr != NULL)
        {

            for (j = 1; j < strlen(argv[i]); j++)
            {
                if (ptr[j] != '\0' && ptr[j] != ' ')
                {
                    ptr[j] = '*';
                }
            }

            ptr = strstr(ptr + 1, argv[i]);
        }
    }

    printf("%s", zeichen);
    
    return 0;
}