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

// 1. Create an empty stack (say S).
// 2. Initialize the curr node as root.
// 3. Push the curr node to S and set curr = curr->left until curr is NULL
// 4. If curr is NULL and the stack is not empty then:
//      Pop the top item from the stack.
//      Print the popped item and set curr = popped_item->right 
//      Go to step 3.
// If curr is NULL and the stack is empty then we are done.

void inorder_iterative(Node* root){

    stack<Node*> s;
    Node* curr = root;
 
    while (curr != NULL || !s.empty()) {
         
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
 
        // curr must be NULL at this point
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";

        curr = curr->right;
    }
}

void inorder_recursion(Node* root){

    if(root == NULL)    return ;

    inorder_recursion(root->left);

    printf("%d ", root->data);

    inorder_recursion(root->right);
}

int main(){

    Node* root = NULL;

    cout << "Enter data for BST ..." << endl;
    root = takeinput(root);

    printf("\nRecursive --> \n");
    inorder_recursion(root);
    printf("\n");

    printf("\nIterative --> \n");
    inorder_iterative(root);
 
    return 0;
}

