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
    scanf("%d", &data);
    while (data != -1) {
        root = insertintoBST(root, data);
        scanf("%d", &data);
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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* curr = root;

    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    s->size = maxsize;
    s->arr = (Node**)malloc(maxsize * sizeof(Node*));

    while (!isEmpty(s) || curr != NULL) {
        while (curr != NULL) {
            push(s, curr);
            curr = curr->left;
        }

        curr = peek(s);
        pop(s);

        printf("%d ", curr->data);

        curr = curr->right;
    }

    free(s->arr);
    free(s);
}

int main() {
    Node* root = NULL;

    printf("Enter BST Data -->\n");
    root = takeinput(root);

    inorder(root);
    printf("\n");
    inOrder(root);

    return 0;
}
