#include <bits/stdc++.h>
using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
};


void PrintList(struct node*);


struct node* Insert_at_Head(struct node*, int);
struct node* Insert_at_End(struct node*, int);
struct node* Insert_in_Between(struct node*, int, int);
struct node* Insert_after_Node(struct node*, struct node*, int);


struct node* Delete_from_Head(struct node*);
struct node* Delete_from_End(struct node*);
struct node* Delete_from_Between(struct node*, int);
struct node* Delete_Node(struct node*, struct node*);


int main(){

    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    struct node* n2 = (struct node*)malloc(sizeof(struct node));
    struct node* n3 = (struct node*)malloc(sizeof(struct node));

    n1 -> data = 12;
    n2 -> data = 121;
    n3 -> data = 129;

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL;

    struct node *head = n1;

    cout << "\nOriginal List..." << endl;
    PrintList(head);

// "Insertion Operations--------------------------------------------------------------";

    // head = Insert_at_Head(head, 56);
    // cout << "After inserting at HEAD..." << endl;
    // PrintList(head);

    // head = Insert_in_Between(head, 56, 1);
    // cout << "After inserting in BETWEEN..." << endl;
    // PrintList(head);

    // head = Insert_at_End(head, 56);
    // cout << "After inserting at END..." << endl;
    // PrintList(head);

    // head = Insert_after_Node(head, n2, 56);     // in this case insert after n2.
    // cout << "On inserting after n2..." << endl;
    // PrintList(head);

// -----------------------------------------------------------------------------------;


// "Deletion Operations--------------------------------------------------------------";

    // head = Delete_from_Head(head);
    // cout << "After deleting HEAD..." << endl;
    // PrintList(head);

    // head = Delete_from_Between(head, 1);
    // cout << "After deleting from BETWEEN..." << endl;
    // PrintList(head);

    // head = Delete_from_End(head);
    // cout << "After deleting END..." << endl;
    // PrintList(head);

    // head = Delete_Node(head, n2);     // in this case insert after n2.
    // cout << "On deleting after n2..." << endl;
    // PrintList(head);

// -----------------------------------------------------------------------------------;
    return 0;
}

void PrintList(struct node* head){
    struct node *p = head;

    while(p != NULL){
        cout << "data : " << p -> data;
        cout << endl;
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
        // should not be p -> next = NULL bec it will point to NULL not last element
        p = p -> next;
    }

    ptr -> data = value;
    p -> next = ptr;
    ptr -> next = NULL;

    return head;
}

struct node* Insert_in_Between(struct node *head, int value, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    int i = 0;

    while(i != index - 1){
        p = p -> next;
        i++;
    }

    ptr -> data = value;
    ptr -> next = p -> next;
    p -> next = ptr;
    
    return head;
}

struct node* Insert_after_Node(struct node *head, struct node *NODE, int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr -> data = value;

    ptr -> next = NODE -> next;
    NODE -> next = ptr;

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

struct node* Delete_from_Between(struct node *head, int index){
    struct node* p = head;

    int i = 0;

    while(i != index - 1){
        p = p -> next;
        i++;
    }

    p -> next = p -> next -> next;
    
    return head;
}

struct node* Delete_Node(struct node *head, struct node *NODE){
    struct node* p = head;
    while(p -> next != NODE){
        p = p -> next;
    }
    p -> next = p -> next -> next;
    return head; 
}

