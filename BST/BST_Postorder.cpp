#include <bits/stdc++.h>
using namespace std;

class Node{

public:

    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertintoBST(Node* root, int d){

    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data)    root->right = insertintoBST(root->right, d);

    else    root->left = insertintoBST(root->left, d);
}

Node* takeinput(Node* root){

    int data;    cin >> data;

    while(data != -1){
        root = insertintoBST(root, data);
        cin >> data;
    }
    return root;
}

void postorder_iterative(Node* root){

    if (root == NULL) {
        return;
    }
 
    stack<Node*> s;
    s.push(root);
 
    stack<int> ans;
 
    while (!s.empty()){
        // pop a node from the stack and push the data into the ansput stack
        Node* curr = s.top();
        s.pop();
 
        ans.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}

void postorder_recursion(Node* root){

    if(root == NULL)    return ;

    postorder_recursion(root->left);

    postorder_recursion(root->right);

    printf("%d ", root->data);
}

int main(){

    Node* root = NULL;

    cout << "Enter data for BST ..." << endl;
    root = takeinput(root);

    printf("\nRecursive --> \n");
    postorder_recursion(root);
    printf("\n");

    printf("\nIterative --> \n");
    postorder_iterative(root);
 
    return 0;
}

