// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

int height(Node* root) {
        
    if(root == NULL)     return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    return max(left, right) + 1;
}
