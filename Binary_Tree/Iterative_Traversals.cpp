#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

vector<int> preorderTraversal(Node* root) {
    vector<int> preorder;
    if(root == NULL)    return preorder;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        preorder.push_back(node->data);
        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left);
        }
    }
    return preorder;
}

vector<int> inorderTraversal(Node* root) {
    vector<int> inorder;
    if(root == NULL)    return inorder;
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        // Reach the left most Node of the curr Node
        while (curr != NULL) {
            // Place pointer to a tree node the stack before traversing the node's left subtree
            s.push(curr);
            curr = curr->left;
        }

        // Current must be NULL at this point
        curr = s.top();
        s.pop();

        inorder.push_back(curr->data);

        curr = curr->right;
    }
    return inorder;
}

vector<int> postorderTraversal(Node* root) {
    vector<int> postOrder;
    stack<Node*> st;
    while(true){
        while(root){
            st.push(root);
            st.push(root);
            root = root->left;
        }
        if(st.empty())    return postOrder;
        root = st.top();
        st.pop();
        if(!st.empty() && st.top() == root){
            root = root->right;
        }
        else{
            postOrder.push_back(root->data);
            root = NULL;
        }
    }
    return postOrder;
}