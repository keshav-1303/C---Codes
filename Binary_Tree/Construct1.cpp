// Given 2 Arrays of Inorder and preorder traversal. 
// The tree can contain duplicate elements. 
// Construct a tree and print the Postorder traversal. 

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

class Solution{
    public:
    //-------------------------------------------------------------------------
    
    Node* solve(int in[], int pre[], int n, int &postorderIndex, int s, int e, map<int, queue<int>> &m){
        
        if(postorderIndex >= n || s > e)
            return NULL;
            
        int element = pre[postorderIndex++];
        
        Node* root = new Node(element);
        
        int position = m[element].front();
        m[element].pop();
            
        root->left = solve(in, pre, n, postorderIndex, s, position-1, m);
        root->right = solve(in, pre, n, postorderIndex, position+1, e, m);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n){
        
        map<int, queue<int>> Node_to_Index;
        
        for(int i=0 ; i<n ; i++)
            Node_to_Index[in[i]].push(i);
            
        int prepostorderIndex = 0;
        return solve(in, pre, n, prepostorderIndex, 0, n-1, Node_to_Index);
    }
};//----------------------------------------------------------------------------

int main(){

	int n;
	cin >> n;

    // For input ...
    // 7
    // 7 3 11 1 17 3 18
    // 1 3 7 11 3 17 18

    // Output must be ...
    // 7 11 3 17 18 3 1
	
	int inorder[n], preorder[n];
	for(int i=0; i<n; i++)
		cin>> inorder[i];
	for(int i=0; i<n; i++)
		cin>> preorder[i];
	Solution obj;
	Node *root = obj.buildTree(inorder, preorder, n);
	printPostOrder(root);
	cout<< endl;

}
