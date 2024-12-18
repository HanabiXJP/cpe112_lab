//66070503450
//Phudid Pimpasan lab5-2
#include<stdio.h>

void enQ(int *queue, int *front, int *rear, int maxsize);
void deQ(int *queue, int *front, int *rear, int maxsize);
void show(int *queue, int *front, int *rear, int maxsize);

int main(){
    char option;
    int maxsize, front=-1, rear=-1;
    scanf("%d",&maxsize);
    if(maxsize<1 || maxsize>10){
        return 0;
    }
    int queue[maxsize];
    while(scanf(" %c",&option)==1){
        switch(option){
            case 'I':
                enQ(queue, &front, &rear, maxsize);
                break;
            case 'D':
                deQ(queue, &front, &rear, maxsize);
                break;
            case 'S':
                show(queue, &front, &rear, maxsize);
                break;
            case 'E':
                return 0;
            default:
                continue;
        }
    }
}

void enQ(int *queue, int *front, int *rear, int maxsize){
    // printf("[enqueue]\n");
    if(*front == (*rear + 1) % maxsize){
        printf("Queue is full!!\n");
        return;
    }
    int val;
    scanf("%d",&val);
    if((*front)==-1 && (*rear)==-1){
        (*front)=(*rear)=0;
    }
    else{
        (*rear) = (*rear + 1) % maxsize;
    }
    queue[*rear] = val;
}

void deQ(int *queue, int *front, int *rear, int maxsize){
    // printf("[dequeue]\n");
    if((*front)==-1 && (*rear)==-1){
        printf("Queue is empty!!\n");
        return;
    }
    int val_front = queue[*front];
    if((*front)==(*rear)){
        (*front)=(*rear)=-1;
    }
    else{
        (*front) = (*front+1) % maxsize;
    }
    printf("%d\n",val_front);
}

void show(int *queue, int *front, int *rear, int maxsize){
    // printf("[show]\n");
    if((*front)==-1 && (*rear)==-1){
        printf("Queue is empty!!\n");
        return;
    }
    int temp_front = *front, temp_rear = *rear;
    printf("Front: %d\nItems: ",temp_front);
    for(int i=temp_front;i!=(*rear);i=(i+1)%maxsize){
        printf("%d ",queue[i]);
    }
    printf("%d \nRear: %d\n",queue[temp_rear], temp_rear);
}