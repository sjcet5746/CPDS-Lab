#include <stdio.h>
#include <stdlib.h>
// Structure to represent a stack
struct Stack {
    int capacity;
    int top;
    int *array;
};
// Function to create a stack of given capacity
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}
// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}
// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
// Function to move a disk from source to destination
void moveDisk(char source, char destination, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, source, destination);
}
// Function to solve Towers of Hanoi problem non-recursively
void towersOfHanoi(int num_disks, char source, char auxiliary, char destination) {
    struct Stack *stack = createStack(num_disks);
    int total_moves = (1 << num_disks) - 1; // Total moves required
    // Push disks onto the stack in reverse order
    for (int i = num_disks; i >= 1; i--)
        push(stack, i);
    char temp;
    // Iterate through the total number of moves
    for (int i = 1; i <= total_moves; i++) {
        // Determine the source and destination rods based on the move number and the number of disks
        if (i % 3 == 1) {
            moveDisk(source, destination, pop(stack));
        } else if (i % 3 == 2) {
            if (num_disks % 2 == 0)
                temp = auxiliary;
            else
                temp = source;
            moveDisk(source, temp, pop(stack));
        } else if (i % 3 == 0) {
            if (num_disks % 2 == 0)
                temp = source;
            else
                temp = auxiliary;
            moveDisk(temp, destination, pop(stack));
        }
    }
}
int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    printf("Steps to solve Towers of Hanoi problem with %d disks:\n", num_disks);
    towersOfHanoi(num_disks, 'A', 'B', 'C');
    return 0;
}
