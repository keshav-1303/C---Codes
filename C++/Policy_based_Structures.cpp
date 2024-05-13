#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }
#define MOD 1000000007
#define PI 3.14159265359
#define ll long long int
using namespace std;
using namespace __gnu_pbds;

int main(){
    
    indexed_set<int> s;

    s.insert(0);
    s.insert(1);
    s.insert(1);
    s.insert(3);

    // cout << s[2];
    return 0;
}