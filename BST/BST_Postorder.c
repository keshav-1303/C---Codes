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

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void PostOrder(Node* root) {
    
    if (root == NULL) {
        return;
    }

    Node* curr = root;

    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    s->size = maxsize;
    s->arr = (Node**)malloc(maxsize * sizeof(Node*));

    push(s, root);

    int ans[maxsize];
    int c = maxsize - 1;

    while (!isEmpty(s)){
        // pop a node from the stack and push the data into the ansput stack
        Node* curr = peek(s);
        pop(s);
 
        ans[c--] = curr->data;
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            push(s, curr->left);
        }
 
        if (curr->right) {
            push(s, curr->right);
        }
    }
 
    // print postorder traversal
    for(int i=c+1 ; i<maxsize ; i++){
        printf("%d ", ans[i]);
    }

    free(s->arr);
    free(s);
}

int main() {
    Node* root = NULL;

    printf("Enter BST Data -->\n");
    root = takeinput(root);
    printf("\n");

    PostOrder(root);
    printf("\n");
    postorder(root);

    return 0;
}
