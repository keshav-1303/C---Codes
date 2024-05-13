#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}Node;

void Print(Node* head){
    Node* p = head;
    while(p != NULL){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main(){

    Node* n1, *n2, *n3;
    Node* n4, *n5, *n6;

    n1 = (Node*)malloc(sizeof(Node));
    n2 = (Node*)malloc(sizeof(Node));
    n3 = (Node*)malloc(sizeof(Node)); 

    n4 = (Node*)malloc(sizeof(Node));
    n5 = (Node*)malloc(sizeof(Node));
    n6 = (Node*)malloc(sizeof(Node));

    n1 -> data = 1;     n2 -> data = 2;     n3 -> data = 3;
    Node* head1 = n1;

    n4 -> data = 4;     n5 -> data = 5;     n6 -> data = 6;
    Node* head2 = n4;

    n1 -> next = n2;    n2 -> next = n3;    n3 -> next = NULL;
    n4 -> next = n5;    n5 -> next = n6;    n6 -> next = NULL;

    cout << "List 1 : ";     Print(head1);
    cout << "List 2 : ";     Print(head2);

    n3 -> next = n4;

    cout << "Concatenated List : ";     Print(head1);
 
    return 0;
}

