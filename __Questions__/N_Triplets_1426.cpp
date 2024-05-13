#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define printVector(v, n)  for(auto i = 0; i < n; i++) {cout << v[i] << " ";} 
#define printDeque(d, n)   for(auto i = 0; i < n; i++) {cout << d[i] << " ";}  cout << endl; 
#define printArr(arr, n)   for(auto i = 0; i < n; i++) {cout << arr[i] << " ";}  cout << endl; 
#define MOD 1000000007
#define PI 3.14159265359
#define ll long long int
using namespace std;

vector<ll> divisors(ll n){
    vector<ll> v;
    for(int i=1; i<sqrt(n); i++){
        if(n % i == 0)   v.pb(i);
    }
    return v;
}

int main(){
    int T;    cin >> T;
    while(T--){

        ll n;    cin >> n;
        
        vector<ll> v = divisors(n);
        
        cout << "divisors are : " << for(auto i = 0; i < v.size(); i++) {cout << v[i] << " ";}  << endl;
        
        if(v.size() < 3)    cout << -1 << endl;
        
        else{
         for(int i=v.size()-1; i>=v.size()-3; i--)    cout << v[i] << " ";
            cout << endl;
        }
    }
	return 0;
}
