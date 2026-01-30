#include <string.h>
#include <stdio.h>

void schwabify(char *input, char output[])
{
    int o = 0;
    int i = 0;

    while (input[i] != '\0')
    {
        if (input[i] == '.')
        {
            strcat(&output[o], ", woisch?");
            o += 9;
            i++;
        }
        else if (strncmp(&input[i], "halt", 4) == 0)
        {
            strcat(&output[o], "heb");
            o += 3;
            i += 4;
        }
        else if (strncmp(&input[i], "ist", 3) == 0)
        {
            strcat(&output[o], "isch");
            o += 4;
            i += 3;
        }
        else
        {
            output[o++] = input[i++];
        }
    }
    output[o] = '\0';
    printf("%s\n", output);

}

int main(void)
{  
    char output[100];
    schwabify("Das ist interessant.", output);
    return 0;
}