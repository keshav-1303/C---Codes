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

// MISTAKES -->
// 1. Use sgrtl() instead of sqrt() for long long
// 2. GCD of |x-y|?
// 3. Huffman Coding? Merging 2 smallest elements?
// 4. Coordinate Compression?
// 5. Min/Max Spanning Tree.
// 6- Topo sort ? if there is something related to relative ordering.
// 7. Try calculating it in reverse order?
// 8. To check if a number is a power of 2, check if n & (n-1) == 0
// 9. Use (num & (1LL << K)) instead of (num & (1 << K)).

void __________(){

    int n, sum = 0;    cin >> n;

    vector<int> a;
    for(int i=0 ; i<n ; i++){
        int t;   cin >> t;
        a.push_back(t);
		sum += t;
    }

	vector<int> pref(n), suff(n);
	int t = 0;
	for(int i=1 ; i<n ; i++){
		t += (n-i)*a[i];
	}
	suff[0] = t;
	for(int i=1 ; i<n ; i++){
		t = t - (n-1)*a[i] + (sum - a[i]);
		suff[i] = t;
	}
	debug(suff);

	t = 0;
	int cnt = 1;
	for(int i=n-1 ; i>0 ; i--){
		t += (n-cnt)*a[i];
		cnt++;
	}
	pref[0] = t;
	for(int i=n-1 ; i>0 ; i--){
		t = t - (n-1)*a[i] + (sum - a[i]);
		pref[i] = t;
	}
	debug(pref);

	int maxi = 0;
	for(int i=0 ; i<n ; i++){
		maxi = max(maxi, max(pref[i], suff[i]));
	}
	println(maxi);
}

signed main(){

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int _ = 1;    
    cin >> _;

    for(int i=1 ; i<=_ ; i++){
        __________();
    }
}
