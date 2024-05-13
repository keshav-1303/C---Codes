#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
using namespace std;

int main(){    // follows FIFO
    
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
  
    cout << "The queue q is : ";
    // print(q);
  
    cout << "\nq.size() : " << q.size();
    cout << "\nq.front() : " << q.front();
    cout << "\nq.back() : " << q.back();
  
    cout << "\nq.pop() : ";
    q.pop();
    // print(q);
  
    return 0;
}
