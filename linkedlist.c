#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int value;
};

typedef struct Node *nodep;

nodep insertAt(nodep lst, int value, int idx);
nodep deleteAt(nodep lst, int idx);
nodep deleteList(nodep lst);
nodep insert(nodep lst, int value);
int sizeOf(nodep lst);
int valueAt(nodep lst, int idx);
int isEmpty(nodep lst);

int main(void)
{
    nodep lst = NULL;
    int i = 0;
    int size_n;

    for (i = 0; i < 5; i++)
    {
        lst = insert(lst, i);
    }

    size_n = sizeOf(lst);
    printf("Size: %d\n", size_n);

    lst = insertAt(lst, 6, 4);
    lst = deleteAt(lst, 0);
    lst = deleteAt(lst, 0);

    size_n = sizeOf(lst);

    printf("Size: %d\n", size_n);

    lst = deleteList(lst);

    if (isEmpty(lst))
    {
        printf("True");
    }

    return 0;
}

nodep insert(nodep lst, int value)
{
    nodep new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = lst;
    return new_node;
}

nodep insertAt(nodep lst, int value, int idx)
{
    nodep new_node, temp, temp_second;
    int i = 0;

    if (idx <= 0)
    {
        insert(lst, value);
    }

    new_node = malloc(sizeof(struct Node));
    new_node->value;

    if (lst == NULL)
    {
        return new_node;    
    }

    temp = lst;
    
    while(temp->next != NULL && i < idx)
    {
        i++;
        if (temp->next->next == NULL)
        {
            temp_second = temp;
        }

        temp = temp->next;
    }

    if (temp->next == NULL && i < idx)
    {
        new_node->next = NULL;
        temp->next = new_node;
        return lst;
    }

    if (temp_second != NULL)
    {
        temp_second->next = new_node;
        new_node->next = temp;
        return lst;
    }

    new_node->next = temp->next->next;
    temp->next = new_node;

    return lst;
}

nodep deleteAt(nodep lst, int idx)
{
    nodep temp, temp_free;
    int i = 0;

    if (lst == NULL)
    {
        return lst;
    }

    temp = lst;

    while(temp->next != NULL && i < idx)
    {
        i++;
        temp = temp->next;
    }

    temp_free = temp->next;
    temp->next = temp->next->next;
    
    free(temp_free);
    
    return lst;
}

nodep deleteList(nodep lst)
{
    nodep temp;

    if (lst == NULL)
    {
        return lst;
    }

    temp = lst;

    while(temp != NULL)
    {
        temp = temp->next;
        free(lst);
        lst = temp;
    }

    return lst;
}

int sizeOf(nodep lst)
{
    int size = 0;

    while(lst != NULL)
    {
        size++;
        lst = lst->next;
    }

    return size;
}

int valueAt(nodep lst, int idx)
{
    int i = 0;

    if (lst == NULL)
    {
        return 0;
    }

    while(lst->next != NULL && i < idx)
    {
        lst = lst->next;
    }

    return lst->value;
}

int isEmpty(nodep lst)
{
    if (lst == NULL)
        return 1;
    
    return 0;
}