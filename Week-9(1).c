#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100
// Structure to represent a stack
typedef struct {
    char arr[MAX_SIZE];
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
void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %c\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
}
// Function to pop an element from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}
// Function to return the top element of the stack without removing it
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return stack->arr[stack->top];
}
// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}
// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initializeStack(&stack);
    int i, j;
    char c;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c; // If operand, add it to the postfix expression
        } else if (c == '(') {
            push(&stack, c); // If opening parenthesis, push it onto the stack
        } else if (c == ')') {
            // If closing parenthesis, pop operators from stack and add them to postfix until '(' is encountered
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard '('
        } else {
            // If operator, pop operators from stack and add them to postfix until an operator with lower precedence is encountered
            while (!isEmpty(&stack) && precedence(c) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c); // Push current operator onto the stack
        }
    }
    // Pop remaining operators from stack and add them to postfix
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Removing trailing newline character
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
