#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

class Solution{
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head){
        
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
    
    struct Node* insert_at_tail(struct Node* head, int key){
        
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        struct Node* p = head;

        while(p -> next != NULL){     
            // should not be p -> next = NULL bec it will point to NULL not last element
            p = p -> next;
        }

        ptr -> data = key;
        p -> next = ptr;
        ptr -> next = NULL;

        return head;
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        
        int carry = 0;
        struct Node* ans = (struct Node*)malloc(sizeof(struct Node));

        // printList(first);
        // printList(second);
        
        while(first != NULL && second != NULL){
            int sum = carry + first->data + second->data;
            
            int digit = sum % 10;
            
            carry = sum / 10;
            
            ans = insert_at_tail(ans, digit);

            printList(ans);
            
            first = first->next;
            second = second->next;
        }
        
        while(first != NULL){
            ans = insert_at_tail(ans, first->data);
            first = first->next;
        }
        
        while(second != NULL){
            ans = insert_at_tail(ans, second->data);
            second = second->next;
        }
        
        return ans;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second){
        
        first = reverse(first);
        second = reverse(second);
        
        struct Node* ans = add(first, second);
        
        ans = reverse(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    
        int n, m;
        
        cout << "Enter length of 1st number : ";
        cin>>n;
        Node* first = buildList(n);
        
        cout << "Enter length of 2nd number : ";
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    
    return 0;
}

// } Driver Code Ends