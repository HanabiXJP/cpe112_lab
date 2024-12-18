#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct stack{

    int top;
    char word[SIZE];

} stack;

int pop(stack *St) {
    if (St->top == -1)
        return -1;
    char ch = St->word[St->top];
    St->top--;
    return ch;
}

int push(stack *St, char ch) {
    St -> top++;
    St ->word[St->top] = ch;
    return St->top;

}

int ParenthesisChecker(stack *St, char data[]) {

    int length = strlen(data);

    for (int i = 0; i < length; i++) {

        if ( St ->word[St->top] == '(' || St ->word[St->top] == '{' || St ->word[St->top] == '[') {
            push(St, data[i]);
        }
        else if (data[i] == ')' || data[i] == '}' || data[i] == ']') {
            
            if (St->top == -1 || St->word[St->top] != data[i]) {
                return 0;
            }
            else {
                pop(St);
            }
        }
    }

    return St->top == -1 ? 0 : 1;

}
int main() {

    char word[SIZE];

    scanf("%s", word);

    int l = strlen(word);

    stack *St = (stack*)malloc(l * sizeof(stack));

    St->top = -1;

    if (ParenthesisChecker(St, word)) {
        printf("The string is balanced");
    } else {
        printf("The string is not balanced");
    }

    free(St);

    return 0;
    
    
}