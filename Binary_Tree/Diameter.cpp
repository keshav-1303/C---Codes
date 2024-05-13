// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

int height(Node* root) {
    
    if(root == NULL)     return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    return max(left, right) + 1;
}

int diameterNaive(Node* root) {
    
    if(root == NULL)    return 0;
    
    int op1 = diameterNaive(root->left);
    int op2 = diameterNaive(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    
    return max(op1, max(op2, op3));     // i.e max(op1, op2, op3);
}

pair<int,int> diameterFast(Node* root) {

    //base case
    if(root == NULL) {
        pair<int,int> p = {0, 0};
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int,int> ans;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second , right.second) + 1;
    
    return ans;
}

int diameter(Node* root) {
    return diameterFast(root).first;
}



