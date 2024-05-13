#include <bits/stdc++.h>
using namespace std;

// Min distance from src to all other vertices
// Fails when Graph has NEGATIVE WEIGHTS

// https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1

// 0-based indexing-------------------------------------------------------

vector<int> dijkstra(vector<vector<int>> &adjMatrix, int V, int E, int src){

    // according to 0-based indexing
    vector<pair<int, int>> adj[V];
    for(int i=0 ; i<E ; i++){
        int u = adjMatrix[i][0];
        int v = adjMatrix[i][1];
        int weight = adjMatrix[i][2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // **** FOR UNDIRECTED GRAPH ****
    }
        
    set<pair<int, int>> s;
    s.insert({0, src});
    
    // min dist from src to all vertices
    vector<int> dist(V, 1e18);
    dist[src] = 0;
    
    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        int nodeDist = it.first;
        s.erase(it);
        
        for(auto i : adj[node]){
            int adjNode = i.first;
            int edgeWeight = i.second;
            int oldDist = dist[adjNode];
            int newDist = nodeDist + edgeWeight;
            
            if(newDist < oldDist){
                // erase if already existed.
                if(oldDist != 1e18){
                    s.erase({oldDist, adjNode});
                }
                dist[adjNode] = newDist;
                s.insert({newDist, adjNode});
            }
        }
    }
    return dist;
}

// 1-based indexing-------------------------------------------------------

vector<int> dijkstra(vector<vector<int>> &adjMatrix, int V, int E, int src){

    // according to 0-based indexing
    vector<pair<int, int>> adj[V+1];
    for(int i=0 ; i<E ; i++){
        int u = adjMatrix[i][0];
        int v = adjMatrix[i][1];
        int weight = adjMatrix[i][2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
        
    set<pair<int, int>> s;
    s.insert({0, src});
    
    // min dist from src to all vertices
    vector<int> dist(V+1, 1e18);
    dist[src] = 0;
    
    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        int nodeDist = it.first;
        s.erase(it);
        
        for(auto i : adj[node]){
            int adjNode = i.first;
            int edgeWeight = i.second;
            int oldDist = dist[adjNode];
            int newDist = nodeDist + edgeWeight;
            
            if(newDist < oldDist){
                // erase if already existed.
                if(oldDist != 1e18){
                    s.erase({oldDist, adjNode});
                }
                dist[adjNode] = newDist;
                s.insert({newDist, adjNode});
            }
        }
    }
    return dist;
}