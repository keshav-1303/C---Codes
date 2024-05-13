// Given inorder and postorder traversals of a Binary Tree 
// in the arrays in[] and post[] respectively. 
// The task is to construct the binary tree from these traversals.

//https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

Node* solve(int in[], int post[], int size, int &postOrderIndex, int in_start, int in_end, map<int, queue<int>> &NodetoIndex){
    
    if(postOrderIndex < 0 || in_start > in_end){
        return NULL;
    }
    
    int element = post[postOrderIndex];
    postOrderIndex--;
    
    Node* root = new Node(element);
    
    int position = NodetoIndex[element].front();
    NodetoIndex[element].pop();
    
    root->right = solve(in, post, size, postOrderIndex, position+1, in_end, NodetoIndex);
    root->left = solve(in, post, size, postOrderIndex, in_start, position-1, NodetoIndex);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    
    int postOrderIndex = n-1;
    
    map<int, queue<int>> NodetoIndex;
    
    for(int i=0 ; i<n ; i++){
        NodetoIndex[in[i]].push(i);
    }
    
    int start = 0;
    int end = n-1;
    
    return solve(in, post, n, postOrderIndex, start, end, NodetoIndex);
}