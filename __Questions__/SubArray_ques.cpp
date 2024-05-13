#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }
#define MOD 1000000007
#define PI 3.14159265359
#define ll long long int
using namespace std;

// https://www.codechef.com/problems/SUBPRB?tab=statement

// Given a positive integer N, find an array A such that foll satisfies for each subarray 
// The sum of elements in the subarray is divisible by its length i.e. 

// It can be proved that such an array always exists under given constraints.

// If there are multiple possible arrays, you may print any of them.

int main()
{

    ios::sync_with_stdio(0);   
    cin.tie(0);   
   
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);      
    #endif   

    int T;    cin >> T;
    while(T--){

        int n;    cin >> n;

        int count = 0;

        if(n & 1){
            for(int i=2 ; count < n ; i+=2, count++)     cout << i << " ";
            cout << endl;
        }

        else{
            for(int i=1 ; count < n ; i+=2, count++)     cout << i << " ";
            cout << endl;
        }

    }
    return 0;
}