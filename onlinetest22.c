#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void komprimiere(const char *ein, char *aus);
void entprelle(const char *ein, char *aus);
void expandiere(const char *ein, char *aus);

int main(void)
{
    char answer[50];
    /*
    komprimiere("Internationalization", answer);
    printf("%s\n", answer);

    entprelle("2022", answer);
    printf("%s\n", answer);
    */

    expandiere("I18n", answer);
    printf("%s\n", answer);

    return 0;
}

void komprimiere(const char *ein, char *aus)
{
    int i = 0,j = 0;
    char num[10];
    int len;

    if (ein == NULL)
    {
        aus[0] = '\0';
        return;
    }

    len = strlen(ein);

    if (len < 4 || !isalpha(ein[0]))
    {
        aus[0] = '\0';
        return;
    }

    aus[i] = ein[i];
    i++;
    sprintf(num,"%d", len - 2);
    
    while(num[j] != '\0')
    {
        aus[i] = num[j];
        i++;
        j++;
    }

    aus[i++] = ein[len - 1];
    aus[i] = '\0';
}

void entprelle(const char *ein, char *aus)
{
    char last;
    int i = 0;
    int j = 0;
    if (ein == NULL)
    {
        aus[0] = '\0';
        return;
    }

    last = ein[i];
    aus[j] = ein[i];
    i++;
    j++;
    while (i < strlen(ein))
    {
        if (ein[i] != last)
        {
            aus[j] = ein[i];
            last = ein[i];
            j++;
        }
        i++;
    }

    aus[j] = '\0';
}

void expandiere(const char *ein, char *aus)
{
    char ersatz[] = "bla";
    int len;
    int i = 0, j = 0;
    int puffer;

    if (ein == NULL)
    {
        aus[0] = '\0';
        return;
    }

    if (strlen(ein) < 4 || !isdigit(ein[1]))
    {
        aus[0] = '\0';
        return;
    }

    len = atoi(ein + 1);

    aus[0] = ein[0];
    puffer = len % 3;

    for (i = 0; i < (int)((len - 2) / 3); i++)
    {
        strcat(aus, ersatz);
    }

    j = strlen(aus);
    i = j;
    while (i < (j + puffer))
    {
        aus[i] = ersatz[i - j];
        i++;
    }
    aus[i++] = ein[strlen(ein) - 1];
    aus[i] = '\0';
}