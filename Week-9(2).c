#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
// Structure to represent a stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;
// Function to initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}
// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
// Function to push an element onto the stack
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
}
// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1;
    }
    return stack->arr[stack->top--];
}
// Function to evaluate the postfix expression
int evaluatePostfix(char *postfix) {
    Stack stack;
    initializeStack(&stack);
    int i, operand1, operand2, result;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(&stack, c - '0'); // If operand, push its integer value onto the stack
        } else {
            // If operator, pop two operands from stack, perform operation, and push result back onto stack
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (c) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", c);
                    return -1;
            }
        }
    }
    // Result will be left on top of the stack after evaluation
    result = pop(&stack);
    if (!isEmpty(&stack)) {
        printf("Invalid postfix expression\n");
        return -1;
    }
    return result;
}
int main() {
    char postfix[MAX_SIZE];
    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = '\0'; // Removing trailing newline character
    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result of the postfix expression: %d\n", result);
    }
    return 0;
}
