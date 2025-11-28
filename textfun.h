#ifndef TEXTFUN_H
#define TEXTFUN_H

typedef struct ListEle
{
    char suchWort[25];
    char ersetzungWort[25];
    struct ListEle *nextEle;
} ListEle;

struct Fundstelle
{
    char *stelleImSuchstring;
    ListEle *ersetzung;
};

void addPair(const char *such, const char *ersatz);
void clearList(void);
int replaceAll(char *s);

#endif