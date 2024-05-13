#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Structure for a queue node
typedef struct QueueNode {
    Node* node;
    struct QueueNode* next;
} queue;

// Function to create a new queue node
queue* createQueueNode(Node* node) {
    queue* queueNode = (queue*)malloc(sizeof(queue));
    if (queueNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queueNode->node = node;
    queueNode->next = NULL;
    return queueNode;
}

// Function to check if the queue is empty
int isEmpty(queue* front) {
    return (front == NULL);
}

// Function to enqueue a node into the queue
void enqueue(queue** front, queue** rear, Node* node) {
    queue* queueNode = createQueueNode(node);
    if (isEmpty(*front))
        *front = queueNode;
    else
        (*rear)->next = queueNode;
    *rear = queueNode;
}

// Function to dequeue a node from the queue
Node* dequeue(queue** front, queue** rear) {
    if (isEmpty(*front))
        return NULL;
    queue* temp = *front;
    Node* node = temp->node;
    *front = (*front)->next;
    free(temp);
    if (*front == NULL)
        *rear = NULL;
    return node;
}

// Function for level order traversal of a BST
void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    queue* front = NULL;
    queue* rear = NULL;

    // Enqueue the root node
    enqueue(&front, &rear, root);

    while (!isEmpty(front)) {
        // Dequeue the front node
        Node* current = dequeue(&front, &rear);

        // Process the current node
        printf("%d ", current->data);

        // Enqueue the left child if it exists
        if (current->left != NULL)
            enqueue(&front, &rear, current->left);

        // Enqueue the right child if it exists
        if (current->right != NULL)
            enqueue(&front, &rear, current->right);
    }
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Test the level order traversal of a BST
int main() {
    // Create the binary search tree
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    // Perform the level order traversal
    printf("Level order traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the BST
    free(root->left->right);
    free(root->left->left);
    free(root->right->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}