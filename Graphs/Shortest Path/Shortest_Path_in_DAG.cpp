#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

void TopoSort(int node, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &s){
        
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i.first]){
            TopoSort(i.first, adj, vis, s);
        }
    }
    
    s.push(node);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    
    vector<pair<int, int>> adj[N];
    
    for(int i=0 ; i<M ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    
    vector<bool> vis (N, 0);
    stack<int> s;
    
    for(int i=0 ; i<N ; i++){
        if(!vis[i]){
            TopoSort(i, adj, vis, s);
        }
    }
    
    // Now calculate distance.
    vector<int> dist (N, 1e9);
    int src = 0;
    dist[src] = 0;
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        
        for(auto i : adj[node]){
            int adjNode = i.first;
            int weight = i.second;
            int newDist = dist[node] + weight;
            int oldDist = dist[adjNode];
            
            dist[adjNode] = min(newDist, oldDist);
        }
    }
    
    for(int i=0 ; i<N ; i++){
        if(dist[i] == 1e9)    dist[i] = -1;
        // if not possible to reach any node return -1 for that node.
    }
    
    return dist;
}