#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return -1; 
}

void printStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }
    
    int temp = pop(&stack);
    printf("phan tu lay ra la %d\n", temp);
    printStack(&stack);

    return 0;
}
