#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;

    node(int d){
        this->data = d;
        this->left = NULL;  
        this->right = NULL;
    }
};

node* buildTree(node* root){

    int data;     cout << "Enter root data : ";     cin >> data;
    root = new node(data);

    if(data == -1)     return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void printSpace(double n, node* removed){

    for( ; n>0 ; n--)    cout << "\t";
    if (removed == NULL)    cout << " ";
    else    cout << removed->data;
}
 
int heightOfTree(node* root){

    if (root == NULL)    return 0;
    return 1 + max(heightOfTree(root->left),heightOfTree(root->right));
}
 
void print_Binary_Tree(node* root){

    queue<node*> treeLevel, temp;
    treeLevel.push(root);
    int counter = 0;
    int height = heightOfTree(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;
    while (counter <= height) {
        node* removed = treeLevel.front();
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

int main(){

    node *root = NULL;
    root = buildTree(root);

    print_Binary_Tree(root);
    
    return 0;
}

