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

bool IsPallindrome(vector<int> v, int k){

    v.erase( remove(v.begin(), v.end(), k), v.end() );
    
    for(int i=0 ; i<=v.size()/2 ; i++){
        if(v[i] != v[v.size()-i-1])    return 0;
    }
    return 1;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t;    cin >> t;
    while (t--){
    
        int n;
        cin >> n;
        vector<int> v;    inputVector(v, n);

        bool flag = 1; // n==1 and n==2

        for (int i = 0; i < n - 1 - i; ++i)
            if (v[i] != v[n - 1 - i]){

                flag = IsPallindrome(v, v[i]) || IsPallindrome(v, v[n - 1 - i]);
                break;
            }

        if (flag)    cout << "YES\n";
        else    cout << "NO\n";
    }
    return 0;
}