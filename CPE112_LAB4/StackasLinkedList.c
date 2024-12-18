//66070501038 PHANTHACH JIAMJARUSCHOT

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;

}node;

node* pushlist (node **start ,int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = data;

    if (*start == NULL) {
        *start = newNode;
        newNode->next = *start;

    }
    else {
        node *current = *start;
        while (current->next != *start) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *start;
    }

    return newNode;
}

void toplist(node *start) {

    if(start == NULL) {
        printf("empty\n");
        return;
    }

    node *current = start;

    while (current->next != start) {
        current = current->next;
    }

    printf("%d\n", current->val);
}

void poplist(node **start) {

    if(*start == NULL) {
        printf("empty\n");
        return;
    }

    node *current = *start;
    node *previous = NULL;

    while (current->next != *start) {
        previous = current;
        current = current->next;

    }

    printf("%d\n", current->val);

    if (previous == NULL) {
        free(current);
        *start = NULL;
    } else {
        previous->next = *start;
        free(current);
    }

}

void ISempty(node *start) {

    if(start == NULL) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

int main() {

    node *start = NULL;
    int data;
    char mode;

    while(1) {

        scanf(" %c", &mode);

        if(mode == 'p') {
            scanf("%d", &data);
            pushlist(&start, data);
        }

        else if(mode == 'o') {
            poplist(&start);
        }

        else if(mode == 't') {
            toplist(start);
        }

        else if(mode == 'e') {
            ISempty(start);
        }

        else if(mode == 'q') {
            exit(0);
        }
        

    }

    
    return 0;
}