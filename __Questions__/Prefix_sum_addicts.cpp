#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

// https://codeforces.com/problemset/problem/1738/B

void solve(){

    ll n, k;
    cin >> n >> k;
    vector<ll> s;
    inputVector(s, k);
    if (k == 1)
    {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i + 1] - s[i] > s[i + 2] - s[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
    }

    ll cc = n - k + 1;
    if ((s[1] - s[0]) * cc < s[0])
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
    return ;
}

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



