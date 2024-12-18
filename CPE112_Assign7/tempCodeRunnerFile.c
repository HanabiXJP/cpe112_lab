//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* insertBinary(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insertBinary(root->left, val);
    }
    else if (val > root->data) {
        root->right = insertBinary(root->right, val);
    }
    return root;
}

int findOrder(node* root, int target, int* order) {
    if (root == NULL) {
        return -1; // Node not found
    }

    // Traverse the left subtree
    int leftOrder = findOrder(root->left, target, order);
    if (leftOrder != -1) {
        return leftOrder; // Found in the left subtree
    }

    // Update order if current node is the target
    (*order)++;
    if (root->data == target) {
        return *order;
    }

    // Traverse the right subtree
    int rightOrder = findOrder(root->right, target, order);
    if (rightOrder != -1) {
        return rightOrder; // Found in the right subtree
    }

    // Not found
    return -1;
}

int main() {
    node* root = NULL;
    int size, input, k;

    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &input);
        root = insertBinary(root, input); // Update root after insertion
    }

    scanf("%d", &k);

    int order = 0;
    int result = findOrder(root, k, &order);

    if (result != -1) {
        printf("%d", result);
    }
    else {
        printf("None");
    }
    return 0;
}

