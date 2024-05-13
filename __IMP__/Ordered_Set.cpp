#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> OS;

// https://codeforces.com/contest/1915/problem/F
// Given an array of segments, find the number of segments in which one segment
// is fully contained in the other.

long long int ANS(vector<pair<int, int>> &v, int n){

    OS A;
    for(int i=0 ; i<n ; i++){
        int b = v[i].second;   
        A.insert(b);     
    }

    sort(v.begin(), v.end());   // for each a[i] see that in right, how many j such that b[j] < b[i].

    long long int ans = 0;
    for(int i=0 ; i<n ; i++){
        ans += A.order_of_key(v[i].second);
        A.erase(v[i].second);   // erased bec we want to consider only right part
    }

    return ans;

}

signed main(){

    int _ = 1;    cin >> _;

    while(_--){

        int n;    cin >> n;

        vector<pair<int, int>> v;
        for(int i=0 ; i<n ; i++){
            int a, b;   cin >> a >> b;
            v.push_back({a, b});       
        }

        cout << ANS(v, n) << endl;
    }
}
