#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

void dfs(int node, int &timer, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<int> &parent, vector<int> &ap){
    vis[node] = 1;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto nbr : adj[node]){
        if(nbr == parent[node])   continue;    // ignore
        else if(!vis[nbr]){
            parent[nbr] = node;
            dfs(nbr, timer, adj, disc, low, vis, parent, ap);
            low[node] = min(low[node], low[nbr]);
            // Now check if BRIDGE present..
            if(low[nbr] >= disc[node] && parent[node] != -1){
                ap[node] = 1;
            }
            child++;
        }
        else{   // back-edge
            low[node] = min(low[node], low[nbr]);
        }
    }
    if(parent[node] == -1 && child > 1)   ap[node] = 1;
}
    
vector<int> articulationPoints(int n, vector<int>adj[]) {
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> vis(n, 0);
    vector<int> parent(n, -1);

    vector<int> ap(n, 0);

    int timer = 0;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i, timer, adj, disc, low, vis, parent, ap);
        }
    } 
    
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        if(ap[i] != 0)  ans.push_back(i);
    }
    if(ans.empty())   return {-1};
    return ans;
}