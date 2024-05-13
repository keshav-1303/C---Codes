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

bool search(Node* root, int key){

    if(root == NULL)    return 0;
    if(root->data == key)     return 1;

    if(root->data > key)    search(root->left, key);
    else    search(root->right, key);
}

Node* minValue(Node* root){     // leftmost value is minimum
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){      // rightmost value is largest
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteNode(Node* root, int key){
    
    if(root == NULL)    return root;

    if(root->data == key){

        // 0 child OR 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // 2 child
        // Get the inorder successor (smallest in the right subtree)
        Node* mini = minValue(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = mini->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, mini->data);
    }

    else if(root->data > key){
        root->left = deleteNode(root->left, key);
        return root;
    }

    else{
        root->right = deleteNode(root->right, key);
        return root;
    }
}

int main(){

    Node* root = NULL;

    cout << "Enter data for BST ..." << endl;
    root = takeinput(root);

    cout << "Minvalue is " << minValue(root) << endl;
    cout << "Maxvalue is " << maxValue(root) << endl;
 
    return 0;
}

