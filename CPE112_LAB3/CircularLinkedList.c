//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *start = NULL;

void InsertList(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if (start == NULL) {
        start = newNode;
        newNode->next = start;
    } else {
        node *current = start;
        while (current->next != start) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = start;
    }
}

void DeleteList(int val) {
    if (start == NULL) {
        return;
    }

    if (start->data == val) {
        node *temp = start;
        if (temp->next == start) {
            start = NULL;
        } else {
            node *current = start;
            while (current->next != start) 
            {
                current = current->next;
            }
            current->next = temp->next;
            start = temp->next;
        }
        free(temp);
    } else {
        node *current = start;
        while (current->next != start && current->next->data != val) {
            current = current->next;
        }
        if (current->next->data == val) {
            node *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
}

void displayList() {
    if (start == NULL) {
        printf("Empty\n");
        return;
    }

    node *current = start;

    do 
    {
        printf("%d ", current->data);
        current = current->next;
    } 
    while (current != start);
    printf("\n");
}

int main() {
    int data;
    char command;

    while (1) {
        scanf(" %c", &command);

        if (command == 'E') {
            break;
        }

        scanf("%d", &data);

        if (command == 'I') {
            InsertList(data);
        } else if (command == 'D') {
            DeleteList(data);
        }
    }

    displayList();
    return 0;
}
