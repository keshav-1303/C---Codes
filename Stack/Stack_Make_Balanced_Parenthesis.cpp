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

int findMinimumCost(string &str) {
  
    if(str.size() & 1)   return -1;

    int count = 0, count_ = 0;

    stack<char> s;

    for(int i=0 ; i<str.size() ; i++){
        if(str[i] == '{'){
            s.push(str[i]);
        }

        else{

          if (s.top() == '{' && !s.empty()) {
            s.pop();
          }

          else{
              s.push(str[i]);
          }
        }
    }

    while(!s.empty()){
        if(s.top() == '}')     count++;
        else    count_++;
        s.pop();
    }
    
    return (count + 1) / 2 + (count_ + 1) / 2;
}

int main(){

    string s = "{{{}";

    cout << findMinimumCost(s) << endl;
    
    return 0;
}

