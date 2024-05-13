#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
    node(){
        data = 0;
        next = NULL;
    }
};

void PrintList(struct node*);

struct node* Insert_at_End(struct node*, int);

struct node* mergesort(struct node*);

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
        Insert_at_End(head, k);
    }

    cout << "Original Linked List : ";
    PrintList(head);

    mergesort(head);

    cout << "Sorted  Linked  List : ";
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

struct node* merge(node* left, node* right){
     
    // struct node* curr = ;
    // curr -> next = NULL;

    struct node *dummyHead = new node();
    struct node *curr = dummyHead;

    while(left != NULL  &&  right != NULL){

        if(left->data < right->data){
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }

        else{
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }
    }

    while(left != NULL){
        curr->next = left;
        left = left->next;
        curr = curr->next;
    }

    while(right != NULL){
        curr->next = right;
        right = right->next;
        curr = curr->next;
    }

    return dummyHead;
}

struct node* Middle(struct node* head){

    struct node* fast = head->next;
    struct node* slow = head;

    while(fast != NULL  &&  fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

struct node* mergesort(struct node* start){

    if(start->next == NULL){    // only 1 element in list
        return start;
    }

    // finding middle of the list using tortoise and hare approach
    struct node* mid = Middle(start);
    struct node* right_of_start = mid->next;

    mid->next = NULL;     // breaking the linked list into two parts

    struct node* left = mergesort(start);
    struct node* right = mergesort(right_of_start);
    struct node* new_start = merge(left, right);

    return new_start;
}


