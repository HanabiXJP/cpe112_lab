//Phudid Pimpsasan lab5-3
//6070503450
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    char data;
    struct node *next;
}node;

typedef struct queue{
    node *front;
    node *rear;
}queue;

int getpriority(char input);
void enQ(node *newnode, queue *current);
void print(queue *current);
queue *classify(char *input, int checkpriority);
node *createnode(char val);


int main(){
    char input[1000];
    scanf("%[^\n]s",&input);

    queue *vowel_Q = classify(input, 1); //vowels
    queue *conso_Q = classify(input, 3); //consonants
    queue *other_Q = classify(input, 2); //others

    print(vowel_Q);
    print(other_Q);
    print(conso_Q);

    return 0;
}

int getpriority(char input){
    // printf("[getpri_o]");
    if(input == 'a' || input == 'A' || input == 'e' || input == 'E'  || input == 'i' || input == 'I' || input == 'o' || input == 'O' || input == 'u' || input == 'U'){
        return 1;
    }
    else if(isalpha(input)){
        return 3;
    }
    return 2;
}

void enQ(node *newnode, queue *current){
    // printf("[enQ]");
    if(current->front == NULL && current->rear == NULL){
        current->front = newnode;
        current->rear  = newnode;
    }
    else{
        current->rear->next = newnode;
        current->rear = newnode;
    }
}

void print(queue *current){
    // printf("[print]");
    if(current->front == NULL){
        return;
    }
    node *now = current->front;
    while(now!=NULL){
        printf("%c", now->data);
        now = now->next;
    }
}

node *createnode(char val){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

queue *classify(char *input, int checkpriority){
    // printf("[classify]");
    queue *current = (queue*)malloc(sizeof(queue));
    current->front = NULL;
    current->rear = NULL;

    node *newnode = NULL;

    while(*input){
        int pri_o = getpriority(*input);
        if(pri_o == checkpriority){
            node *newnode = createnode(*input);
            enQ(newnode,current);
        }
        input++;
    }
    return current;
}