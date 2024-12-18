//Phanthach Jiamjaruschot 66070501038
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void addNode(node **head, int value) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = value;
  newNode->next = *head;
  if (*head == NULL) {
    newNode->next = newNode;
    *head = newNode;
  } else {
    node *temp = *head;
    while (temp->next != *head) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int deleteNode(node **head, int count) {
  node *temp = *head;
  while (temp->next != *head) {
    temp = temp->next;
  }
  while (temp->next != temp) {
    for (int i=1; i<count; i++) {
      temp = temp->next;
    }
    temp->next = temp->next->next;
  }
  return temp->data;
}

int main() {
  int n, c, input;
  node *head = NULL;
  scanf("%d %d", &n, &c);
  for (int i=0; i<n; i++) {
    scanf("%d", &input);
    addNode(&head, input);
  }
  printf("%d", deleteNode(&head, c));

  return 0;
}