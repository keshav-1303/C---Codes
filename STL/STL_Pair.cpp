#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

int main(){

    pair<int, string> p;    // require #include <utility>
    p = {2, "abcd"};
    cout << p.first << " " << p.second << endl;

    // If not initialized, the first value of the pair gets automatically initialized. 

    vector<pair<int, string>> v;
    pair<int, string> temp1 = {1, "keshav"};
    v.pb(temp1);
    pair<int, string> temp2 = {2, "abcd"};
    v.pb(temp2);
    pair<int, string> temp3 = {3, "asdf"};
    v.pb(temp3);

    swap(v[0], v[1]);

    for(int i=0 ; i<3  ;i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

    // tie() in pair.

    
 
    return 0;
}

