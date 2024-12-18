#include "Fundamental_Lib_OPD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROOM 4
#define STATUSWORD 8
#define INPUTCMD 100

typedef struct queue {
    OPD_Info patientname;
    struct queue *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

void addqueue(char name[]);
void show();
void assignRoom(char room[][STATUSWORD]);

int main () {
    char name[INPUTCMD];
    char Room[MAXROOM][STATUSWORD]; // 2D array to track room status

    printf("---------------------------------\n");
    printf("\tROOM QUEUE SYSTEM\n");
    printf("---------------------------------\n");

        // Initialize room status
        for (int i = 0; i < MAXROOM ; i++) {
            strcpy(Room[i], "EMPTY");
        }

        // Display room status
        for (int i = 0; i < MAXROOM ; i++) {
            printf("\tRoom[%d] : %s\n", i+1, Room[i]);
        }
    while (1) {
        

        printf("---------------------------------\n");
        printf("\tPATIENT QUEUE LIST\n");
        show();
        printf("---------------------------------\n");
        printf("enqueue here : ");
        scanf("%s", name);
        
        if (strcmp(name, "T") == 0) { // If input is "T", assign patients to rooms
            assignRoom(Room);
        } else { // Otherwise, enqueue the patient
            addqueue(name);
        }
        system("cls"); // Clear screen (Windows specific, consider using a cross-platform solution)

        printf("---------------------------------\n");
        printf("\tROOM QUEUE SYSTEM\n");
        printf("---------------------------------\n");

        // Display room status
        for (int i = 0; i < MAXROOM ; i++) {
            printf("\tRoom[%d] : %s\n", i+1, Room[i]);
        }
    }
    return 0;
}

void addqueue(char name[]) {
    queue *newQueue = (queue*)malloc(sizeof(queue));
    strcpy(newQueue->patientname.name_surname, name);
    newQueue->next = NULL;

    if (rear == NULL) {
        front = rear = newQueue;
    } else {
        rear->next = newQueue;
        rear = newQueue;
    }
}

void show() {
    if (front == NULL) {
        printf("\tNo Patient!\n");
    } else {
        printf("\tPatient Queue:\n");
        queue *temp = front;
        while (temp != NULL) {
            printf("\t- %s\n", temp->patientname.name_surname);
            temp = temp->next;
        }
    }
}

void assignRoom(char room[][STATUSWORD]) {
    for (int i = 0; i < MAXROOM; i++) {
        if (strcmp(room[i], "EMPTY") == 0 && front != NULL) {
            // Room is empty and patient is available in the queue
            strcpy(room[i], front->patientname.name_surname);
            // Dequeue the patient
            queue *temp = front;
            front = front->next;
            free(temp);
            if (front == NULL) {
                rear = NULL;
            }
        }
    }
}


