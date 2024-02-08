#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
// Function to create a new node with the given data
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the beginning of the doubly linked list
Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
// Function to insert a node at the end of the doubly linked list
Node* insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}
// Function to delete the first occurrence of a node with the given data
Node* deleteNode(Node *head, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->data == data) {
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    Node *current = head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list\n");
        return head;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    current->prev->next = current->next;
    free(current);
    return head;
}
// Function to traverse and print the elements of the doubly linked list
void traverse(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Elements of the list:\n");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Node *head = NULL;
    int choice, data;
    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    // Freeing memory allocated to the doubly linked list
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
