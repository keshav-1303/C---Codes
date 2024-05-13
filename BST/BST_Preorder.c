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

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void PreOrder(Node* root) {

    if(root == NULL){
        return ;
    }

    stack* s = (stack*)malloc(sizeof(stack));

    s->arr = (Node**)malloc(maxsize * sizeof(Node*));
    s->top = -1;
    s->size = maxsize;
    push(s, root);
 
    while (!isEmpty(s)) {

        Node* Node = peek(s);
        printf("%d ", Node->data);
        pop(s);
 
        if (Node->right)
            push(s, Node->right);
            
        if (Node->left)
            push(s, Node->left);
    }

    free(s->arr);
    free(s);
}

int main() {
    Node* root = NULL;

    printf("Enter BST Data -->\n");
    root = takeinput(root);

    preorder(root);
    printf("\n");
    PreOrder(root);

    return 0;
}
