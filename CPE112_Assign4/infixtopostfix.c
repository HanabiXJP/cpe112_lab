//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// กำหนดความสำคัญของเครื่องหมาย symbol

int PIR(char c) { //priority
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// กำหนดการเชื่อมโยงของตัวดำเนินการ
char ASOC(char symbol) { // associativity
    if (symbol == '^') {
        return 0; //R
    }

    return 1; // L ค่าเริ่มต้น
}

// ฟังก์ชันหลักสำหรับแปลง infix เป็น postfix
void infixToPostfix(char expression[]) {

    char stack[1000];
    int top = -1;
    int length = strlen(expression);
    char result[1000];
    int num = 0;
    
    for (int i = 0; i < length; i++) {

        char currentChar = expression[i];

        if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= '0' && currentChar <= '9')) {

            result[num++] = currentChar;

        } else if (currentChar == '(') {

            stack[++top] = currentChar;

        } else if (currentChar == ')') {

            while (top >= 0 && stack[top] != '(') {

                result[num++] = stack[top--];

            }

            top--; // Pop '('

        } else {

            while (top >= 0 && (PIR(expression[i]) < PIR(stack[top]) || PIR(expression[i]) == PIR(stack[top]) && ASOC(expression[i]) == 1)) {

                result[num++] = stack[top--];

            }

            stack[++top] = currentChar;
        }
    }

    // Pop function

    while (top >= 0) {

        result[num++] = stack[top--];

    }

    result[num] = '\0'; //Null terminator

    printf("%s", result);
}

int main() {
    
    char infixExpression[100];

    scanf("%s", &infixExpression);

    infixToPostfix(infixExpression);

    return 0;
}
