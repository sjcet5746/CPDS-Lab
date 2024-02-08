#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// Structure to represent a queue
typedef struct {
    Node *front;
    Node *rear;
} Queue;
// Function to initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}
// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}
// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot enqueue %d\n", item);
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("Enqueued %d into the queue\n", item);
}
// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue\n");
        return -1;
    }
    Node *temp = queue->front;
    int item = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL; // Reset rear when queue becomes empty after dequeueing
    }
    printf("Dequeued %d from the queue\n", item);
    return item;
}
// Function to display the elements of the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements of the queue:\n");
    Node *current = queue->front;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
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
