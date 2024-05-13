#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

vector<int> rightView(struct Node *root);

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {

    string s;
    getline(cin,s);
    Node* root = buildTree(s);
    vector<int> vec = rightView(root);
    for(int x : vec)
    cout<<x<<" ";
    cout << endl;

    return 0;
}

//Function to return a list containing elements of left view of the binary tree.

int height(Node* root){
    
    if(root == NULL)     return 0;
    
    int lefth = height(root->left);
    int righth = height(root->right);
    
    return max(lefth, righth) + 1;
}

void solve(Node* root, vector<int> &ans){

    if(root == NULL)    return ;

    ans.push_back(root->data);
        
    int lefth = height(root->left);
    int righth = height(root->right);
    
    if(righth >= lefth){
        solve(root->right, ans);
    }
    
    else{
        vector<int> temp1;
        solve(root->right, temp1);
        
        vector<int> temp2;
        solve(root->left, temp2);
        
        int i = 0;
        
        for( ; i<temp1.size() ; i++){
            ans.push_back(temp1[i]);
        }
        for( ; i<temp2.size() ; i++){
            ans.push_back(temp2[i]);
        }
    }
}
    
vector<int> rightView(Node *root){
    
    vector<int> ans;
    
    if(root == NULL){
        return ans;
    }
    solve(root, ans);
    
    return ans;
}
