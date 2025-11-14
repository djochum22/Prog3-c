#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    struct Node *prev;
    char *inhalt;
};

typedef struct Node *nodep;

void printList(nodep lst);
nodep insertAt(nodep lst, int pos, char *inhalt);
nodep deleteAt(nodep lst, int pos);
void freeAll(nodep lst);

int main(void)
{
    nodep lst = NULL;

    lst = insertAt(lst, 0, "hi");
    lst = insertAt(lst, -1, "last");
    lst = insertAt(lst, 0, "beginning");
    lst = insertAt(lst, 2, "middle");
    lst = insertAt(lst, 1231, "large number");

    lst = deleteAt(lst, 0);
    lst = deleteAt(lst, 3);

    printList(lst);

    if (lst != NULL)
    {
        freeAll(lst);
    }

    return 0;
}

void printList(nodep lst)
{
    while (lst != NULL)
    {
        printf("%p: %s\n", (void *)lst, lst->inhalt);
        lst = lst->next;
    }
}

nodep insertAt(nodep lst, int pos, char *inhalt)
{
    int i = 0;
    nodep newNode = (struct Node *)malloc(sizeof(struct Node));
    nodep temp = lst;

    newNode->inhalt = inhalt;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (lst == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    else if (pos == 0)
    {
        newNode->next = lst;
        newNode->prev = NULL;
        lst->prev = newNode;
        return newNode;
    }
    else
    {
        while (i != pos && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (i == pos)
        {
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
        else
        {
            newNode->prev = temp;
            newNode->next = NULL;
            temp->next = newNode;
        }
        
        
    }

    return lst;
}

nodep deleteAt(nodep lst, int pos)
{
    int i = 0;
    nodep temp = lst;
    
    if (lst == NULL)
    {
        return lst;
    }

    if (lst->next == NULL && pos == 0)
    {
        free(lst);
        return NULL;
    }

    if (pos == 0)
    {
        temp = lst->next;
        lst->next->prev = NULL;
        lst->next = NULL;
        free(lst);
        return temp;
    }
    else
    {
        while (i != pos && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        
        if (i != pos)
        {
            return lst;
        }

        if (i == pos && temp->next != NULL)
        {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp->prev = NULL;
            temp->next = NULL;
            free(temp);
        }
        else if (i == pos)
        {
            temp->prev->next = NULL;
            temp->prev = NULL;
            free(temp);
        }
    }
    return lst;
}

void freeAll(nodep lst)
{
    nodep temp = lst;

    while (lst->next != NULL)
    {
        temp = lst;
        lst = lst->next;
        free(temp);
    }

    free(lst);
}