#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
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

//**************************************************************************************************************************

bool check_subsequence(string t, string s) {
    
    if(s == t)
    return true;
    int n = s.size();
    int m = t.size();
    int j = 0;
    for(int i = 0; i < n; i++){
       if(t[j] == s[i])
       j++;
       if(j == t.size())
       return true;
    }
    return false;
    
}

// RECURSION IS ALL FINE, CORRECTION MUST BE DONE IN DP.

bool rec(string s, string l, string r, int ind, string till_now){

    if(ind == l.size()){
        bool temp = check_subsequence(till_now, s);
        if(temp)    return 0;
        else    return 1;
    }

    for(char i = l[ind] ; i<= r[ind] ; i++){
        string ans = till_now;
        ans += i;
        // cout << ans << endl;
        bool temp = rec(s, l, r, ind+1, ans);
        // temp_bool = max(temp_bool, temp);
        if(temp == 1)   return 1;
    }

    return 0;
}

void solve(){

    string s;   cin >> s;
    int m;   cin >> m;
    string l, r;    cin >> l >> r;

    

    bool ispossible = rec(s, l, r, 0, "");

    if(ispossible){
        yes;
    }
    no;
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



