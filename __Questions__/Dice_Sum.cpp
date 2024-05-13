#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long int
#define MOD 1000000007
#define PI 3.141592653589793238462643383279
ll gcd(ll a, ll b) { return((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
ll power(ll a, ll b, ll mod) {ll temp = 1; while (b > 0) {if (b & 1)temp = (temp * a) % mod; a = (a * a) % mod; b = b >> 1;} return temp;}
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

//**************************************************************************************************************************

void solve(){

    ll n, s, r;    cin >> n >> s >> r;

    // s = a1 + a2 + a3 + ..... + an
    // r = s - max(ai)

    int temp = r/(n-1), count = r%(n-1);

    for (int i=0 ; i<n-1-count ; i++)
        cout << temp << " ";

    for (int i=0 ; i<count ; i++)
        cout << temp + 1 << " ";

    cout << s - r << endl;
    return ;
    
}

//**************************************************************************************************************************

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("Error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
        auto start_time = clock();
    #endif

    int _ = 1;    cin >> _; 

    while(_--){
        solve();
    }

    #ifndef ONLINE_JUDGE
        auto end_time = clock();
        cerr<< "Execution time : " << (end_time - start_time)*(int)1e3/CLOCKS_PER_SEC << " ms" << endl;
    #endif

    return 0;
}



