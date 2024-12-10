
#include<stdio.h>
#include <stdio.h>
#include<string.h>
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

void push(Stack *stack, char value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    }
}
void printStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%c", stack->data[i]);
    }
}
int main() {
    Stack stack;
    initStack(&stack);

    char str[MAX_SIZE];
    fgets(str,sizeof(str),stdin);

    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }
    printStack(&stack);
}
