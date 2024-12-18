//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 100
#define MAXARTIST 100
#define MAXOPTION 10

typedef struct {
    char name[MAXNAME];
    char artist[MAXARTIST];
    int time;
} song;

typedef struct queue {
    song spotify;
    struct queue *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

void add(char name[], char artist[], int time);
void play();
void sum();


int main () {
    char option[MAXOPTION];
    char name[MAXNAME];
    char artist[MAXARTIST];
    int time = 0;

    while (1) {
        fgets(option, sizeof(option), stdin);

        if (option[strlen(option) - 1] == '\n')
        {
            option[strlen(option) - 1] = '\0';
        }

        if (strcmp("add", option) == 0) {
            fgets(name, sizeof(name), stdin);
            if (name[strlen(name) - 1] == '\n')
            {
                name[strlen(name) - 1] = '\0';
            }
            fgets(artist, sizeof(artist), stdin);
            if (artist[strlen(artist) - 1] == '\n')
            {
                artist[strlen(artist) - 1] = '\0';
            }
            scanf("%d", &time);
            getchar(); // Flush the newline character

            //Debug log
            // printf("Debug: name=%s, artist=%s, time=%d\n", name, artist, time); 

            add(name, artist, time);
        } else if (strcmp("play", option) == 0) {
            play();
        } else if (strcmp("sum", option) == 0) {
            sum();
            break;
        }
    }

    return 0;
}

void add(char name[], char artist[], int time) {
    queue *newQueue = (queue*)malloc(sizeof(queue));

    strcpy(newQueue->spotify.name, name);
    strcpy(newQueue->spotify.artist, artist);
    newQueue->spotify.time = time;

    newQueue->next = NULL;

    if (rear == NULL) {
        front = rear = newQueue;
    } else {
        rear->next = newQueue;
        rear = newQueue;
    }
}

void play() {
    if (front == NULL) {
        printf("No songs in the playlist\n");
    } else {
        queue *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;

        printf("Now playing: %s by %s\n", temp->spotify.name, temp->spotify.artist);
        free(temp);
    }
}

void sum() {
    if (front == NULL) {
        printf("No songs in the playlist\n");
    } else {
        queue *order = front;
        int timeamount = 0;


        printf("Songs in the playlist:\n");
        while (order != NULL) {
            printf("%s by %s %d\n", order->spotify.name, order->spotify.artist, order->spotify.time);
            timeamount += order->spotify.time;
            order = order->next;
        }

        printf("Remaining Time: %d\n", timeamount);
    }
}
