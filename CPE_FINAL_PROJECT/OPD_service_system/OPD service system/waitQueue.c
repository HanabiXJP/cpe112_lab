#include "Fundamental_Lib_OPD.h" // Custom header file, likely defining the OPD_Info struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROOM 4      // Maximum number of rooms
#define STATUSWORD 8   // Maximum length of the status word for each room
#define INPUTCMD 100   // Maximum length for the input command

// Define the queue node structure
typedef struct queue {
    OPD_Info patientname; // Structure to hold patient name
    struct queue *next;   // Pointer to the next node in the queue
} queue;

queue *front = NULL; // Pointer to the front of the queue
queue *rear = NULL;  // Pointer to the rear of the queue

// Function prototypes
void addqueue(char name[]);
void show();
void assignRoom(char room[][STATUSWORD]);
void emptyRoom(char room[][STATUSWORD], int roomNumber);

int main() {
    char name[INPUTCMD]; // Buffer to hold input command
    char Room[MAXROOM][STATUSWORD]; // 2D array to track room status

    printf("---------------------------------\n");
    printf("\tROOM QUEUE SYSTEM\n");
    printf("---------------------------------\n");

    // Initialize room status to "EMPTY"
    for (int i = 0; i < MAXROOM; i++) {
        strcpy(Room[i], "EMPTY");
    }

    // Display initial room status
    for (int i = 0; i < MAXROOM; i++) {
        printf("\tRoom[%d] : %s\n", i + 1, Room[i]);
    }

    while (1) {
        printf("---------------------------------\n");
        printf("\tPATIENT QUEUE LIST\n");
        show(); // Display the current patient queue
        printf("---------------------------------\n");
        printf("\t[Name for ENQUEUE]\n");
        printf("\t[T for QUEUE ACTION]\n");
        printf("\t[E for EMPTYROOMNUM Example : E1]\n");
        printf("\tINPUT : ");
        scanf("%s", name); // Read input command
        
        // If input is "T", assign patients to rooms
        if (strcmp(name, "T") == 0) {
            assignRoom(Room);
        }
        // If input starts with "E", followed by a room number
        else if (name[0] == 'E') {
            int roomNumber = atoi(name + 1); // Extract the room number from input string
            emptyRoom(Room, roomNumber);
        }
        // Otherwise, enqueue the patient
        else {
            addqueue(name);
        }
        system("cls"); // Clear screen (Windows specific, consider using a cross-platform solution)

        printf("---------------------------------\n");
        printf("\tROOM QUEUE SYSTEM\n");
        printf("---------------------------------\n");

        // Display updated room status
        for (int i = 0; i < MAXROOM; i++) {
            if (strcmp(Room[i], "EMPTY") == 0) {
                printf("\tRoom[%d] : %s \tNO PATIENT\n", i + 1, Room[i]);
            }
            else {
                printf("\tRoom[%d] : %s \t\tOCCUPIED\n", i + 1, Room[i]);
            }
        }
    }
    return 0;
}

// Function to add a patient to the queue
void addqueue(char name[]) {
    queue *newQueue = (queue*)malloc(sizeof(queue)); // Allocate memory for new node
    strcpy(newQueue->patientname.name_surname, name); // Set the patient name
    newQueue->next = NULL; // Set the next pointer to NULL

    if (rear == NULL) { // If queue is empty
        front = rear = newQueue; // Both front and rear point to the new node
    } else {
        rear->next = newQueue; // Link the new node at the end of the queue
        rear = newQueue; // Update the rear pointer
    }
}

// Function to display the patient queue
void show() {
    if (front == NULL) { // If queue is empty
        printf("\tNO PATIENT IN QUEUE\n");
    } else {
        printf("\tPATIENT QUEUE:\n");
        queue *temp = front;
        while (temp != NULL) { // Traverse the queue
            printf("\t- %s\n", temp->patientname.name_surname); // Print each patient name
            temp = temp->next; // Move to the next node
        }
    }
}

// Function to assign patients to empty rooms
void assignRoom(char room[][STATUSWORD]) {
    for (int i = 0; i < MAXROOM; i++) {
        if (strcmp(room[i], "EMPTY") == 0 && front != NULL) {
            // Room is empty and patient is available in the queue
            strcpy(room[i], front->patientname.name_surname); // Assign patient to room
            // Dequeue the patient
            queue *temp = front;
            front = front->next;
            free(temp); // Free the dequeued node
            if (front == NULL) {
                rear = NULL; // Update rear if queue is empty
            }
            break; // Exit loop after assigning a patient to a room
        }
    }
}

// Function to empty a specified room
void emptyRoom(char room[][STATUSWORD], int roomNumber) {
    if (roomNumber >= 1 && roomNumber <= MAXROOM) { // Check if the room number is valid
        strcpy(room[roomNumber - 1], "EMPTY"); // Empty the specified room
    } else {
        printf("Invalid room number!\n"); // Print error message if room number is invalid
    }
}
