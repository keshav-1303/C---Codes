#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void PrintList(struct node*);

struct node* Insert_at_Head(struct node*, int);
struct node* Insert_at_End(struct node*, int);

struct node* Delete_from_Head(struct node*);
struct node* Delete_from_End(struct node*);

int main(){

    int n;    cout << "Enter n : ";    cin >> n;

    cout << "Enter ARRAY : ";

    struct node* n1 = (struct node*)malloc(sizeof(struct node));

    int temp;     cin >> temp;

    n1 -> data = temp;
    n1 -> next = NULL;

    struct node *head = n1;

    for(int i=1 ; i<n ; i++){
        int k;     cin >> k;
        head = Insert_at_End(head, k);
    }

    cout << "Linked List : ";
    PrintList(head);

    return 0;
}

void PrintList(struct node* head){
    struct node *p = head;

    while(p != NULL){
        cout << p -> data << " ";
        p = p -> next;
    }

    cout << endl;
}

struct node* Insert_at_Head(struct node *head, int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> next = head;
    return ptr;    // because ptr is new head
}

struct node* Insert_at_End(struct node *head, int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    while(p -> next != NULL){     
        p = p -> next;
    }

    ptr -> data = value;
    p -> next = ptr;
    ptr -> next = NULL;

    return head;
}

struct node* Delete_from_Head(struct node *head){
    struct node* p = head;
    head = p -> next;
    free(p);
    return head;    // because p is new head
}

struct node* Delete_from_End(struct node *head){
    struct node* p = head;
    while(p -> next -> next != NULL){    // traverse till last 2nd element.  
        p = p -> next;
    }
    p -> next = NULL;
    return head;
}
