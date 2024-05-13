#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* insert_sorted(struct node *head, int value){

    struct node* p = head;
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));

    while(p -> data < value){
        p = p -> next;
    }

    ptr -> data = value;
    ptr -> next = p -> next;
    p -> next = ptr;

    return head;
}

void Print(struct node* head){
    struct node* p = head;
    while(p !=NULL){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main(){

    struct node* n1, *n2, *n3;
    struct node* n4, *n5, *n6;

    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));
    n3 = (struct node*)malloc(sizeof(struct node)); 
    n4 = (struct node*)malloc(sizeof(struct node));
    n5 = (struct node*)malloc(sizeof(struct node));
    n6 = (struct node*)malloc(sizeof(struct node));

    n1 -> data = 1;     n2 -> data = 2;     n3 -> data = 3;
    n4 -> data = 4;     n5 -> data = 5;     n6 -> data = 6;

    struct node* head = n1;

    n1 -> next = n2;    n2 -> next = n3;    n3 -> next = n4;
    n4 -> next = n5;    n5 -> next = n6;    n6 -> next = NULL;

    cout << "\nOriginal list...\n";
    Print(head);

    int k;    cout << "\nEnter element to insert : ";     cin >> k;

    head = insert_sorted (head, k);

    cout << "\nNew list...\n";
    Print(head);
    
    return 0;
}

