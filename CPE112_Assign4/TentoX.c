//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void ConvertBase(node **start, int remainder) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = remainder;    

    if (*start == NULL) {
        newNode->next = NULL;
        *start = newNode;
        return;
    }

    newNode->next = *start;
    *start = newNode;
}

void freeList(node *head) {
    node *current = head;
    node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void displayList(node **start, char letter[]) {
    node *ptr = *start;

    if (ptr == NULL) {
        printf("Invalid");
        return;
    }

    while (ptr != NULL) {
        printf("%c", letter[ptr->data]);
        ptr = ptr->next;
    }
}

int main() {
    int decimal, base, remainder;
    remainder = 0;
    node *start = NULL;

    scanf("%d", &decimal);
    scanf("%d", &base);

    if (base < 2 || base > 36) {
        printf("Invalid");
        exit(0);
    }

    while (decimal != 0) {
        remainder = decimal % base;
        ConvertBase(&start, remainder);
        decimal = decimal / base;
    }

    char letter[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    displayList(&start, letter);

    freeList(start);

    return 0;
}
