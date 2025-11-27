typedef struct listEle
{
    char suchWort[25];
    char ersetzungWort[25];
    ListEle *nextEle;
} ListEle;

struct Fundstelle
{
    const char *stelleImSuchstring;
    ListEle *ersetzung;
};