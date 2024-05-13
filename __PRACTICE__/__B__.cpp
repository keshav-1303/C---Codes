#include <bits/stdc++.h>
using namespace std;
// #define int long long int
#define endl "\n"
#define inputVector(arr, n)  {for(int i=0 ; i<n ; i++){int t; cin >> t; arr.push_back(t);}}
#define sort_rev(a)    {  sort(a.begin(), a.end());    reverse(a.begin(), a.end());  }

void __________(){

    int n, k, q;    cin >> n >> k >> q;

    vector<int> a;   a.push_back(0);   inputVector(a, k);
    vector<int> b;   b.push_back(0);   inputVector(b, k);
    sort_rev(a);
    sort_rev(b);

    while(q--){
        int d;   cin >> d;
        auto it = find(a.begin(), a.end(), d);
        if(it != a.end())   cout << b[it-a.begin()] << " ";
        else{
            it = lower_bound(begin(a), end(a), d, greater<int>());
            int ind = it - a.begin();
            cout << b[ind] + (1LL*(d - a[ind])*(b[ind-1] - b[ind])/(a[ind-1] - a[ind])) << " ";
        }
    }
    cout << endl;
}

signed main(){

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int _ = 1;    
    cin >> _;

    for(int i=1 ; i<=_ ; i++){
        __________();
    }
}
