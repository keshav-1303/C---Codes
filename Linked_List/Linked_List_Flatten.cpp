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

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* insertatHead(Node* head, int k){
    
    Node* p;
    p -> data = k;
    p -> next = head;
    
    return p;
}
    
Node *flatten(Node *root){
    
   Node* p = root;
   
   vector<int> v;
   
   while(p != NULL){
       
       Node* ptr = p;
       
       while(ptr != NULL){
           v.pb(ptr -> data);
           ptr = ptr -> bottom;
       }
       
       p = p -> next;
       
   }
   
   sort(v.begin(), v.end(), greater<int>());
   
   for(auto i : v)    cout << i << " ";
   cout << endl;
   
   Node* head;
   
   head -> data = v.back();
   head -> next = NULL;
   v.pop_back();
   
//   for(int i=1 ; !v.empty() ; i++){
//       head = insertatHead(head, v.back());
//       v.pop_back();
//   }
   
   return head;
}

int main(){


 
    
    return 0;
}

