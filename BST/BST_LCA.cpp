// LCA == Lowest Common Ancestor
// https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=0

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
    cin >> data;
    root = new node(data);

    if(data == -1)     return NULL;

    root->left = buildTree(root->left);

    root->right = buildTree(root->right);

    return root;
}

node* LCAinaBST(node* root, int a, int b){

    if(root == NULL)    return NULL;

	if(root->data < a && root->data < b){
        return LCAinaBST(root->right, a, b);
    }

    if(root->data > a && root->data > b){
        return LCAinaBST(root->left, a, b);
    }

    return root;
}

int main(){

    node *root = NULL;
    cout << "Enter data : " ;
    root = buildTree(root);     

    int a;    cout << "Enter a : ";     cin >> a;
    int b;    cout << "Enter b : ";     cin >> b;

    // a, b = 8, 19
    // BST = 2 1 13 -1 -1 8 19 4 -1 17 20 -1 -1 -1 -1 -1 -1
    // answer must be 13

    node* ans = LCAinaBST(root, a, b);

    cout << "LCA of " << a << " and " << b << " is " << ans->data << endl;
    
    return 0;
}
