#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void freeList(node *head) {
    node *current = head;
    node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void AddList(node **start, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    node *ptr = *start;
    newNode->data = data;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
        return;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void DelList(node **start, int data) {
    node *current = *start;
    node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            *start = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

void SearchList(node **start, int data) {
    node *ptr = *start;
    printf("%d ", data);
    
    while (ptr != NULL) {
        if (ptr->data == data) {
            printf("%d ", ptr->next != NULL ? ptr->next->data : -1);
            break;
        }
        ptr = ptr->next;
    }
    printf("\n");
}

void displayList(node *start) {
    node *ptr = start;

    if (ptr == NULL) {
        printf("none");
        return;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    node *start = NULL;
    char command[10];
    int data;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "END") == 0) {
            break;
        }

        scanf("%d", &data);

        if (strcmp(command, "ADD") == 0) {
            AddList(&start, data);
        } else if (strcmp(command, "DEL") == 0) {
            DelList(&start, data);
        } else if (strcmp(command, "SCH") == 0) {
            SearchList(&start, data);
        }
    }

    displayList(start);

    freeList(start);

    return 0;
}
