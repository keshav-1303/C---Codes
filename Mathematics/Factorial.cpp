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
#define PI 3.14159265359
#define ll long long int
using namespace std;

int main(){
    
    int n;    cout << "Enter Number : ";    cin >> n;

    ll k = 100000 , MOD = 1e9+7;

    ll fact[k + 1];
	fact[1] = 1;

	for(ll i=2 ; i<=k ; i++){
	    fact[i] = (fact[i-1] * i) % MOD;
	}
    
    cout << fact[100] << endl;

	return 0;
}