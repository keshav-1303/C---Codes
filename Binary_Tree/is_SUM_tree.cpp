// https://practice.geeksforgeeks.org/problems/sum-tree/1

pair<bool, int> isfast(Node* root){
    
    if(root == NULL){
        pair<bool, int> p = make_pair(1, 0);
        return p;
    }
    
    if(root->left == NULL && root->right ==NULL){
        pair<bool, int> p = make_pair(1, root->data);
        return p;
    }
    
    pair<bool, int> left = isfast(root->left);
    pair<bool, int> right = isfast(root->right);
    
    int sum = left.second + right.second;
    
    pair<bool, int> ans;
    ans.second = sum + root->data;
    
    if(left.first && right.first && sum == root->data){
        ans.first = 1;
    }
    else    ans.first = 0;
    
    return ans;
}

bool isSumTree(Node* root){
    
    if(isfast(root).first)     return 1;
    return 0;
}