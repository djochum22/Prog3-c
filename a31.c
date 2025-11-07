#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char tempName[25];
    int i = 0;

    struct Node
    {
        char name[25];
        struct Node *next;
    };

    struct Node *ptr, *temp; 
    struct Node newNode;

    ptr = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));

    while (scanf("%25s", tempName) != EOF)
    {
        strcpy(newNode.name, tempName);

        if (ptr = NULL)
        {
            ptr = (struct Node *)malloc(sizeof(struct Node));
            *ptr = newNode;
        }
        else
        {
            temp = ptr;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = &newNode;
        }
    }

    temp = ptr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr->next;

    temp = ptr;
    while (strcmp(argv[i], "\0"))
    {
        temp = temp->next;
        i++;
    }

    printf("%s is dran!", temp->name);

    free(ptr);
    free(temp);
    ptr = NULL;
    temp = NULL;
    
    return 0;
}