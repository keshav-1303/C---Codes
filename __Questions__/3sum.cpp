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
ll power(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
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

// https://codeforces.com/problemset/problem/1692/F

//******************************************************************//

void solve(){

    ll n;    cin >> n;

    vector<ll> v; 

    for(ll i=0 ; i<n ; i++){
        string s;    cin >> s;
        v.pb((int)(s[s.size() - 1] - '0'));
    }

    sort(v.begin(), v.end());

    ll sum = 0;

    bool check = 0;

    for(ll i=0 ; i<n ; i++){

        sum += v[i];
        string s = to_string(sum);
        ll temp = (int)(s[s.size() - 1] - '0');

        debug(temp);

        if( temp == 3 ){
            check = 1;
            break;
        }

        else if(temp > 3){
            ll extra = temp - 3;
            ll in = 0;
            for(ll j=0 ; j<n ; j++){
                in += v[j];
                if(in == extra){
                    check = 1;
                    break;
                }
            } 
        }
    }

    if(check)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    cerr << endl;
    
}

//******************************************************************//

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("Error.txt", "w", stderr);
        auto start_time = clock();
    #endif

    int _ = 1;    cin >> _; 

    while(_--){
        solve();
    }

    #ifndef ONLINE_JUDGE
        auto end_time = clock();
        cerr<< "Execution time: "<<(end_time - start_time)*(int)1e3/CLOCKS_PER_SEC<<" ms\n";
    #endif

    return 0;
}



