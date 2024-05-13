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

void rev(queue<int> &q){
    
    if(q.empty()){
        return ;
    }
    
    int num = q.front();
    
    q.pop();
    
    rev(q);
    
    q.push(num);
}

int main(){
 
    queue<int> q ;

    q.push(4);
    q.push(6);
    q.push(1);
    q.push(3);
    q.push(5);
    q.push(2);

    cout << "\nOriginal queue ...\n";
    queue<int> q1 = q;
    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    rev(q);

    cout << "\nReversed queue ...\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl << endl;

    return 0;
}

