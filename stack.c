#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int num;
};

typedef struct Node *nodep;

nodep top(nodep lst);
nodep pop(nodep lst);
nodep push(nodep lst, int value);
int sizeOf(nodep lst);

int main(void)
{
    nodep lst = NULL;
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        lst = push(lst, i);
    }

    printf("Size: %d\n", sizeOf(lst));

    printf("Top: %d\n", top(lst)->num);

    for (i = 0; i < 5; i++)
    {
        lst = pop(lst);
    }

    return 0;
}

nodep top(nodep lst)
{
    if (lst == NULL)
        return NULL;

    return lst;
}

nodep pop(nodep lst)
{
    nodep temp;

    if (lst == NULL)
        return NULL;

    temp = lst->next;
    free(lst);
    return temp;
}

nodep push(nodep lst, int value)
{
    nodep new_node = malloc(sizeof(struct Node));
    new_node->num = value;
    new_node->next = lst;
    return new_node;
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
