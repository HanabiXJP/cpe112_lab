// 66070501060 ADISORN PARAMA 
// Assignment 7.1 : Kth Smallest Element in a BST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;

Node *newNode(int data);
Node *insert(Node *node, int data);
void kthSmallestElement(Node *node, int k, int *count);
void freeTree(Node *node);

int main()
{
    int n;
    scanf("%d", &n);
    //invaild input
    if(n < 1 || n > 1000)
    {
        printf("None\n");
        return 1;
    }
    //create BST
    Node *root = NULL;
    for(int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        //invaild input
        if(data < -1000 || data > 1000)
        {
            printf("Invalid input\n");
            freeTree(root);
            return 1;
        }
        root = insert(root, data);
    }

    //find kth smallest element
    int k;
    scanf("%d", &k);
    //invaild input
    if(k < 1 || k > 1000)
    {
        printf("Invalid input\n");
        freeTree(root);
        return 1;
    }
    //cant find kth smallest element
    if(k > n)
    {
        printf("None\n");
        freeTree(root);
        return 0;
    }
    int count = 0;
    kthSmallestElement(root, k, &count);
    return 0;
}

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *node, int data)
{
    if(node == NULL)
        return newNode(data);
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void kthSmallestElement(Node *node, int k, int *count)
{
    //inorder traversal always give sorted element

    if(node == NULL)
        return;
    kthSmallestElement(node->left, k, count);
    (*count)++;
    if(*count == k)
    {
        printf("%d\n", node->data);
        return;
    }
    kthSmallestElement(node->right, k, count);
}

void freeTree(Node *node)
{
    if(node == NULL)
        return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}