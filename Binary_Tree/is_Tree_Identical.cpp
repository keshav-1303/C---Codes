// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

bool isIdentical(Node *r1, Node *r2){
        
        if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){
            return 0;
        }
        
        if(r1 == NULL && r2 == NULL)    return 1;
        
        if(r1 != NULL && r2 != NULL){
            if(r1->data != r2->data)    return 0;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        if(left && right)    return 1;
    }