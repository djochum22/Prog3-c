#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char tempName[26];
    int i = 0;

    struct Node
    {
        char name[26];
        struct Node *next;
    };

    struct Node *ptr, *temp, *newNode, *start;
    
    ptr = NULL;
    temp = NULL;
    newNode = NULL;
    start = NULL;

    while (scanf("%25s", tempName) != EOF)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->name, tempName);
        newNode->next = NULL;

        if (ptr == NULL)
        {
            ptr = newNode;
        }
        else
        {
            if (ptr == NULL)
            {
                return 0;
            }

            temp = ptr;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    temp = ptr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;

    temp = ptr;

    for (i = 2; i < argc; i++)
    {
        temp = temp->next;
    }

    printf("%s is dran!", temp->name);

    temp = ptr->next;
    
    while (temp != ptr)
    {
        start = temp->next;
        free(temp);
        temp = start;
    }

    free(ptr);

    ptr = NULL;
    temp = NULL;
    
    return 0;
}