//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <stdlib.h>

typedef struct graph{
    struct node* head[100];
}graph;

typedef struct node{
    int dest, weight;
    struct node* next;
}node;

node* createNode(int dest, int weight) {
    node* newNode = malloc(sizeof(node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL; // ตั้งค่า pointer ให้ชี้ไปที่ NULL เพื่อให้เป็นโหนดสุดท้ายของ linked list
    return newNode;
}

void addEdge(graph* Graph, int src, int dest, int weight) {
    node* newNode = createNode(dest, weight);
    if (Graph->head[src] == NULL || dest < Graph->head[src]->dest) {
        newNode->next = Graph->head[src];
        Graph->head[src] = newNode;
    } else {
        node* ptrN = Graph->head[src], *temp = NULL;
        while (ptrN != NULL && dest > ptrN->dest) {
            temp = ptrN;
            ptrN = ptrN->next;
        }
        if (ptrN != NULL && ptrN->dest == dest) {
            while (ptrN != NULL && weight > ptrN->weight) {
                temp = ptrN;
                ptrN = ptrN->next;
            }
        }
        newNode->next = ptrN;
        if (temp != NULL)
            temp->next = newNode;
        else
            Graph->head[src] = newNode;
    }
}

void printGraph(graph* Graph, int n) {
    for (int i = 0; i < n; i++) {
        node* ptr = Graph->head[i];
        while (ptr != NULL) {
            printf("%d -> %d (%d)\n", i, ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
    }
}

int main() {
    int src, dest, weight, n_vertex;
    scanf("%d", &n_vertex);
    graph* Graph = malloc(sizeof(graph));

    for (int i = 0; i < n_vertex; i++) {
        Graph->head[i] = NULL;
    }

    for (int i = 0; i < n_vertex; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(Graph, src, dest, weight);
    }

    printGraph(Graph, n_vertex);

    return 0;
}
