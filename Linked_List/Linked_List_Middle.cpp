#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

int len(struct Node* head){
    struct Node* p = head;
    int len = 0;
    while(p != NULL){
        cout << p -> data << " ";
        p = p -> next;
        len++;
    }
    cout << endl;
    return len;
}

struct Node *findMiddle(struct Node *head) {

    struct Node* p = head;

    int length = len(head);

    int i = 0;

    int stop = (length & 1) ? length/2 : length/2 + 1 ;

    while(i != stop){
        p = p -> next;
        i++;
    }
    
    return p;
}

int main(){

    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    n1 -> data = 12;
    n2 -> data = 121;
    n3 -> data = 122;

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL;

    head = n1;

    cout << "\nOriginal List..." << endl;

    struct Node* p = findMiddle(head);

    cout << "Middle element is " << p -> data << endl;
}