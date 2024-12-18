//66070501038 PHANTHACH JIAMJARUSCHOT

#include <stdio.h>
#include <stdlib.h>

int top = -1;

void push(int *stack, int val, int max) {
    if(top == max - 1 ) {
        printf("Stack Overflow.");
        exit(0);
    }
    top++;
    stack[top] = val;
}

void pop(int *stack) {

    if(top == -1) {
        printf("Stack Underflow.");
        exit(0);
    }
    top--;

}

void show(int *stack) {

    for (int i = top; i > -1 ; i--) {
        printf("%d\n", stack[i]);
    }

}

void isEmpty() {
    if(top == -1 ) {
        printf("Stack is empty.");
        exit(0);
    }
}

int main () {
    int max, choice, val;

    scanf("%d", &max);

    if(max <= 0) {
        printf("Please enter a positive number.");
        exit(0);
    }

    int *stack = (int*)malloc(max * sizeof(int));


    while(1) {

        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &val);
            push(stack, val, max);
        }
        else if (choice == 2) {
            pop(stack);
        }
        else if (choice == 3) {
            isEmpty(stack);
            break;
        }
        else if (choice == 4) {
            printf("Exiting...");
            exit(0);
        }
        else
        {
            printf("Invalid choice.");
            exit(0);
        }

    }


    show(stack);
    free(stack);

    return 0;
}