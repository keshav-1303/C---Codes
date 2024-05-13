#include <bits/stdc++.h>
using namespace std;

Node* kReverse(Node* head, int k) {

  if(head == NULL  ||  head -> next == NULL)    return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *forward;

    int count = 0;

    while(curr != NULL  &&  count < k){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head -> next =  kReverse(forward, k);       // *************
    }

    head = prev;

    return head;
}