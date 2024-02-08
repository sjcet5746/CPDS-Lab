#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the binary tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
// Function to create a new node with the given data
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a node into the binary tree
Node* insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
// Function for inorder traversal of the binary tree and printing its elements
void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
// Function for preorder traversal of the binary tree and printing its elements
void preorderTraversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
// Function for postorder traversal of the binary tree and printing its elements
void postorderTraversal(Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    Node *root = NULL;
    int n, data;
    printf("Enter the number of elements in the binary tree: ");
    scanf("%d", &n);
    printf("Enter the elements of the binary tree:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder traversal of the binary tree: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder traversal of the binary tree: ");
    postorderTraversal(root);
    printf("\n");
    // Freeing memory allocated to the binary tree (optional)
    /*
    void freeTree(Node *root) {
        if (root != NULL) {
            freeTree(root->left);
            freeTree(root->right);
            free(root);
        }
    }
    freeTree(root);
    */
    return 0;
}
