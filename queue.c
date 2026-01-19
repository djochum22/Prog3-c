#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int num;
};

typedef struct Node *nodep;

nodep enqueue(nodep lst, int value);
nodep dequeue(nodep lst);
nodep getFront(nodep lst);
nodep getRear(nodep lst);
int size(nodep lst);
int isEmpty(nodep lst);

int main(void)
{
    nodep lst = NULL;
    int i = 0;

    for(i = 0; i < 5; i++)
    {
        lst = enqueue(lst, i);
    }

    if (lst != NULL)
    {
        printf("Front: %d\n", getFront(lst)->num);
        printf("Rear: %d\n", getRear(lst)->num);

        printf("Size: %d\n", size(lst));

        for(i = 0; i < 5; i++)
        {
            lst = dequeue(lst);
        }
    }

    if (isEmpty(lst) == 1)
    {
        printf("Is empty\n");
    }
    else
    {
        printf("Is not empty\n");
    }

    return 0;
}

nodep enqueue(nodep lst, int value)
{
    nodep new_node = malloc(sizeof(struct Node));
    new_node->num = value;
    new_node->next = lst;
    return new_node;
}

nodep dequeue(nodep lst)
{
    nodep temp;

    if (lst == NULL)
    {
        return NULL;
    }

    if (lst->next == NULL)
    {
        free(lst);
        return NULL;
    }

    temp = lst;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return lst;
}

nodep getFront(nodep lst)
{
    return lst;
}

nodep getRear(nodep lst)
{
    if (lst == NULL)
    {
        return NULL;
    }

    if (lst->next == NULL)
    {
        return lst;
    }

    while(lst->next != NULL)
    {
        lst = lst->next;
    }

    return lst;
}

int size(nodep lst)
{
    int output = 0;

    while(lst != NULL)
    {
        output++;
        lst = lst->next;
    }

    return output;
}

int isEmpty(nodep lst)
{
    if (lst == NULL)
        return 1;
    
    return 0;
}