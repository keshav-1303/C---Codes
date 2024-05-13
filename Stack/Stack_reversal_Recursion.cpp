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

void insertatBottom(stack<int> &s, int x){

    if(s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();

    s.pop();

    insertatBottom(s, x);

    s.push(num);
}

void reverseStack(stack<int> &s) {
    if(s.empty()){
        return ;
    }

    int num = s.top();
    s.pop();

    reverseStack(s);

    insertatBottom(s, num);

}


int main(){

    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(9);

    cout << "Original Stack ...\n";
    stack<int> s1 = s;
    while(!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }

    reverseStack(s);

    cout << "\nReversed Stack ...\n";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
 
    return 0;
}

