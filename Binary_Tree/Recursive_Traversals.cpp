#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){

    int data;     
    // cout << "Enter root data : ";     
    cin >> data;
    root = new node(data);

    if(data == -1)     return NULL;

    // cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    // cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void InOrderTraversal(node* root){
    if(root == NULL){
        return ;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(node* root){
    if(root == NULL){
        return ;
    }

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(node* root){
    if(root == NULL){
        return ;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

int main(){

    node *root = NULL;
    cout << "Enter data : " ;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nPrinting in InOrder Traversal..." << endl;
    InOrderTraversal(root);     // 7 3 11 1 17 5

    cout << endl << "\nPrinting in PreOrder Traversal..." << endl;
    PreOrderTraversal(root);     // 1 3 7 11 5 17

    cout << endl << "\nPrinting in PostOrder Traversal..." << endl;
    PostOrderTraversal(root);     // 7 11 3 17 5 1
    
    cout << endl << endl;
    return 0;
}

