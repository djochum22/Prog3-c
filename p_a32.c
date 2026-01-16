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

int main(void)
{
    nodep lst = NULL;
    lst = insertAt(lst, 0, "hi");
    lst = insertAt(lst, 0, "hi new");
    lst = insertAt(lst, -1, "Hi Last");
    printList(lst);
    return 0;
}

void printList(nodep lst)
{
    while (lst != NULL)
    {
        printf("%p\n", (void *)lst);
        printf("%s\n", lst->inhalt);
        lst = lst->next;
    }
}

nodep insertAt(nodep lst, int pos, char *inhalt)
{
    int i = 0;
    nodep temp = lst;
    nodep new_node = (nodep)malloc(sizeof(nodep));

    new_node->inhalt = inhalt;

    if (lst == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        return new_node;
    }

    if (pos == -1)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->prev = temp;
        new_node->next = NULL;

        temp->next = new_node;
    }
    else if (pos == 0)
    {
        new_node->prev = NULL;
        new_node->next = lst;
        
        lst->prev = new_node;

        return new_node;
    }
    else
    {
        while (i < pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            return lst;
        }

        new_node->next = temp;
        new_node->prev = temp->prev;
        
        temp->prev->next = new_node;
        temp->prev = new_node;
    }

    return lst;
}