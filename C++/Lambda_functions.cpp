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
#define MOD 1000000007
#define PI 3.14159265359
#define ll long long int
using namespace std;

int main(){
    
    vector<int> v = { 1, 2, 3, 4, 5 };

    auto sum = accumulate(v.begin()+start, v.begin()+end, [](vector<int> &v, int start, int end){
        return ;
    });

    cout << sum(v,0,4);
	return 0;
}