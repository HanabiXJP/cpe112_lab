//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* makeList(int array[], int size) {
    if (size == 0) {
        return NULL;
    }

    ListNode *start = malloc(sizeof(ListNode));
    start->val = array[0];
    start->next = NULL;
    ListNode *current = start;

    for (int i = 1; i < size; i++) {
        current->next = malloc(sizeof(ListNode));
        current = current->next;
        current->val = array[i];
        current->next = NULL;
    }

    return start;
}

void displayList(ListNode *start) {
    while (start != NULL) {
        printf("%d ", start->val);
        start = start->next;
    }
    printf("\n");
}

ListNode* RevBetween(ListNode* start, int sp, int ep) {
    if (start == NULL || sp == ep) {
        return start;
    }

    ListNode *dummy = malloc(sizeof(ListNode));
    dummy->next = start;

    ListNode *prev = dummy;
    for (int i = 1; i < sp; i++) {
        prev = prev->next;
    }

    ListNode *current = prev->next;
    ListNode *next = NULL;

    for (int i = sp; i < ep; i++) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy->next;
}

void freeList(ListNode *start) {
    while (start != NULL) {
        ListNode *temp = start;
        start = start->next;
        free(temp);
    }
}

int main() {
    ListNode *start = NULL;
    char stop[10];
    int array[MAX_SIZE];
    int sp, ep, data;
    int i = 0;

    while (i < MAX_SIZE) {
        scanf("%s", stop);
        if (strcmp(stop, "END") == 0) {
            break;
        }

        data = atoi(stop);
        array[i++] = data;
    }

    scanf("%d %d", &sp, &ep);
    start = makeList(array, i);
    start = RevBetween(start, sp, ep);
    displayList(start);

    // Free allocated memory
    freeList(start);

    return 0;
}
