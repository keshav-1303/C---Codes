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

// https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

void inorder(node* root, deque<int> &ans){
    
    if(root == NULL)    return ;

    inorder(root->left, ans);
    
    ans.push_back(root->data);

    inorder(root->right, ans);
}

pair<int,int> predecessorSuccessor(node* root, int key){
    
    deque<int> in;
    inorder(root, in);

    int ans1, ans2;

    in.push_front(-1);
    in.push_back(-1);

    for(int i=0 ; i<in.size() ; i++){
        if(in[i] == key){
            ans1 = in[i - 1];
            ans2 = in[i + 1];
            break;
        }
    }

    pair<int, int> p = make_pair(ans1, ans2);
    
    return p;    
}

int main(){

    node *root = NULL;
    cout << "Enter data : " ;
    root = buildTree(root);

    // 59 -1 104 -1 120 -1 158 -1 165 -1 190 -1 193 -1 199 -1 200 -1 -1
    // key = 158
    // answer must be = 120, 165     

    int key;    cout << "Enter key : ";     cin >> key;

    pair<int, int> p = predecessorSuccessor(root, key);

    cout << "Predecessor = " << p.first << endl;
    cout << "Successor = " << p.second << endl;
    
    return 0;
}
