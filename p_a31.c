#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[25];
    struct Node
    {
        struct Node *next;
        char name[25];
    };

    struct Node *p, *new_node;
    
    /* not certain if I need & or not in scanf swear down didn't need it last time */
    while(scanf("%s", name) != EOF)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
    }
    return 0;
}