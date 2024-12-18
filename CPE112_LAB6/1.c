//66070501038 Phanthach Jiamjaruschot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct node* insertLeft(struct node* root, int data) {
	root->left = createnode(data);
	return root->left;
}
// Insert on the right of the node
struct node* insertRight(struct node* root, int data) {
	root->right = createnode(data);
	return root->right;
}

// Function to insert a node
struct node* insertRoot(struct node* root, int data) {
	if (root == NULL)
		return createnode(data);
}

// Preorder traversal: Root -> Left -> Right
void preorder(struct node* root) {
	if (root != NULL) {
		printf("%d ",root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct node* root) {
	if (root != NULL) {
		inorder(root -> left);
		printf("%d ",root -> data);
		inorder(root -> right);
	}
}

// Postorder traversal: Left -> Right -> Root
void postorder(struct node* root) {
	if (root != NULL) {
		postorder(root -> left);
		postorder(root -> right);
		printf("%d ",root -> data);
	}
}

//No need to edit in the main() function
int main() {
	struct node* root = NULL;
	int j;
	int n, data;
	char dir[10];
	// printf("Enter the number of nodes: ");
	scanf("%d", &n);
	// printf("Enter the node values:\n");
	for (int i = 0; i < n; ++i) {

		// insert/create root node
		if(i==0){
			scanf("%d", &data);
			root = insertRoot(root, data);
			continue;
		}

		// insert non-root node
		scanf("%s", dir);
		scanf("%d", &data);
		struct node* temp = root;
		for(j = 0; j<strlen(dir)-1; j++){
			if(dir[j]=='R'){
				temp = temp->right;
			}
			else if(dir[j]=='L'){
				temp = temp->left;
			}
		}
		if(dir[j]=='R'){
			temp = insertRight(temp, data);
		}
		else if(dir[j]=='L'){
			temp = insertLeft(temp, data);
		}
	}

	// printf("Preorder traversal: ");
	preorder(root);
	printf("\n");

	// printf("Inorder traversal: ");
	inorder(root); 
	printf("\n");

	// printf("Postorder traversal: ");
	postorder(root);
	printf("\n");

	return 0;
}