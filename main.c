#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary search tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* delete(Node* root, int data);
Node* search(Node* root, int data);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);

int main() {
    Node* root = NULL;

    // Inserting nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    // Searching for a node
    int searchValue = 40;
    Node* foundNode = search(root, searchValue);
    if (foundNode)
        printf("Node with value %d found.\n", foundNode->data);
    else
        printf("Node with value %d not found.\n", searchValue);

    // Deleting a node
    root = delete(root, 20);
    printf("In-order after deletion of 20: ");
    inOrder(root);
    printf("\n");

    return 0;
}

// Function implementations...
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
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

Node* delete(Node* root, int data) {
    // Deletion logic here...
    return root; // Placeholder
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}