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

void Reverse(string &str){

    stack<char> s;

    for(int i=0 ; i<str.size() ; i++){
        s.push(str[i]);
    }

    str = "";

    while(!s.empty()){
        str = str + s.top();
        s.pop();
    }
}

int main(){

    string s = "keshav";

    Reverse(s);

    cout << s << endl;
    
    return 0;
}

