//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


void printSpace(double n, Node* removed){

    for( ; n>0 ; n--)    cout << "\t";
    if (removed == NULL)    cout << " ";
    else    cout << removed->data;
}
 
int heightOfTree(Node* root){

    if (root == NULL)    return 0;
    return 1 + max(heightOfTree(root->left),heightOfTree(root->right));
}
 
void print_Binary_Tree(Node* root){

    queue<Node*> treeLevel, temp;
    treeLevel.push(root);
    int counter = 0;
    int height = heightOfTree(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;
    while (counter <= height) {
        Node* removed = treeLevel.front();
        treeLevel.pop();
        if (temp.empty()) {
            printSpace(numberOfElements / pow(2, counter + 1), removed);
        }
        else {
            printSpace(numberOfElements / pow(2, counter), removed);
        }
        if (removed == NULL) {
            temp.push(NULL);
            temp.push(NULL);
        }
        else {
            temp.push(removed->left);
            temp.push(removed->right);
        }
        if (treeLevel.empty()) {
            cout << endl << endl;
            treeLevel = temp;
            while (!temp.empty())    temp.pop();
            counter++;
        }
    }
}

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void Leftgo(Node* root, vector<int> &ans){
        
        if(root == NULL){
            return ;
        }
        
        if(root->left)    Leftgo(root->left, ans);
        else    Leftgo(root->right, ans);
        
        ans.push_back(root->data);
    }
    
    void Rightgo(Node* root, vector<int> &ans){
        
        if(root == NULL)    return ;
        
        ans.push_back(root->data);
        
        if(root->right)     Rightgo(root->right, ans);
        else    Rightgo(root->left, ans);
    }
    
    vector<int> topView(Node *root){

        // print_Binary_Tree(root);
        
        vector<int> ans;

        // print_Binary_Tree(root->right);
        
        Leftgo(root->left, ans);
        
        ans.push_back(root->data);
        
        Rightgo(root->right, ans);
        
        return ans;
    }

};



//{ Driver Code Starts.

int main() {

        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    
    return 0;
}
// } Driver Code Ends