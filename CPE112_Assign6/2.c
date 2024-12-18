//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure for a binary tree node
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node;

// Function to create a new node
node* createnode(int data) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int add(node **root, char data){
    int status = 0;
    if(*root == NULL){
        *root = createnode(data);
        return 1;
    }else if((*root)->data == '+' || (*root)->data == '-'){
        //status is used to check if the node is add to the left or right
        status = add(&(*root)->left, data);
        if(status == 0){
            status = add(&(*root)->right, data);
        }
    }else{
        return 0;
    }
    return status; //use to collect data in recursive
}

void post(node *root){
    if(root == NULL)
        return;
    post(root->left);
    post(root->right);
    printf("%c", root->data);
}
 

int main () {

    node* root = NULL;
    char formula[1000];
    scanf("%s", formula);

    for (int i = 0; formula[i] != '\0'; i++) {
        add(&root, formula[i]);
    }

    post(root);
    return 0;


}