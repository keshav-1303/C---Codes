#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

typedef struct q{

    int size;
    int front;
    int rear;
    int *arr;
} Queue ;

bool isFull(Queue* q){
    return (q->rear == q->size - 1);
}

bool isEmpty(Queue* q){
    return (q->front == q->rear);
}

void push(Queue* q, int k){

    if(isFull(q)){
        cout << "Queue FUll" << endl;
    }
    else{
        // q->rear = (q->rear + 1) % q->size;
        q->rear++;
        q->arr[q->rear] = k;
    }
}

void pop(Queue* q){

    if(isEmpty(q)){
        cout << "Queue EMPTY" << endl;
    }
    else{
        q->front++;
        q->arr[q->front] = 0;

        if(q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }
    }
}

void printq(Queue* q){
    int i = q->front + 1;
    for( ; i <= q->rear ; i++){
        cout << q->arr[i] << " ";
    }
    cout << endl;
}

int main(){

    Queue* q = (Queue*)malloc(sizeof(Queue));

    q->size = 8;

    q->front = 2;
    q->rear  = 2;

    q->arr = (int*)malloc(q->size * sizeof(int));

    push(q, 2);
    push(q, 3);
    push(q, 4);

    printq(q);
    
    return 0;
}

