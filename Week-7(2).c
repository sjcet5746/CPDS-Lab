#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the stack
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// Structure to represent a stack
typedef struct {
    Node *top;
} Stack;
// Function to initialize the stack
void initializeStack(Stack *stack) {
    stack->top = NULL;
}
// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}
// Function to push an element onto the stack
void push(Stack *stack, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot push %d\n", item);
        return;
    }
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack\n", item);
}
// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1;
    }
    Node *temp = stack->top;
    int item = temp->data;
    stack->top = temp->next;
    free(temp);
    return item;
}
// Function to display the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements of the stack:\n");
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
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
