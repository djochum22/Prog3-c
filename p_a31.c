#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0;
    char name[26];
    struct Node
    {
        struct Node *next;
        char name[26];
    };

    struct Node *p, *new_node, *temp;

    p = NULL;
    new_node = NULL;
    temp = NULL;
    
    while(scanf("%25s", name) != EOF)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        strcpy(new_node->name, name);
        new_node->next = NULL;

        if (p == NULL)
        {
            p = new_node;
        }
        else
        {
            if (p == NULL)
            {
                continue;
            }
            else
            {
                temp = p;
                
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = new_node;
                new_node->next = NULL;
            }
        }
    }

    temp = p;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p;

    temp = p;

    /* because we want it to be the last person in the for loop */
    for (i = 2; i < argc; i++)
    {
        temp = temp->next;
    }

    printf("It's %s turn\n", temp->name);

    new_node = p->next;
    temp = new_node;

    while (new_node != p)
    {
        new_node = new_node->next;
        free(temp);
        temp = new_node;
    }

    free(p);
    
    p = NULL;
    temp = NULL;

    return 0;
}