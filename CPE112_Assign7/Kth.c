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

int kthSmallest(node* root, int target, int* count) {
    if (root == NULL)
        return -1;

    int result = kthSmallest(root->left, target, count);
    if (result != -1)
        return result;

    (*count)++;
    if (*count == target)
        return root->data;

    return kthSmallest(root->right, target, count);
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
    int result = kthSmallest(root, k, &order);

    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("None\n");
    }
    return 0;
}

