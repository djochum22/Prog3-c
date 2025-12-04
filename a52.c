#include "textfun.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    char s[200];
    int number_of_replaced;

    for (i = 1; i < argc; i++)
    {
        char *token = strtok(argv[i], "=");        
        char *key = strtok(NULL, "=");
        
        addPair(token, key);
    }

    
    fgets(s, 200, stdin);
    number_of_replaced = replaceAll(s);
    clearList();

    printf("%d", number_of_replaced);

    return 0;
}