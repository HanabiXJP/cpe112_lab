  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

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

  node* insertLevelOrder(node* root, int data_array[], int i, int max) {

    if (i < max) {

      node* temp = createNode(data_array[i]);
      root = temp;
      root->left = insertLevelOrder(root->left, data_array, 2*i + 1, max);
      root->right = insertLevelOrder(root->right, data_array, 2*i + 2, max);
      
    }
    return root;
  }

  // Placeholder for potential optimization
  int add(node* root) {
    if (root == NULL) {
      return 0;
    }

    int sum = root->data + add(root->left) + add(root->right);
    return sum;
  }

  int sumTree(node* root) {
    if (root == NULL) {
      return 1; // Empty tree considered a sum tree
    }

    int left_sum = add(root->left);
    int right_sum = add(root->right);
    return root->data == left_sum + right_sum;
  }

  int main() {
    node* root = NULL;
    int data_array[100];
    int max = 0;

    // Input loop
    while (1) {
      int input_value;
      scanf("%d", &input_value);
      if (input_value == -1001) {
        data_array[max] = 0;
        break;
      }
      data_array[max] = input_value;
      max++;
    }

    root = insertLevelOrder(root, data_array, 0, max);


    if (sumTree(root) == 1) {
      printf("True\n");
    } else {
      printf("False\n");
    }

    return 0;
  }
