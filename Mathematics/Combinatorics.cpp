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

// https://cp-algorithms.com/algebra/factorial-divisors.html#implementation
// You are given two numbers n and k. Find x (the largest power of k such that n! is divisible by k ^ x) .

int When_k_is_Prime(int n, int k){

    int ans = 0;

    while(n){
        n = n / k;
        ans += n;
    }
    return ans;
}

int When_k_is_Composite(int n, int k){

}
                                                                                                  
int main(){



    return 0;
}