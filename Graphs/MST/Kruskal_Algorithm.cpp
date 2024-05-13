#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

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

int spanningTree(int V, vector<vector<int>> adj[]){
        
    vector<pair<int, pair<int, int>>> edges;
    
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            int adjNode = it[0];
            int weight = it[1];
            int node = i;
            edges.push_back({weight, {node, adjNode}});
            edges.push_back({weight, {adjNode, node}});
        }
    }
    
    sort(edges.begin(), edges.end());
    Disjoint_Set ds(V);
    
    int mstWeight = 0;
    
    for(auto i : edges){
        int u = i.second.first;
        int v = i.second.second;
        int weight = i.first;
        
        if(ds.findUpar(u) != ds.findUpar(v)){
            // it means they don't belong to same component.
            mstWeight += weight;
            ds.UnionbyRank(u, v);
        }
    }
    
    return mstWeight;
}