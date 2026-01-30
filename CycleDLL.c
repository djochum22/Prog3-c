#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    struct nd *next;
    struct nd *prev;
    int value;
} ListEle;

ListEle *deleteList(ListEle *lst);
ListEle *insert(ListEle *lst, int);

int main(void)
{
    ListEle *lst;
    lst = insert(lst, 1);
    lst = insert(lst, 2);
    lst = insert(lst, 3);

    lst = deleteList(lst);
    if (lst != NULL)
    {
        printf("Not Cleared\n");
    }
    return 0;
}

ListEle *insert(ListEle *lst, int value)
{
    ListEle *new_node, *temp;
    new_node = malloc(sizeof(ListEle));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (lst == NULL)
    {
        return new_node;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;

    return new_node;
}
