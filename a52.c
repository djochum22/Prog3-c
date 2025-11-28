#include "textfun.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    char s[200];
    int number_of_replaced;

    for (i = 0; i < argc; i++)
    {
        char *token[2] = strtok(argv[i], "=");

        while (token != NULL)
        {
            token[i%2] = strtok(NULL, "=");
        }
        
        addPair(token[0], token[1]);
    }

    
    fgets(s, 200, stdin);
    number_of_replaced = replaceAll(s);
    clearList();

    printf("%d", number_of_replaced);

    return 0;
}