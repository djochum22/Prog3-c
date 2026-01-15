#include <stdio.h>
#include <string.h>

void encrypt(char c);
void decrypt(char c);

char abc_de[] = "abcdefghijklmnopqrstuvwxyz";
char abc_en[] = "wgsnqcdvmeyluzoabhrjfkxipt"; 

int main(int argc, char *argv[])
{
    char input;

    while (scanf("%c", &input) != EOF) {
        if (strcmp("encrypt", argv[1]) == 0)
        {
            encrypt(input);
        }
        else
        {
            decrypt(input);
        }
    }
    
    return 0;
}

void encrypt(char c)
{
    int i = 0;
    int index = -1;

    for (i = 0; i < strlen(abc_de); i++)
    {
        if (c == abc_de[i])
        {
            index = i;
        }
    }
    
    if (index == -1)
    {
        printf("%c", c);
    }
    else
    {
        printf("%c", abc_en[index]);
    }
}

void decrypt(char c)
{
    int i = 0;
    int index = -1;

    for (i = 0; i < strlen(abc_en); i++)
    {
        if (c == abc_en[i])
        {
            index = i;
        }
    }
    
    if (index == -1)
    {
        printf("%c", c);
    }
    else
    {
        printf("%c", abc_de[index]);
    }
}