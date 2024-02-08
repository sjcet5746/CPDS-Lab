#include <stdio.h>
#define MAX_SIZE 100
// Structure to represent a queue
typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;
// Function to initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
// Function to check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}
// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}
// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", item);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Initialize front when inserting the first element
    }
    queue->arr[++queue->rear] = item;
    printf("Enqueued %d into the queue\n", item);
}
// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue\n");
        return -1;
    }
    int item = queue->arr[queue->front++];
    printf("Dequeued %d from the queue\n", item);
    if (queue->front > queue->rear) {
        // Reset front and rear when queue becomes empty after dequeueing
        initializeQueue(queue);
    }
    return item;
}
// Function to display the elements of the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements of the queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\n", queue->arr[i]);
    }
}
int main() {
    Queue queue;
    initializeQueue(&queue);
    int choice, item;
    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
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
