#include <stdio.h>
#include <ctype.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    for (i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isspace(ch)) continue;
        if (isalnum(ch)) postfix[k++] = ch;
        else if (ch == '(') push(ch);
        else if (ch == ')') {
            while (stack[top] != '(') postfix[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (top != -1) postfix[k++] = pop();
    postfix[k] = '\0';
}
int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix expression: ");
    fgets(infix, SIZE, stdin);  // User input
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
