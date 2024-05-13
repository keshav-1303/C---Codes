#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

bool isCircular(Node *head){
    
    Node* slow = head;
    Node* fast = head;
    
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow){
            return 1;
        }
    }
    
    return 0;
}

int main(){

    int T, i, n, l, k;

    // 22 0
    // 859 396 30 238 236 794 819 429 144 12 929 530 777 405 444 764 614 539 607 841 905 819

    cin >> n >> k;
    Node *head = NULL, *tail = NULL;
    int x;
    cin >> x;

    head = new Node(x);
    tail = head;

    for (int i = 0; i < n - 1; i++){

        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    if (k == 1 && n >= 1)
        tail->next = head;

    cout << "Is Circular --> " << isCircular(head) << endl;

    return 0;
}