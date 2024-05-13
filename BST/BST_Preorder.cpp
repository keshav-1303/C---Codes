#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

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

// 1. Create an empty stack NodeStack and push root Node to stack.
// 2. Do the following while NodeStack is not empty.
//      Pop an item from the stack and print it.
//      Push right child of a popped item to stack.
//      Push left child of a popped item to stack.

void preorder_iterative(Node* root){

    if(root == NULL){
        return ;
    }

    stack<Node*> NodeStack;
    NodeStack.push(root);
 
    while (!NodeStack.empty()) {

        Node* Node = NodeStack.top();
        cout << Node->data << " ";
        NodeStack.pop();
 
        if (Node->right)
            NodeStack.push(Node->right);
            
        if (Node->left)
            NodeStack.push(Node->left);
    }
}

void preorder_recursion(Node* root){

    if(root == NULL)    return ;

    printf("%d ", root->data);

    preorder_recursion(root->left);

    preorder_recursion(root->right);
}

int main(){

    Node* root = NULL;

    cout << "Enter data for BST ..." << endl;
    root = takeinput(root);

    printf("\nRecursive --> \n");
    preorder_recursion(root);
    printf("\n");

    printf("\nIterative --> \n");
    preorder_iterative(root);
 
    return 0;
}

