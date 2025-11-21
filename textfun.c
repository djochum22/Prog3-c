#include <stdlib.h>
#include "textfun.h"

ListEle *wordList = NULL;

void addPair(const char *such, const char *ersatz)
{
    ListEle *newEle = (ListEle *)malloc(sizeof(ListEle));

    if (wordList == NULL)
    {
        wordList = newEle;
    }
    else
    {
        
    }
}