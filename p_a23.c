#include <stdio.h>
#include <ctype.h>

void soundex(const char s[], char res[]);

int main(void) 
{
    char s[100];
    char res[7];

    while (scanf("%s", s) != EOF)
    {
        soundex(s, res);
    }

    return 0;
}

void soundex(const char s[], char res[])
{
    int i = 0;
    int last_app = 1;

    if (!isupper(s[0]))
    {
        res[0] = toupper(s[0]);
    }
    else
    {
        res[0] = s[0];
    }

    for (i = 1; i < 6; i++)
    {
        char c = toupper(s[i]);

        if (c == 'B' || c == 'F' || c == 'P' || c == 'V')
        {
            res[last_app] = '1';
            last_app += 1;
        }
        else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
        {
            res[last_app] = '2';
            last_app += 1;
        }
        else if (c == 'D' || c == 'T')
        {
            res[last_app] = '3';
            last_app += 1;
        }
        else if (c == 'L')
        {
            res[last_app] = '4';
            last_app += 1;
        }
        else if (c == 'M' || c == 'N')
        {
            res[last_app] = '5';
            last_app += 1;
        }
        else if (c == 'R')
        {
            res[last_app] = '6';
            last_app += 1;
        }
    }

    for (i = last_app; i < 6; i++)
    {
        res[i] = '0';
    }

    res[7] = '\0';

    printf("%s\n", res);
}