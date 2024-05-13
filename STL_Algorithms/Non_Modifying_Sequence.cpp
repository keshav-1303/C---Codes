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

int main(){

    int count = 0;
    vector<vector<int>> s;

    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            for(int k=0 ; k<10 ; k++){
                if(i + j + k == 13){
                    vector<int> v;
                    v.pb(i);    v.pb(j);    v.pb(k);
                    sort(v.begin(), v.end());
                    s.pb(v);
                }
            }
        }
    }

    sort(s.begin(), s.end());

    s.erase( unique(s.begin(), s.end()), s.end() );
 
    for(int i=0 ; i<s.size() ; i++){
        print(s[i]);        
    }

}

