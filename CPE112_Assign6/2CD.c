//66070501053 Sakchat Hensook
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Node
typedef struct Node {
  char data;
  struct Node *left;
  struct Node *right;
} Node;

// Function to create a new Node
Node *createNode(char data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Function to add Nodes to the binary tree
int add(Node **root, char data) {
  if (*root == NULL) {
    *root = createNode(data);
    return 1;
  }
  int temp = 0;
  if ((*root)->data == '+' || (*root)->data == '-' || (*root)->data == '*' || (*root)->data == '/') {
    temp = add(&(*root)->left, data);
        if(temp == 0) {
            temp = add(&(*root)->right, data);
        }
        } else {
        return 0;
        }
        return temp;
    }
// Function to display postfix expression
void post(Node *root) {
  if (root != NULL) {
    post(root->left);
    post(root->right);
    printf("%c", root->data);
  }
}

int main() {
  Node *root = NULL;

  // Input prefix expression
  char expression[101];
  scanf("%s", expression);

  int i = 0;

  // Build the binary tree
  while (expression[i] != '\0') {
    add(&root, expression[i]);
    i++;
  }

  post(root);
  return 0;
}

