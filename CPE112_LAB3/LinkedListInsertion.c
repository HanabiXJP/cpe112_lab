//66070501038 PHANTHACH JIAMJARUSCHOT

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void displayList(struct node **start) // display sublist
{
    struct node *ptr = *start; // assign *ptr to pointer to head of the list

    if (ptr == NULL) // if ptr is null
    {
        printf("Invalid");
    }

    while (ptr != NULL) // loop until ptr is null
    {
        printf("%d ", ptr->data); // print value of current node
        ptr = ptr->next;         // move ptr to next node
    }
}

void insertNodeBegin(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertNodeEnd(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *ptr = *head;
        
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

int main() {

    struct node *start = NULL;
    int nodenum, option, data;
    scanf("%d", &nodenum);
    scanf("%d", &option);

    for (int i = 0; i < nodenum; i++) {
        scanf("%d", &data);
        if(option == 1) {
            insertNodeBegin(&start, data);
        }
        else if(option == 2) {
            insertNodeEnd(&start, data);
        }
    }

    displayList(&start);
    free(start);
}

