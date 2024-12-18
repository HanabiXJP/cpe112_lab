//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int items;
    struct queue *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

int frontIdx = -1;  // Global front index variable
int rearIdx = -1;   // Global rear index variable

void insert(int data, int *size);
void dequeue(int *size);
void show(int maxindx);

int main() {
    int size, data, maxindx;
    scanf("%d", &size);

    maxindx = size;

    char option;

    while (1) {
        scanf(" %c", &option);

        if (option == 'I') {
            scanf("%d", &data);
            insert(data, &size);
        } else if (option == 'D') {
            dequeue(&size);
        } else if (option == 'S') {
            show(maxindx);
        } else if (option == 'E') {
            exit(0);
        }
    }
}

void insert(int data, int *size) {
    queue *newQueue = (queue *)malloc(sizeof(queue));

    if (*size == 0) {
        printf("Queue is full!!\n");
        free(newQueue);
        return;
    }

    newQueue->items = data;

    if (rear == NULL) {
        front = rear = newQueue;
        newQueue->next = front;
        frontIdx = 0;  // Set front index to 0 when the first element is inserted
        rearIdx = 0;   // Set rear index to 0 when the first element is inserted
    } else {
        rear->next = newQueue;
        rear = newQueue;
        newQueue->next = front;
        rearIdx++;  // Increment rear index when a new element is inserted
    }

    (*size)--;
}

void dequeue(int *size) {
    if (front == NULL) {
        printf("Queue is empty!!\n");
        return;
    }

    queue *temp = front;
    printf("%d\n", temp->items);

    if (front == rear) {
        front = rear = NULL;
        frontIdx = -1;  // Reset front index when the last element is dequeued
        rearIdx = -1;   // Reset rear index when the last element is dequeued
    } else {
        front = front->next;
        rear->next = front;
        frontIdx++;  // Increment front index when an element is dequeued
    }
    (*size)++;
    free(temp);
}

void show(int maxindx) {
    if (front == NULL) {
        printf("Queue is empty!!\n");
        return;
    }

    int position = frontIdx;

    queue *temp = front;
    printf("Front: %d\n", position);
    printf("Items: ");
    if (front != rear) {
        do {
            printf("%d ", temp->items);
            position++;
            temp = temp->next;
        } while (temp != front);
    } else {
        printf("%d ", temp->items);
    }

    printf("\n");
    printf("Rear: %d\n", (rearIdx % maxindx));
}