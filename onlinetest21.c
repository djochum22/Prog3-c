#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct le
{
    int anzahl;
    char name[25];
    struct le *next;
} ListEle;

ListEle *hinzufuege(ListEle *liste, const char *name);
ListEle *korrigiere(ListEle *liste, const char *altname, const char *neuname);
ListEle *suche(ListEle *liste, const char *name);

void printListe(ListEle *l)
{
    while (l != NULL)
    {
        printf("[%s:%d] -> ", l->name, l->anzahl);
        l = l->next;
    }
    printf("NULL\n");
}

int main(void)
{
    ListEle *liste;
    ListEle *p;

    liste = NULL;

    printf("TEST 1: Search in empty list\n");
    p = suche(liste, "Max");
    printf("Expected: NULL | Got: %s\n\n", p == NULL ? "NULL" : p->name);

    printf("TEST 2: Add first element\n");
    liste = hinzufuege(liste, "Jonathan");
    printListe(liste);
    printf("Expected: [Jonathan:1]\n\n");

    printf("TEST 3: Add second element\n");
    liste = hinzufuege(liste, "Friedbert");
    printListe(liste);
    printf("Expected: Jonathan -> Friedbert\n\n");

    printf("TEST 4: Add duplicate name\n");
    liste = hinzufuege(liste, "Jonathan");
    printListe(liste);
    printf("Expected: Jonathan:2 -> Friedbert:1\n\n");

    printf("TEST 5: Add third element\n");
    liste = hinzufuege(liste, "Johanna");
    printListe(liste);
    printf("Expected: Jonathan -> Friedbert -> Johanna\n\n");

    printf("TEST 6: Rename existing element\n");
    liste = korrigiere(liste, "Friedbert", "Purzel");
    printListe(liste);
    printf("Expected: Jonathan -> Purzel -> Johanna\n\n");

    printf("TEST 7: Rename non-existing element\n");
    liste = korrigiere(liste, "Nobody", "X");
    printListe(liste);
    printf("Expected: unchanged\n\n");

    printf("TEST 8: Rename to existing name (must fail)\n");
    liste = korrigiere(liste, "Purzel", "Jonathan");
    printListe(liste);
    printf("Expected: unchanged\n\n");

    printf("TEST 9: Search existing element\n");
    p = suche(liste, "Jonathan");
    printf("Expected: Jonathan | Got: %s\n\n", p != NULL ? p->name : "NULL");

    printf("TEST 10: Search non-existing element\n");
    p = suche(liste, "Eingangstuer");
    printf("Expected: NULL | Got: %s\n\n", p == NULL ? "NULL" : p->name);

    return 0;
}

ListEle *hinzufuege(ListEle *liste, const char *name)
{
    ListEle *temp, *new_node;

    new_node = malloc(sizeof(ListEle));
    new_node->anzahl = 1;
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (liste == NULL)
    {
        return new_node;
    }

    temp = liste;

    while (temp->next != NULL && strcmp(temp->name, name) != 0)
    {
        temp = temp->next;
    }

    if (strcmp(temp->name, name) == 0)
    {
        temp->anzahl++;
        return liste;
    }

    temp->next = new_node;
    return liste;
}

ListEle *korrigiere(ListEle *liste, const char *altname, const char *neuname)
{
    ListEle *temp = liste;

    while (temp != NULL && strcmp(temp->name, altname) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return liste;
    }

    if (strcmp(temp->name, altname) == 0)
    {
        strcpy(temp->name, neuname);
    }

    return liste;
}

ListEle *suche(ListEle *liste, const char *name)
{
    while (liste != NULL && strcmp(liste->name, name) != 0)
    {
        liste = liste->next;
    }

    return liste;
}