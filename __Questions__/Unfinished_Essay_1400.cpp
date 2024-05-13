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
ll power(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll power(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }
#define sort_(a)    sort(a.begin(), a.end());
#define sort_rev(a)    {  sort(a.begin(), a.end());    reverse(a.begin(), a.end());  }
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
#define yes  {cout << "YES" << endl;   return ;}
#define no  {cout << "NO" << endl;   return ;}
#define printpairv(K) { for(auto i : K){cout << "<" << i.first << ":" << i.second << ">" << " ";}cout << endl;}
#define inputpairv(v, n)  for(auto i=0; i<n; i++) {int temp1, temp2;    cin >> temp1 >> temp2;    v.pb({temp1, temp2});} 

//**************************************************************************************************************************

void solve(){

    ll n, c, q;    cin >> n >> c >> q;
    string s;    cin >> s;

    map<char, vector<ll>> mp;

    for(ll i=0 ; i<n ; i++){
        char ch = s[i];
        mp[ch].pb(i + 1);
    }

    ll len = n;

    for(ll i=0 ; i<c ; i++){
        ll temp1, temp2;    cin >> temp1 >> temp2;

        string s1 = "";

        for(ll xy = 0 ; xy < temp2 - temp1 + 1 ; xy++){
            for(auto k : mp){
                if(  binary_search(k.second.begin(), k.second.end(), temp1 + xy)  ){
                    // ch = k.first;
                    s1 += k.first;
                }
            }
        }

        debug(s1);

        for(ll j=0 ; j<s1.size() ; j++){
            mp[s1[j]].pb(j + len + 1);
        }

        len += s1.size();
        s1.clear();
    }

    // for(auto i : mp){
    //     cout << i.first << " ";
    //     print(i.second);
    // }cout << endl;

    for(ll i=0 ; i<q ; i++){
        ll temp;    cin >> temp;
        for(auto k : mp){
            if(  binary_search(k.second.begin(), k.second.end(), temp)  ){
                cout << k.first << endl;
                break;
            }
        }
    }
    return ;
}

//**************************************************************************************************************************

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("Error.txt", "w", stderr);
        // freopen("output.txt", "w", stdout);
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



