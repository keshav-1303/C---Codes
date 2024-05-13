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
#define inputVector(v, n)  for(auto i=0; i<n; i++) {string temp;    cin >> temp;    v.pb(temp);} 
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

//*******************************************************************//

// https://www.codechef.com/problems/DIGITOP

void solve(){

    ll n, k;    cin >> n >> k;
    
    vector<string> v1;    inputVector(v1, n);
    
    vector<string> v2;    inputVector(v2, n);
    
    bool check = true;
    
    for(int i=0 ; i<n ; i++){
        if(v1[i].size() != v2[i].size()){
            check = false;
            break;
        }
    }
    
    if(!check){
        cout << "NO" << endl;
        return ;
    }
    
    string a = "", b = "";
    
    for(int i=0 ; i<n ; i++){
        a += v1[i];
        b += v2[i];
    }
    
    map<char, int> map1;
    map<char, int> map2;
    
    for(int i=0 ; i<a.size() ; i++){
        char ch = a[i];
        map1[ch]++;
    }
    for(int i=0 ; i<b.size() ; i++){
        char ch = b[i];
        map2[ch]++;
    }
    
    // printmap(map1);
    // printmap(map2);
    
    int count = 0;
    
    map<char,int>::iterator i1 = map1.begin();
    map<char,int>::iterator i2 = map2.begin();
    
    while(i1 != map1.end() && i2 != map2.end()){
        
        while( i1->first < i2->first  &&  i1 != map1.end() ){
            i1++;
            count++;
        }
        
        while( i1->first > i2->first  &&  i2 != map2.end() ){
            i2++;
            count++;
        }
        
        if(i1 -> first == i2 -> first){
            count += abs(i1 -> second - i2 -> second);
        }
        i1++;
        i2++;
    }
    
    // cout << count << endl;

    if(k >= count/2){
        cout << "YES" << endl;
        return ;
    }

    cout << "NO" << endl;
    return ;
}

//*******************************************************************//

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

