#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the circular linked list
typedef struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the beginning of the circular linked list
Node* insertAtBeginning(Node *last, int data) {
    Node *newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}
// Function to insert a node at the end of the circular linked list
Node* insertAtEnd(Node *last, int data) {
    Node *newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}
// Function to delete the first occurrence of a node with the given data
Node* deleteNode(Node *last, int key) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node *temp = last->next;
    Node *prev = NULL;
    if (temp->data == key) {
        if (temp == last) {
            free(temp);
            return NULL;
        } else {
            last->next = temp->next;
            free(temp);
            return last;
        }
    }
    prev = temp;
    temp = temp->next;
    while (temp != last->next && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == last->next) {
        printf("Element not found in the list\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
    return last;
}
// Function to traverse and print the elements of the circular linked list
void traverse(Node *last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Elements of the list:\n");
    Node *temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}
int main() {
    Node *last = NULL;
    int choice, data;
    do {
        printf("\nCircular Linked List Operations:\n");
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
                last = insertAtBeginning(last, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                last = insertAtEnd(last, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                last = deleteNode(last, data);
                break;
            case 4:
                traverse(last);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    // Freeing memory allocated to the circular linked list
    if (last != NULL) {
        Node *temp = last->next;
        while (temp != last) {
            Node *tempNext = temp->next;
            free(temp);
            temp = tempNext;
        }
        free(last);
    }
    return 0;
}
