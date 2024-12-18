//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAfter(struct node **start, int val, int r) {
    if (*start == NULL) {
        return;
    }
    struct node *newNode, *ptr, *prePtr;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    ptr = (*start)->next;
    prePtr = *start;

    while (prePtr != NULL && ptr != NULL && prePtr->data != r) {
        prePtr = ptr;
        ptr = ptr->next;
    }

    if (prePtr->data != r) {
        free(newNode);
        return;
    }
    else{
        prePtr->next = newNode;
        newNode->next = ptr;
    }
}

void insertBefore(struct node **start, int val, int r) {
    if (*start == NULL) {
        return;
    }
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if((*start)->data == r) {
        newNode->next = *start;
        *start = newNode;
        return;
    }
    struct node *ptr = (*start)->next, *prePtr = *start;

    while (ptr != NULL && ptr->data != r) {
        prePtr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->data != r) {
        free(newNode);
        return;
    }
    else {
        prePtr->next = newNode;
        newNode->next = ptr;
    }
}

void insertNodeEnd(struct node **head, int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void displayList(struct node *start) // display sublist
{
    struct node *ptr = start; // assign *ptr to pointer to head of the list

    if (ptr == NULL) // if ptr is null
    {
        printf("Invalid");
        return;
    }

    while (ptr != NULL) // loop until ptr is null
    {
        printf("%d ", ptr->data); // print value of current node
        ptr = ptr->next;          // move ptr to next node
    }
}

void freeList(struct node *head)
{
    struct node *current = head;
    struct node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main () {
    struct node *start = NULL;
    int nodenum, data, v, r;
    char letter;

    scanf("%d", &nodenum);

    for (int i = 0; i < nodenum; i++) {
        scanf("%d", &data);
        insertNodeEnd(&start, data);
    }

    while (letter != 'E') {
        scanf(" %c", &letter);

        if (letter == 'E') {
            break;
        }

        if(letter == 'A') {
            scanf("%d %d", &r, &v);
            insertAfter(&start ,v ,r);
        }
        else if(letter == 'B') {
            scanf("%d %d", &r, &v);
            insertBefore(&start ,v ,r);
        }

    }

    displayList(start);

    // Free the allocated memory
    freeList(start);

    return 0;
}
