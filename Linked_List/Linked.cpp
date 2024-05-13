#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void Print(struct node* head){
    struct node* p = head;
    while(p !=NULL){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

struct node* insertatEND(struct node* head, int *temp){
    struct node* p = head;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    while(p -> next != NULL){
        p = p -> next;
    }

    ptr -> data = *temp;
    p -> next = ptr;
    ptr -> next = NULL;

    // cout << "in" ;

    return head;
}

struct node* insertatHEAD(struct node* head, int *temp){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    ptr -> data = *temp;
    ptr -> next = head;

    // cout << "insertted";

    return ptr;
}


int main(){

    // int n;    cout << "Enter n : ";     cin >> n;

    struct node* n1;

    int temp;    
    // cout << "Enter value 1 : ";    
    // cin >> temp;
    temp = 34;

    // n1 -> data = temp;
    // n1 -> next = NULL;

    struct node* head = insertatHEAD(head, &temp);  

    // cin >> n1 -> data;
    // n1 -> next = NULL;

    head = insertatEND(head, &temp);

    Print(head);
    
    return 0;
}

