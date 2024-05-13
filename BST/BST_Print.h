
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

