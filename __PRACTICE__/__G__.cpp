#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    #include "debug.h"
#endif
#ifdef ONLINE_JUDGE
    #define debug(x) 
#endif
using namespace std;
#define int long long int
#define endl "\n"
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define sort_(a)    sort(a.begin(), a.end());
#define sort_rev(a)    {  sort(a.begin(), a.end());    reverse(a.begin(), a.end());  }
int __lcm(int a, int b) {  return (b / __gcd(a, b)) * a; }
int power(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)   res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int power(int a, int b) {int res = 1; while (b > 0) {if (b & 1)   res = (res * a); a = (a * a); b = b >> 1;} return res;}
#define printMatrix(v)  {  for(int i=0 ; i<v.size() ; i++){ for(int j=0 ; j<v[0].size() ; j++){ cout << v[i][j] << " "; }cout << endl; }}
#define yes   {cout << "YES" << endl;   return ;}
#define no   {cout << "NO" << endl;   return ;}
#define println(K)   {cout << K << endl;   return ;}
#define all_(v)    v.begin(), v.end()

bool N(int n){
    return !(n & (1 << 3));
}
bool E(int n){
    return !(n & (1 << 2));
}
bool S(int n){
    return !(n & (1 << 1));
}
bool W(int n){
    return !(n & (1 << 0));
} 

int bfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &v){

    queue<pair<int, pair<int, int>>> q;
    q.push({v[i][j], {i, j}});

    int count = 0, m = v[0].size(), n = v.size();

    while(!q.empty()){
        pair<int, pair<int, int>> t = q.front();
        q.pop();
        count++;
        int node = t.first;
        int x = t.second.first;
        int y = t.second.second;
        vis[x][y] = 1;

        if(x > 0 && N(node) && !vis[x-1][y]){
            q.push({v[x-1][y], {x-1, y}});
        }
        if(y < m-1 && E(node) && !vis[x][y+1]){
            q.push({v[x][y+1], {x, y+1}});
        }
        if(x < n-1 && S(node) && !vis[x+1][y]){
            q.push({v[x+1][y], {x+1, y}});
        }
        if(y > 0 && W(node) && !vis[x][y-1]){
            q.push({v[x][y-1], {x, y-1}});
        }
    }
    return count;
}

void __________(){

    int n, m;    cin >> n >> m;
    vector<vector<int>> v (n, vector<int> (m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<bool>> vis (n, vector<bool> (m, 0));

    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!vis[i][j]){
                ans.push_back(bfs(i, j, vis, v));
            }
        }
    }

    sort_rev(ans);
    print(ans); 

}

signed main(){

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int _ = 1;    
    // cin >> _;

    while(_--){
        __________();
    }
}
