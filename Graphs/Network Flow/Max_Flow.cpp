#include <bits/stdc++.h>
using namespace std;

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
  
int findMaxFlow(int N, int M, vector<vector<int>> Edges){
    int src = 0, dest = N-1;

    vector<vector<int>> rgraph(N, vector<int>(N, 0));
    for(int i=0 ; i<M ; i++){
        int u = Edges[i][0];
        int v = Edges[i][1];
        int wt = Edges[i][2];
        rgraph[u-1][v-1] += wt;
        rgraph[v-1][u-1] += wt;
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