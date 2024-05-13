#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

/*
Given the total number of children n, a number i to start the counting from and a number k which indicates that k-1 children are skipped in each turn and the k-th child exits the circle. 
The task is to find the place in the initial circle (winning position), so that the child standing there would be the winner at last
*/

struct node{
    int data;
    struct node* next;
};

struct node* inHead(struct node* head, int key){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = key;
    p->next = head;
    return p;
}

void print(struct node* head){
    struct node* p = head;
    while(p->next != NULL){
        cout << p->data << " ";
        p = p-> next;
    }
    cout << endl;
}

int solve(struct node* head, int i, int k){

    struct node* p = head;

    int temp = 0;

    while(temp < i - 1){
        p = p-> next;
        temp++;
    }

    while(p->next != p){

        p->next = p->next->next;

        int count = 0;

        while(count < k-1){
            p = p->next;
            count++;
        }
    }

    return p->data;
}

int main(){

    int N, k, i;

    cout << "\nEnter n : ";     cin >> N;
    cout << "Enter i : ";     cin >> i;
    cout << "Enter k : ";     cin >> k;

    int count = N - 1;

    struct node* v = (struct node*)malloc(sizeof(struct node));
    v->data = N;
    v->next = NULL;

    struct node* head = v;
    struct node* first = v;

    for(int i=1 ; i<N ; i++){
        head = inHead(head, count--);
    }

    first->next = head;

    cout << "\nPerson at position " << solve(head, i, k) << " survives\n" << endl;
 
    return 0;
}

