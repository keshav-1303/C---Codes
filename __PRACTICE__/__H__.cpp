#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    #include "debug.h"
#endif
#ifdef ONLINE_JUDGE
    #define debug(x) 
#endif
using namespace std;
#define int long long int
#define endl "\n"
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define sort_(a)    sort(a.begin(), a.end());
#define sort_rev(a)    {  sort(a.begin(), a.end());    reverse(a.begin(), a.end());  }
int __lcm(int a, int b) {  return (b / __gcd(a, b)) * a; }
int power(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)   res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int power(int a, int b) {int res = 1; while (b > 0) {if (b & 1)   res = (res * a); a = (a * a); b = b >> 1;} return res;}
#define printMatrix(v)  {  for(int i=0 ; i<v.size() ; i++){ for(int j=0 ; j<v[0].size() ; j++){ cout << v[i][j] << " "; }cout << endl; }}
#define yes   {cout << "YES" << endl;   return ;}
#define no   {cout << "NO" << endl;   return ;}
#define println(K)   {cout << K << endl;   return ;}
#define all_(v)    v.begin(), v.end()

void __________(){

    int n;    cin >> n;

    int low = 1, high = n;
    while(high - low > 1){
        cout << "? " << low << " " << high << endl;
        cout << flush;
        int k;   cin >> k;
        
        cout << "? " << low << " " << k << endl;
        cout << flush;
        int left;   cin >> left;

        if(left == k){
            // Search in left part
            high = k - 1;
        }
        else{
            // Search in right part
            low = k + 1;
        }
    }   
    cout << "? " << low << " " << high << endl;
    cout << flush;
    int temp;   cin >> temp;

    if(temp == low){
        cout << "! " << high << endl;
    }
    else{
        cout << "! " << low << endl;
    }
}

signed main(){

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int _ = 1;    
    // cin >> _;

    for(int i=1 ; i<=_ ; i++){
        __________();
    }
}
