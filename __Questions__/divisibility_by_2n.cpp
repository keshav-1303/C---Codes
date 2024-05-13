#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long int
#define MOD 1000000007
#define PI 3.14159265359
ll gcd(ll a, ll b) { return((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
ll power(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned ll t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// https://codeforces.com/problemset/problem/1744/D


int findN(ll n){       // returns power of 2 on factorisation.
	int count = 0;
	while(!(n & 1)){

		if(n == 0)	 break;

		n = n >> 1;
		count++;
	}
	return count;
}

bool res(int a, int b){
    return (findN(a) > findN(b)) ? 1 : 0 ;
}

int solve(vector<ll> &v, int n){

	//-----------------------------------------find how many already present

	int total = 0;
	for(int i=0 ; i<n ; i++)	total = total + findN(v[i]);

	//-----------------------------------------find maxpossible
	
    int maxPossible = 0;
    for(int i=2 ; i<=n ; i+=2){
        maxPossible = maxPossible + findN(i);
    }

	//-----------------------------------------find how many extra needed

	int needed = n - total;

	//-----------------------------------------finding answer

    // debug(needed);
    // debug(maxPossible);
    // debug(total);
    // cerr << endl;

	if(maxPossible < needed)	return -1;

	else if(needed <= 0)	return 0;

	int ans = 0;

	vector<ll> temp;
	for(int i=2 ; i<=n ; i+=2) 	temp.pb(i);

	sort(temp.begin(), temp.end(), res);

	for(ll i=0 ; i<temp.size() ; i++){

		needed -= findN(temp[i]);

		ans++;

		if (needed <= 0)	break;
	}

	return ans;
}

int main(){

    ios::sync_with_stdio(0);   
    cin.tie(0);   
   
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);      
    freopen("Error.txt", "w", stderr);      
    #endif   

    int T;    cin >> T;
    while(T--){
        int n;    cin >> n;
		vector<ll> v;	 inputVector(v, n);
		cout << solve(v, n) << endl;
    }
    return 0;
}