#include <stdio.h>
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
    } else {
        stack->arr[++stack->top] = item;
        printf("Pushed %d onto the stack\n", item);
    }
}
// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}
// Function to display the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Elements of the stack:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->arr[i]);
        }
    }
}
int main() {
    Stack stack;
    initializeStack(&stack);
    int choice, item;
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1) {
                    printf("Popped %d from the stack\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
