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
    // cout << "Enter node data : ";     
    cin >> data;
    root = new node(data);

    if(data == -1)     return NULL;

    // cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    // cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrder(node* root){
    
    if(root == NULL){
        return ;
    }
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        
        node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        
        if(temp->left != NULL){
            q.push(temp->left);
        }
        
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

int main(){

    node *root = NULL;
    cout << "Enter data : " ;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    levelOrder(root);

    return 0;
}



