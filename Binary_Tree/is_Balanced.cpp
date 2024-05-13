// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

pair<bool , int> isbalancedfast(Node* root){
    
    if(root == NULL){
        pair<bool, int> p = make_pair(1, 0);
        return p;
    }
    
    pair<bool, int> left = isbalancedfast(root->left);
    pair<bool, int> right = isbalancedfast(root->right);
    
    bool diff = abs(left.second - right.second) <= 1;   
    
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    
    if(left.first && right.first && diff){
        ans.first = 1;
    }
    else    ans.first = 0;
    
    return ans;
    
}

bool isBalanced(Node *root)
{
    if(isbalancedfast(root).first)    return 1;
    return 0;
}