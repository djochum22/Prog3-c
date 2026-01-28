#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n {
    struct n *next;
    char zahl[9]; 
} Node;

int vergleiche(Node *a, Node *b);
void tausche(Node *a);
int bubbleOnce(Node *liste);
void sortiere(Node *liste);

void printList(Node *k) {
    while (k) {
        printf("%s ", k->zahl);
        k = k->next;
    }
    printf("\n");
}

int main(void)
{
    Node *l1;
    Node *l2;
    Node *l3;
    Node *l4;
    Node *l5;
    Node *l6;
    Node *l7;
    Node *l8;
    Node *l9;
    int swaps;

    /* ---------- Test 1: Empty list ---------- */
    printf("Test 1: Empty list\n");
    l1 = NULL;
    sortiere(l1);
    printList(l1);
    printf("\n");

    /* ---------- Test 2: One element ---------- */
    printf("Test 2: One element\n");
    l2 = malloc(sizeof(Node));
    strcpy(l2->zahl, "5");
    l2->next = NULL;

    sortiere(l2);
    printList(l2);
    printf("\n");

    /* ---------- Test 3: Already sorted ---------- */
    printf("Test 3: Already sorted\n");
    l3 = malloc(sizeof(Node));
    l3->next = malloc(sizeof(Node));
    l3->next->next = malloc(sizeof(Node));
    l3->next->next->next = NULL;

    strcpy(l3->zahl, "1");
    strcpy(l3->next->zahl, "2");
    strcpy(l3->next->next->zahl, "3");

    sortiere(l3);
    printList(l3);
    printf("\n");

    /* ---------- Test 4: Reverse order ---------- */
    printf("Test 4: Reverse order\n");
    l4 = malloc(sizeof(Node));
    l4->next = malloc(sizeof(Node));
    l4->next->next = malloc(sizeof(Node));
    l4->next->next->next = NULL;

    strcpy(l4->zahl, "9");
    strcpy(l4->next->zahl, "5");
    strcpy(l4->next->next->zahl, "1");

    sortiere(l4);
    printList(l4);
    printf("\n");

    /* ---------- Test 5: Assignment example ---------- */
    printf("Test 5: Assignment example\n");
    l5 = malloc(sizeof(Node));
    l5->next = malloc(sizeof(Node));
    l5->next->next = malloc(sizeof(Node));
    l5->next->next->next = NULL;

    strcpy(l5->zahl, "10");
    strcpy(l5->next->zahl, "2");
    strcpy(l5->next->next->zahl, "5");

    sortiere(l5);
    printList(l5);
    printf("\n");

    /* ---------- Test 6: Equal values ---------- */
    printf("Test 6: Equal values\n");
    l6 = malloc(sizeof(Node));
    l6->next = malloc(sizeof(Node));
    l6->next->next = malloc(sizeof(Node));
    l6->next->next->next = NULL;

    strcpy(l6->zahl, "7");
    strcpy(l6->next->zahl, "7");
    strcpy(l6->next->next->zahl, "7");

    sortiere(l6);
    printList(l6);
    printf("\n");

    /* ---------- Test 7: Multi-digit numbers ---------- */
    printf("Test 7: Multi-digit numbers\n");
    l7 = malloc(sizeof(Node));
    l7->next = malloc(sizeof(Node));
    l7->next->next = malloc(sizeof(Node));
    l7->next->next->next = malloc(sizeof(Node));
    l7->next->next->next->next = NULL;

    strcpy(l7->zahl, "100");
    strcpy(l7->next->zahl, "20");
    strcpy(l7->next->next->zahl, "3");
    strcpy(l7->next->next->next->zahl, "45");

    sortiere(l7);
    printList(l7);
    printf("\n");

    /* ---------- Test 8: Leading zeros ---------- */
    printf("Test 8: Leading zeros\n");
    l8 = malloc(sizeof(Node));
    l8->next = malloc(sizeof(Node));
    l8->next->next = malloc(sizeof(Node));
    l8->next->next->next = malloc(sizeof(Node));
    l8->next->next->next->next = NULL;

    strcpy(l8->zahl, "001");
    strcpy(l8->next->zahl, "01");
    strcpy(l8->next->next->zahl, "1");
    strcpy(l8->next->next->next->zahl, "0002");

    sortiere(l8);
    printList(l8);
    printf("\n");

    /* ---------- Test 9: bubbleOnce ---------- */
    printf("Test 9: bubbleOnce\n");
    l9 = malloc(sizeof(Node));
    l9->next = malloc(sizeof(Node));
    l9->next->next = malloc(sizeof(Node));
    l9->next->next->next = NULL;

    strcpy(l9->zahl, "4");
    strcpy(l9->next->zahl, "2");
    strcpy(l9->next->next->zahl, "3");

    swaps = bubbleOnce(l9);
    printf("Swaps: %d\n", swaps);
    printList(l9);
    printf("\n");

    return 0;
}

int vergleiche(Node *a, Node *b)
{
    int wert_a;
    int wert_b;
    int answer;

    wert_a = atoi(a->zahl);
    wert_b = atoi(b->zahl);

    if (wert_a < wert_b)
        answer = -1;
    else if (wert_a == wert_b)
        answer = 0;
    else
        answer = 1;

    return answer;
}

void tausche(Node *a)
{
    char *nachbar_wert = malloc(sizeof(a->zahl));
    
    if (a->next != NULL)
    {
        strcpy(nachbar_wert, a->next->zahl);

        if (nachbar_wert != NULL)
        {
            strcpy(a->next->zahl, a->zahl);
            strcpy(a->zahl, nachbar_wert);
        }
    }

    free(nachbar_wert);
}

int bubbleOnce(Node *liste)
{
    Node *temp;
    int swaps = 0;

    if (liste == NULL)
    {
        return swaps;
    }

    temp = liste;

    while (temp->next != NULL)
    {
        if (vergleiche(temp, temp->next) == 1)
        {
            tausche(temp);
            swaps++;
        }

        temp = temp->next;
    }

    return swaps;
}

void sortiere(Node *liste)
{
    if (liste == NULL)
    {
        return;
    }

    while (bubbleOnce(liste) != 0) {}
}