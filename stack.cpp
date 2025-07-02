#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int val) {
    if (top == SIZE - 1)
        printf("Stack full!\n");
    else
        stack[++top] = val;
}

void pop() {
    if (top == -1)
        printf("Stack empty!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack empty!\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1)
        printf("Stack empty!\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int n, val, ch;

    printf("How many elements? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        push(val);
    }

    while (1) {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
        } else if (ch == 2)
            pop();
        else if (ch == 3)
            peek();
        else if (ch == 4)
            display();
        else if (ch == 5)
            break;
        else
            printf("Invalid choice!\n");
    }

    return 0;
}

