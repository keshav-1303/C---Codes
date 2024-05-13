#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node *reverseLinkedList(struct Node *head) {  // Iterative Solution

    if(head == NULL  ||  head -> next == NULL){
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;

    return head;
}

void PrintList(struct Node* head){
    struct Node *p = head;

    while(p != NULL){
        cout << "data : " << p -> data;
        cout << endl;
        p = p -> next;
    }

    cout << endl;
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
    PrintList(head);

    head = reverseLinkedList(head);

    cout << "Reversed List..." << endl;
    PrintList(head);
}