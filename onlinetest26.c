#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lst
{
    char name[20];
    int alter;
    struct lst *next;
} ListEle;


ListEle *einfuegen(ListEle *lst, const char *n, int a);
int dopple(ListEle *lst, const char *n, int a);
void befreie(ListEle *lst);

int main(void)
{
    ListEle *lst = NULL;
    lst = einfuegen(lst, "Douglas", 20);
    lst = einfuegen(lst, "Mathi", 19);
    lst = einfuegen(lst, "Oliver", 23);
    lst = einfuegen(lst, "Julia", 36);
    lst = einfuegen(lst, "Douglas", 30);
    lst = einfuegen(lst, "Mathi", 20);

    printf("%d\n", dopple(lst, "Douglas", 30));
    printf("%d\n", dopple(lst, "Douglas", 19));

    befreie(lst);
    return 0;
}

ListEle *einfuegen(ListEle *lst, const char *n, int a)
{
    ListEle *new_node, *temp;

    new_node = malloc(sizeof(ListEle));
    new_node->alter = a;
    strcpy(new_node->name, n);
    new_node->next = NULL;

    if (lst == NULL)
    {
        return new_node;
    }

    temp = lst;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;

    return lst;
}

int dopple(ListEle *lst, const char *n, int a)
{
    ListEle *new_node;

    if (lst == NULL)
    {
        return 0;
    }

    new_node = malloc(sizeof(ListEle));
    new_node->alter = a;
    strcpy(new_node->name, n);
    new_node->next = NULL;

    while (lst != NULL)
    {
        if (lst->alter == a && strcmp(lst->name, n) == 0)
        {
            break;
        }
        lst = lst->next;
    }

    if (lst == NULL)
    {
        free(new_node);
        return 0;
    }

    new_node->next = lst->next;
    lst->next = new_node;

    return 1;
}

void befreie(ListEle *lst)
{
    ListEle *temp;

    if (lst == NULL)
    {
        return;
    }

    temp = lst;

    while (temp != NULL)
    {
        lst = lst->next;
        free(temp);
        temp = lst;
    }
}

