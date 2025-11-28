#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "textfun.h"

ListEle *wordList = NULL;

void addPair(const char *such, const char *ersatz)
{
    ListEle *newEle = (ListEle *)malloc(sizeof(ListEle));
    ListEle *temp;

    if (wordList == NULL)
    {
        wordList = newEle;
    }
    else
    {
        temp = wordList;
        while (temp->nextEle != NULL)
        {
            temp = temp->nextEle;
        }

        temp->nextEle = newEle;
    }
}

void clearList(void)
{
    ListEle *temp = wordList;

    if (wordList == NULL) 
    {
        return;
    }

    while (temp->nextEle != NULL)
    {   wordList = temp;
        free(wordList);
        temp = temp->nextEle;
    }

    free(temp);
}

struct Fundstelle find(const char *s)
{
    struct Fundstelle fundstelle = {NULL, NULL};

    ListEle *temp = wordList;
    char *ptr = NULL;

    while ((ptr = strstr(s, temp->suchWort)) == NULL && temp->nextEle != NULL)
    {
        temp = temp->nextEle;
    }

    if (ptr != NULL)
    {
        fundstelle.stelleImSuchstring = ptr;
        fundstelle.ersetzung = temp;
    }

    return fundstelle;
}

int replaceAll(char *s)
{
    int replaceCounter = 0;
    
    struct Fundstelle fundstelle;
    char *pos;

    fundstelle = find(s);

    while(fundstelle.stelleImSuchstring != NULL)
    {
        int newLen = strlen(fundstelle.ersetzung->ersetzungWort);
        int oldLen = strlen(fundstelle.ersetzung->suchWort);
        pos = fundstelle.stelleImSuchstring;

        memmove(pos + newLen, pos + oldLen, strlen(pos + oldLen) + 1);
        memcpy(pos,fundstelle.ersetzung->ersetzungWort, newLen);
        replaceCounter++;
        fundstelle = find(s);
    }

    printf("%s", s);

    return replaceCounter;
}