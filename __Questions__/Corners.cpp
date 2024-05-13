#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long int
#define MOD 1000000007
#define PI 3.14159265359
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

// https://codeforces.com/problemset/problem/1720/C

void Print(int **arr, int n, int m){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout << arr[i][j] << " ";
            }
        cout << endl;
    }
    cout << "--------------" << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Error.txt", "w", stderr);
    #endif   

    int t;   cin >> t;
    while(t--){

        int n, m;    cin >> n >> m;
 
        int** arr = (int**)malloc(n * sizeof(int*));

        for(int i=0; i<n; i++){
            arr[i] = (int*)malloc(m * sizeof(int));
        }

        for(int i=0 ; i<n ; i++){
            string temp;    cin >> temp;
            for(int j=m-1 ; j>=0 ; j--){
                int r = (int)(temp[j] - '0');
                arr[i][j] = r;
            }
        }

        // Print(arr, n, m);

        int count0 = 0, count1 = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 1)    count1++;
                else    count0++;
            }
        }

        bool check = 0;

        for(int i=0 ; i<n-1 ; i++){
            for(int j=0 ; j<m-1 ; j++){
                
                int sum = arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1];

                if(sum <= 2){
                    check = 1;
                    break;
                }
            }
        }

        if(check)    cout << count1 << endl;

        else if(count0 == 0)     cout << count1 - 2 << endl;

        else if(!check  &&  count0)    cout << count1 - 1 << endl;

        free(arr);

    }
}

