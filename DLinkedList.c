#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int value;
    int key;
    struct Node *prev;
};

typedef struct Node *nodep;

nodep insert(nodep lst, int value, int key);
nodep deleteKey(nodep lst, int key);
nodep delList(nodep lst);
int size(nodep lst);
int isEmpty(nodep lst);

int main(void)
{
    nodep lst = NULL;
    lst = insert(lst, 3, 5);
    lst = insert(lst, 2, 3);
    lst = insert(lst, 10, 4);
    lst = insert(lst, 12, 6);

    printf("Size: %d\n", size(lst));

    lst = deleteKey(lst, 3);
    lst = deleteKey(lst, 1);

    printf("Size: %d\n", size(lst));

    lst = delList(lst);

    if (isEmpty(lst))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    
    return 0;
}

nodep insert(nodep lst, int value, int key)
{
    nodep temp, new_node;
    new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->key = key;

    if (lst == NULL)
    {
        return new_node;
    }

    temp = lst;

    if (key < temp->key)
    {
        new_node->next = temp;
        temp->prev = new_node;
        new_node->prev = NULL;
        return new_node;
    }

    while(temp->next != NULL && temp->next->key < key)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;
        return lst;
    }

    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;

    return lst;
}

nodep deleteKey(nodep lst, int key)
{
    nodep temp;

    if (lst == NULL)
    {
        return lst;
    }
    
    temp = lst;

    while(temp != NULL && key != temp->key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return lst;
    }

    if (temp->prev == NULL)
    {
        lst = temp->next;
        lst->prev = NULL;
        free(temp);
    }

    while(temp->key == key)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        return lst;
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        free(temp);
    }

    return lst;
}

nodep delList(nodep lst)
{
    nodep temp;

    if (lst == NULL)
    {
        return lst;
    }

    temp = lst;

    while (lst != NULL)
    {
        lst = lst->next;
        free(temp);
        temp = lst;
    }

    return lst;
}

int size(nodep lst)
{
    int size = 0;
    
    while(lst != NULL)
    {
        size++;
        lst = lst->next;
    }

    return size;
}

int isEmpty(nodep lst)
{
    if (lst == NULL)
        return 1;
    
    return 0;
}