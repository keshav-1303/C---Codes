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
#define ll long long int

int main(){

    ll t;   cin >> t;

    while(t--){

        ll n;    cin >> n;

        vector<ll> v;      inputVector(v, n);

        if (n == 1){
            cout << v[0] << endl;
        }

        else{

            ll l, r;
            for (ll i = 0; i < n; i++){
                if (v[i] == n)
                    r = i - 1;
            }

            if (r == -1){
                for (ll i = 0; i < n; i++){
                    if (v[i] == n - 1)
                        r = i - 1;
                }
            }

            l = 0;
            for (ll i = r - 1; i >= 0; i--){
                if (v[i] < v[0]){
                    l = i + 1;
                    break;
                }
            }
            
            if (r == n - 2 && v[r] < v[0]){
                r = n - 1;
                l = r;
            }

            vector<ll> ans;
            
            for (ll i = r + 1; i < n; i++)
                ans.push_back(v[i]);
            for (ll i = r; i >= l; i--)
                ans.push_back(v[i]);
            for (ll i = 0; i < l; i++)
                ans.push_back(v[i]);
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}