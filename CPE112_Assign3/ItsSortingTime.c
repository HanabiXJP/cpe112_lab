//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int ID;
    struct node *next;

}node;

void insertNodeEnd(struct node **start, int data, int ID) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = *start;
    newNode->data = data;
    newNode->ID = ID;
    newNode->next = NULL;

    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void SortByID (node **start) {
    node *current = *start, *next;
    while (current != NULL) {
    next = current->next;
    while (next != NULL) {
      if (current->ID > next->ID) {

        int tempID = current->ID;
        int tempdata = current->data;

        current->ID = next->ID;
        current->data = next->data;
        next->ID = tempID;
        next->data = tempdata;
      }
      next = next->next;
    }
    current = current->next;
  }
}

void SortByData (node **start) {
    node *current = *start, *next;
    while (current != NULL) {
        next = current->next;
        while (next != NULL) {
            if (current->data > next->data) {
                int tempID = current->ID;
                int tempdata = current->data;
                current->ID = next->ID;
                current->data = next->data;
                next->ID = tempID;
                next->data = tempdata;
            } 
            else if (current->data == next->data && current->ID > next->ID) {
                int tempID = current->ID;
                int tempdata = current->data;
                current->ID = next->ID;
                current->data = next->data;
                next->ID = tempID;
                next->data = tempdata;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void displayList(struct node *start)
{
    struct node *ptr = start; 

    if (ptr == NULL)
    {
        printf("Invalid");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;   
    }
}

int main() {
    node *start = NULL;

    int size, ID, data, mode;

    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d %d", &ID, &data);
        insertNodeEnd(&start, data, ID);
    }

    scanf("%d", &mode);

    if(mode == 0) {
        SortByID(&start);
    }
    else if(mode == 1) {
        SortByData(&start);
    }

    displayList(start);

    return 0;
}