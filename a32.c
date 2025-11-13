#include <stdio.h>

void printList(nodep lst);
nodep insertAt(nodep lst, int pos, char *inhalt);
nodep deleteAt(nodep lst, int pos);

struct Node
{
    struct Node *next;
    struct Node *prev;
    char *inhalt;
};

typedef struct Node *nodep;

int main(void)
{
    nodep lst = NULL;
    lst->inhalt = NULL;
    lst->next = NULL;
    lst->prev = NULL;
}

void printList(nodep lst)
{
    while (lst != NULL)
    {
        printf("%p: %s\n", lst, lst->inhalt);
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