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

//******************************************************************//

void solve(){

    ll n;    cin >> n;

	vector<ll> v;     inputVector(v, n);

    ll i = n/2 - 1, j = n/2;

    ll maxi = max(v[i], v[j]), mini = min(v[i], v[j]);

    ll l = -1 , r = -1;

    int count = 0;

    while(i >= 0  &&  j < n){

        // debug(i);
        // debug(j);
        debug(v[i]);
        debug(v[j]);

        maxi = max( (v[i], v[j]), maxi );
        mini = min( (v[i], v[j]), mini );

        debug(maxi);
        debug(mini);

        if(v[i] != maxi  &&  v[i] != mini  &&  v[j] != maxi  &&  v[j] != mini){
            l = i + 1;
            r = j + 1;
            break;
        }

        debug(l);
        debug(r);

        if(!(count & 1))    j++;
        else    i--;

        count++;
    }

    cerr << "-------------" << endl;

    if(l == -1 && r == -1){
        cout << -1 << endl;
        return ;
    }

    cout << l << " " << r << endl;
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

/*
27
7
1 2 3 4 5 6 7
7
1 2 3 4 5 7 6
7
1 2 3 4 6 5 7
7
1 2 3 4 6 7 5
7
1 2 3 4 7 5 6
7
1 2 3 4 7 6 5
7
1 2 3 5 4 6 7
7
1 2 3 5 4 7 6
7
1 2 3 5 6 4 7
7
1 2 3 5 6 7 4
7
1 2 3 5 7 4 6
7
1 2 3 5 7 6 4
7
1 2 3 6 4 5 7
7
1 2 3 6 4 7 5
7
1 2 3 6 5 4 7
7
1 2 3 6 5 7 4
7
1 2 3 6 7 4 5
7
1 2 3 6 7 5 4
7
1 2 3 7 4 5 6
7
1 2 3 7 4 6 5
7
1 2 3 7 5 4 6
7
1 2 3 7 5 6 4
7
1 2 3 7 6 4 5
7
1 2 3 7 6 5 4
7
1 2 4 3 5 6 7
7
1 2 4 3 5 7 6
7
1 2 4 3 6 5 7
7
1 2 4 3 6 7 5
*/


/*
-1
-1
-1
-1
-1
-1
-1
4 7
-1
-1
4 7
-1
-1
4 7
-1
-1
4 7
-1
-1
-1
-1
-1
-1
-1
-1
3 7
3 6
3 7
*/



