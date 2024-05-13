#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/critical-connections-in-a-network/
void dfs(int node, int &timer, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<int> &parent, vector<vector<int>> &ans){
    vis[node] = 1;
    disc[node] = low[node] = timer++;

    for(auto nbr : adj[node]){
        if(nbr == parent[node])   continue;    // ignore
        else if(!vis[nbr]){
            parent[nbr] = node;
            dfs(nbr, timer, adj, disc, low, vis, parent, ans);
            low[node] = min(low[node], low[nbr]);
            // Now check if BRIDGE present..
            if(low[nbr] > disc[node]){
                ans.push_back({node, nbr});
            }
        }
        else{   // back-edge
            low[node] = min(low[node], low[nbr]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
    vector<int> adj[n];
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> vis(n, 0);
    vector<int> parent(n, -1);

    vector<vector<int>> ans;

    int timer = 0;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i, timer, adj, disc, low, vis, parent, ans);
        }
    } 
    return ans;
}