//66070501077 Nipitpon Pakmaruek
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createnode(data);
    if (data < root->data)
        root->left = insert(root->left, data); //Recursive
    else if (data > root->data)
        root->right = insert(root->right, data); //Recursive
    return root;
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct node* root,int* sorted,int* j) {
    if (root != NULL) {
        inorder(root->left,sorted,j);
        sorted[*j] = root->data;
        (*j)++;
        inorder(root->right,sorted,j);
    }
}

int main() {
    struct node* root = NULL;
    int num, data,k,j = 1;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &data);
        root = insert(root, data); //Recursive
    }
    scanf("%d",&k);
    k;
    int sorted[100];


    //Inorder traversal: 
    inorder(root,sorted,&j);
    if(sorted[k] != 0){
        printf("%d",sorted[k]);
    }else{
        printf("None");
    }


    return 0;
}