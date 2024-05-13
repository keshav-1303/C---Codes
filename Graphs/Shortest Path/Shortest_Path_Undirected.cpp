#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

// T.C = O(E), S.C = O(V)+O(V)+O(V)
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
    vector<int> adj[N];
    for(int i=0 ; i<M ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(N, 1e9);
    dist[src] = 0;
    
    queue<pair<int, int>> q;
    q.push({src, 0});
    
    vector<int> vis(N, 0);  
    vector<int> degree(N, 0);
    
    for(int i=0 ; i<N ; i++){
        degree[i] = adj[i].size();
    }
    
    while(!q.empty()){
        int node = q.front().first;
        int nodeDist = q.front().second;
        vis[node]++;
        q.pop();
        
        for(auto i : adj[node]){
            if(vis[i] < degree[i]){
                int oldDist = dist[i];
                int newDist = dist[node] + 1; // +1 bec of unit weight
                dist[i] = min(oldDist, newDist);
                q.push({i, dist[i]});
            }
        }
    }
    
    for(int i=0 ; i<N ; i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }
    
    return dist;
    
}