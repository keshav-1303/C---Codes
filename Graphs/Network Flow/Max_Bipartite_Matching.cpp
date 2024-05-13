#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/maximum-bipartite-matching/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
bool bfs(vector<vector<int>> &rGraph, int src, int dest, vector<int> &parent){
    int V = rGraph.size();
    vector<int> vis(V, 0);
    vis[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);
  
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v=0 ; v<V ; v++){
            if(!vis[v] && rGraph[u][v] != 0){
                if(v == dest){
                    parent[v] = u;
                    return 1;
                }
                q.push(v);
                parent[v] = u;
                vis[v] = 1;
            }
        }
    }
    return false;
}
  
// Edges has 0-based indexing
int findMaxFlow(int N, int M, vector<vector<int>> Edges){
    int src = 0, dest = N-1;
    
    vector<vector<int>> rgraph(N, vector<int>(N, 0));
    for(int i=0 ; i<M ; i++){
        int u = Edges[i][0];
        int v = Edges[i][1];
        int wt = Edges[i][2];
        rgraph[u][v] += wt;
        rgraph[v][u] += wt;
    }

    vector<int> parent(N, 0);
    int maxFlow = 0;
    while(bfs(rgraph, src, dest, parent)){
        int pathFlow = INT_MAX;
        for(int v=dest ; v!=src ; v=parent[v]){
            int u = parent[v];
            pathFlow = min(pathFlow, rgraph[u][v]);
        }
        for(int v=dest ; v!=src; v=parent[v]){
            int u = parent[v];
            rgraph[u][v] -= pathFlow;
            rgraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}
	
int maximumMatch(vector<vector<int>> &G){
    int n = G.size(), m = G[0].size();
    vector<vector<int>> edges;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(G[i][j] == 1){
                int u = i+1;
                int v = n+j+1;
                edges.push_back({u, v, 1});
            }
        }
    }
    
    int N = n+m+2;
    
    for(int i=0 ; i<n ; i++){
        edges.push_back({0, i+1, 1});
    }
    for(int j=0 ; j<m ; j++){
        edges.push_back({n+j+1, N-1, 1});
    }
    
    int M = edges.size();
    return findMaxFlow(N, M, edges);
}