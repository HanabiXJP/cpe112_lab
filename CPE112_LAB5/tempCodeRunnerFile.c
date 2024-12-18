//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int items;
    struct queue *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

void insert(int data, int *size);
void dequeue(int *size);
void show();

int main() {

    int size, data;
    scanf("%d", &size);
    char option;

    while (1) {

        scanf(" %c", &option);

        if (option == 'I') {
            scanf("%d", &data);
            insert(data, &size);

        }
        else if (option == 'D') {

            dequeue(&size);

        }
        else if (option == 'S') {

            show();

        }
        else if (option == 'E') {

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
    }
    else {
        rear->next = newQueue;
        rear = newQueue;
        newQueue->next = front;
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
        // If there is only one element in the queue
        front = rear = NULL;
    }
    else {
        front = front->next;
        rear->next = front;
    }
    (*size)++;
    free(temp);
}

void show() {
    if (front == NULL) {
        printf("Queue is empty!!\n");
        return;
    }

    int position = 1;

    queue *temp = front;

    printf("Front: %d\n", position);
    printf("Items: ");
    if (front != rear) {
        do {
            printf("%d ", temp->items);
            position++;
            temp = temp->next;
        } while (temp != front);
    }
    else {
        printf("%d ", temp->items);
    }

    printf("\n");
    printf("Rear: %d\n", position - 1);
}
