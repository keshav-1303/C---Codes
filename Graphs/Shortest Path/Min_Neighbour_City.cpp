#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
int findTheCity(int n, vector<vector<int>>& edges, int K) {
    vector<vector<int>> adj(n, vector<int> (n, 1e9));
    for(int i=0 ; i<n ; i++)    adj[i][i] = 0;
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int wt = i[2];
        adj[u][v] = wt;
        adj[v][u] = wt;
    }

    for(int k=0 ; k<n ; k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int ans = 0, mini = 0;
    for(int j=0 ; j<n ; j++){
        if(adj[0][j] <= K && adj[0][j] > 0)   mini++;
    }
    ans = 0;
    for(int i=1 ; i<n ; i++){
        int cnt = 0;
        for(int j=0 ; j<n ; j++){
            if(adj[i][j] <= K && adj[i][j] > 0)   cnt++;
        }
        if(cnt <= mini){
            mini = cnt;
            ans = i;
        }
    }
    return ans;
}