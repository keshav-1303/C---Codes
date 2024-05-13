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

void inorder(node* root, vector<int> &ans){

    if(root == NULL)    return ;

    inorder(root->left, ans);

    ans.push_back(root->data);

    inorder(root->right, ans);
}

bool isSorted(vector<int> &v){
    
    for(int i=0 ; i<v.size()-1 ; i++){
        if(v[i + 1] < v[i]){
            return 0;
        }
    }
    return 1;
}

bool validateBST(node *root) {

    vector<int> v;
    
    inorder(root, v);

    if(v.empty())    return 1;

    return isSorted(v);
    
}

int main(){

    node *root = NULL;
    cout << "Enter data : " ;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1      -should give "NO"

    cout << "Is BST Valid ? --> " << validateBST(root) << endl;
    
    return 0;
}
