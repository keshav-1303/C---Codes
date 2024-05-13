#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.push_back(temp);}
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(K) { for(auto i : K){cout << "<" << i.first << ":" << i.second << ">" << " ";}cout << endl;}
#define sort_(a)    sort(a.begin(), a.end());
#define sort_rev(a)    {  sort(a.begin(), a.end());    reverse(a.begin(), a.end());  }
int __lcm(int a, int b) {  return (b / __gcd(a, b)) * a; }
int power(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)   res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int power(int a, int b) {int res = 1; while (b > 0) {if (b & 1)   res = (res * a); a = (a * a); b = b >> 1;} return res;}
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" = "; _print(x); cout << endl;
#else
#define debug(x)
#endif
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(long double t) {cout << t;}
void _print(double t) {cout << t;}
void _print(unsigned int t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(deque <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(deque <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
#define yes   {cout << "YES" << endl; }
#define no   {cout << "NO" << endl; }

void __________(int testcases){

    int n, m;    cin >> n >> m;
    string s1, s2;   cin >> s1 >> s2;

    vector<int> pref, suff;
    pref.push_back(0);
    suff.push_back(0);

    int ind = 0, i = 0;
    for( ; i<n ; i++){
        if(ind == m)    break;
        if(s1[i] == s2[ind]){
            ind++;
        }
        pref.push_back(ind);
    }
    while(i < n){
        pref.push_back(ind);
        i++;
    }

    ind = m, i = n-1;
    for( ; i>=0 ; i--){
        if(ind == m)    break;
        if(s1[i] == s2[m-ind-1]){
            ind++;
        }
        suff.push_back(ind);
    }
    while(i > 0){
        pref.push_back(ind);
        i--;
    }

    debug(pref);
    debug(suff);

    int q;   cin >> q;
    while(q--){
        int l, r;   cin >> l >> r;
        int t1 = 0, t2 = 0;

        if(l-2 >= 0){
            t1 = pref[l-2];
        }
        if(r < n){
            t2 = suff[r];
        }
        
        if(t1 + 1 > t2 - 1){
            yes;
        }
        else{
            no;
        }
        
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    #ifndef ONLINE_JUDGE
        cout << "---------------------------------------------------------------------------------------------------" << '\n';
        freopen("input.txt", "r", stdin);
        auto chrono_begin = chrono::steady_clock::now();
    #endif

    int _ = 1;    

    while(_--){
        __________(_);
    }

    #ifndef ONLINE_JUDGE
        cout << "Execution time : " << 1e-6L * chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - chrono_begin).count() << 's' << endl;
        cout << "---------------------------------------------------------------------------------------------------" << '\n';
    #endif
}
