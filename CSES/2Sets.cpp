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
#define inputVector(arr, n)  {for(int i=0 ; i<n ; i++){int t; cin >> t; arr.push_back(t);}}
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

    if(n % 4 == 2 || n % 4 == 1){
        no;
    }

    // YES only if n if of types -> 4k OR 4k+3
    // first n/4 and last n/4 s1 me, baaki saare s2 me
    vector<int> s1, s2;
    int start = 1;

    if(n % 4 == 3){
        s1.push_back(1);
        s1.push_back(2);
        s2.push_back(3);
        start = 4;
    }

    for(int i=start ; i<=n ; i++){
        if(i < start+n/4)   s1.push_back(i);
        else if(i < start + 3*(n/4))   s2.push_back(i);
        else    s1.push_back(i);
    }

    cout << "YES" << endl;
    cout << s1.size() << endl;
    print(s1);
    cout << s2.size() << endl;
    print(s2);
}

signed main(){

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int _ = 1;    
    // cin >> _;

    for(int i=1 ; i<=_ ; i++){
        __________();
    }
}
