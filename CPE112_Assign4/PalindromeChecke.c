//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct stack{

    int top;
    char word[SIZE];

} stack;

int pop(stack *St) {
    char ch = St->word[St->top];
    St->top--;
    return ch;
}

int push(stack *St, char ch) {
    St -> top++;
    St ->word[St->top] = ch;
    return St->top;

}

int palindromeChecker(stack *St, char data[]) {

    int length = strlen(data);

    for (int i = 0; i < length; i++) {
        push(St, data[i]);
    }

    for (int i = 0; i < length; i++) {
        if (pop(St) != data[i]) {
            return 0;
        }
    }

    return 1;


}
int main() {

    char data[SIZE];

    scanf("%s", data);

    int l = strlen(data);

    stack *St = (stack*)malloc(l * sizeof(stack));

    St->top = -1;

    if (palindromeChecker(St, data)) {
        printf("yes");
    } else {
        printf("no");
    }

    return 0;
    
    
}