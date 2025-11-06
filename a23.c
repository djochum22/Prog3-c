#include <stdio.h>
#include <ctype.h>
#include <string.h>

void soundex(const char s[], char res[]);

int main(void)
{
    char s[100];
    char res[7];

    fgets(s, 100, stdin);

    soundex(s, res);
    return 0;
}

void soundex(const char s[], char res[])
{
    const char *p = s;
    int i = 0;
    char c = *p;
    res[i++] = toupper(c);

    while(*p != '\0' && i < 6) 
    {
        c = *p++;
    
        c = toupper(*p);

        if (c == 'B' || c == 'F' || c == 'P' || c == 'V') 
        {
            if (res[i - 1] != '1') res[i++] = '1';
        }
        else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' ||  c == 'X' || c == 'Z')
        {
            if (res[i - 1] != '2') res[i++] = '2';
        }
        else if (c == 'D' || c == 'T')
        {
            if (res[i - 1] != '3') res[i++] = '3';
        }
        else if (c == 'L')
        {
            if (res[i - 1] != '4') res[i++] = '4';
        }
        else if (c == 'M' || c == 'N')
        {
            if (res[i - 1] != '5') res[i++] = '5';
        }
        else if (c == 'R')
        {
            if (res[i - 1] != '6') res[i++] = '6';
        }
    }

    while (i < 6) 
    {  
        res[i++] = '0';
    }

    res[i] = '\0';

    printf("%s\n", res);
}