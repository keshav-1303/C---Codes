// https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan

#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head){

    map<int, bool> visited;

    Node* prev = head;
    Node* curr = head->next;

    visited[head->data] = 1;

    while(curr != NULL){

        if(visited[curr->data] == 1){
            Node* forward = curr->next;
            prev->next = curr->next;
            curr->next = NULL;
            curr = forward;
        }

        else {

            prev = curr;
            visited[curr->data] = 1;
            curr = curr->next;
        }
    }

    return head;
}

