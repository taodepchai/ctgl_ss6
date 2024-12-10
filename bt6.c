#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return '\0';
}

int checkBalanced(char *s) {
    Stack stack;
    initStack(&stack);
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(&stack, s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char top = peek(&stack);
            if ((top == '(' && s[i] == ')') || 
                (top == '[' && s[i] == ']') || 
                (top == '{' && s[i] == '}')) {
                pop(&stack);
            } else {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main() {


        char str[MAX_SIZE];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; 

        if (checkBalanced(str)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

}
