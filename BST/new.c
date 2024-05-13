#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int d) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = d;
    root->left = NULL;
    root->right = NULL;
    return root;
}

Node* insertintoBST(Node* root, int d) {
    if (root == NULL) {
        root = newNode(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertintoBST(root->right, d);
    } else {
        root->left = insertintoBST(root->left, d);
    }

    return root;
}

Node* takeinput(Node* root) {
    int data;
    scanf("%c", &data);
    while (data != -1) {
        root = insertintoBST(root, data);
        scanf("%c", &data);
    }
    return root;
}

typedef struct stack {
    int top;
    int size;
    Node** arr;
} stack;

int isFull(stack* s) {
    if (s->top == s->size - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(stack* s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

void push(stack* s, Node* k) {
    if (isFull(s)) {
        printf("Overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = k;
    }
}

void pop(stack* s) {
    if (isEmpty(s)) {
        printf("Underflow\n");
    } else {
        s->top--;
    }
}

Node* peek(stack* s) {
    return s->arr[s->top];
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;

    printf("Enter info ");
    root = takeinput(root);
    printf("\n");
    postorder(root);

    return 0;
}








