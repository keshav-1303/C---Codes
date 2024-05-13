// Return the no of diff connected components in Graph

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis){
        
    vis[node] = 1;
    
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i, adj, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    
    vector<int> adjList[V];
    
    // Matrix to List
    for(int i=0 ; i<V ; i++){
        for(int j=0 ; j<V ; j++){
            if(adj[i][j] == 1 && i != j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    int count = 0;
    vector<int> vis(V, 0);
    
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            count++;
            dfs(i, adjList, vis);
        }
    }
    
    return count;
}

// Using DSU -----------------------------------------------------------

class Disjoint_Set{

    vector<int> rank, parent;

    public:

    Disjoint_Set(int n){
        rank.resize(n+1, 0);
        int start = 0;
        parent.resize(n+1, 0);
        iota(parent.begin(), parent.end(), start);   // does parent[i] = i;
    }

    int findUpar(int node){
        if(node == parent[node])    return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionbyRank(int u, int v){
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);
        // if already same do nothing.
        if(ult_u == ult_v)    return ;
        if(rank[ult_u] < rank[ult_v]){
            // Smaller goes and gets attatched to the greater one.
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            // Smaller goes and gets attatched to the greater one.
            parent[ult_v] = ult_u;
        }
        else{
            // if they are same.
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        Disjoint_Set ds(V);

        vector<int> ult_Parents;

        for(int i=0 ; i<V ; i++){
            for(int j=0 ; j<V ; j++){
                if(adj[i][j] == 1){
                    ds.UnionbyRank(i, j);
                }
            }
        }

        int count = 0;
        for(int i=0 ; i<V ; i++){
            if(ds.findUpar(i) == i)    count++;
        }

        return count;
    }
};