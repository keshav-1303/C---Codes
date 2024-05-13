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

// https://codeforces.com/contest/559/problem/B

//******************************************************************//

// bool iseq(string a, string b){

//     if(a.size() == 0 || b.size() == 0){
//         return 0;
//     }

//     if(a == b)    return 1;

//     else{

//         int n = a.size();

//         string a1 = a.substr(0, n/2);
//         string a2 = a.substr(n/2, n/2);
//         string b1 = b.substr(0, n/2);
//         string b2 = b.substr(n/2, n/2);

//         bool eq1 = iseq(a1, b1);
//         bool eq2 = iseq(a2, b2);
//         bool eq3 = iseq(a1, b2);
//         bool eq4 = iseq(a2, b1);

//         if( (eq1 && eq2) || (eq3 && eq4) )    return 1;
//         else    return 0;
//     }
// }

string iseq(string str){

    int n = str.size();

    if(n & 1)    return str;
    
    else{

        string a, b;

        a = iseq(str.substr(0, n/2));
        b = iseq(str.substr(n/2, n/2));

        if(a < b)     return a + b;
        else    return b + a;
    }
}

void solve(){

    string a, b;    cin >> a >> b;
    
    // if(iseq(a, b)){
    //     cout << "YES" << endl;
    //     return ;
    // }

    if(iseq(a) == iseq(b)){
        cout << "YES" << endl;
        return ;
    }

    cout << "NO" << endl;
    return ;
    
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

    solve();

    #ifndef ONLINE_JUDGE
        auto end_time = clock();
        cerr<< "Execution time: " << (end_time - start_time)*(int)1e3/CLOCKS_PER_SEC << " ms\n";
    #endif

    return 0;
}
