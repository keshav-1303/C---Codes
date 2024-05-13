#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
    // Creating Adjacency List
    vector<pair<int, int>> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    int src = 1, dest = n;
    
    set<pair<int, int>> s;
    vector<int> dist(n+1, 1e9), parent(n+1, -1);
    dist[src] = 0;
    
    for(int i=1 ; i<=n ; i++){
        parent[i] = i;
    }
    
    s.insert({0, src});
    
    while(!s.empty()){
        
        auto it = *(s.begin());
        int node = it.second;
        int nodeDist = it.first;
        s.erase(it);
        
        for(auto i : adj[node]){
            
            int adjNode = i.first;
            int weight = i.second;
            int oldDist = dist[adjNode];
            int newDist = nodeDist + weight;
            
            if(newDist < oldDist){
                // delete if already present.
                if(oldDist != 1e9){
                    s.erase({oldDist, adjNode});
                }
                
                dist[adjNode] = newDist;
                s.insert({newDist, adjNode});
                parent[adjNode] = node;
            }
        }
    }
    
    if(dist[dest] == 1e9){
        return {-1};
    }
    
    vector<int> path;
    int curr_node = dest;

    while (curr_node != src) {
        path.push_back(curr_node);
        curr_node = parent[curr_node];
    }

    path.push_back(src);
    reverse(path.begin(), path.end());

    return path;
    
}