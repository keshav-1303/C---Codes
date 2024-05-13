#include <bits/stdc++.h>
using namespace std;

// T.C = O(V + E), S.C = O(E) for all methods

// Using DSU ----------------------------------------------------
class Disjoint_Set{
    public:
    vector<int> rank, parent, size;

    Disjoint_Set(int n){
        rank.resize(n+1, 0);
        int start = 0;
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        iota(parent.begin(), parent.end(), start);   // does parent[i] = i;
        iota(size.begin(), size.end(), start);   // does size[i] = i;
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

    void UnionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int detectCycle(int V, vector<int>adj[]){
    map<pair<int, int>, bool> vis;
    Disjoint_Set ds(V);
    for(int i=0 ; i<V ; i++){
        for(auto j : adj[i]){
            int u = i, v = j;   // u -> v is an edge
            if(u > v)   swap(u, v);
            if(!vis[{u, v}] && ds.findUpar(u) == ds.findUpar(v)){
                return 1;
            }
            else{
                ds.UnionbyRank(u, v);
            }
            vis[{u, v}] = 1;
        }
    }
    return 0;
}

// Using BFS (Toposort) ----------------------------------------------------

bool isCyclicBFS(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0), ans;
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0)    q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i] == 0)    q.push(i);
        }
    }
    if(ans.size() == V)   return 0;
    // if size == V, toposort is possible, thus no cycle present.
    return 1;
}

// Using DFS ----------------------------------------------------

bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathvis){
    vis[node] = 1;
    pathvis[node] = 1;
    
    for(auto i : adj[node]){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathvis))    return true;
        }
        // if node is already visited, but has to be 
        // visited again on same path, its a cycle
        else if(pathvis[i]){
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}

bool isCyclicDFS(int V, vector<int> adj[]) {
    vector<bool> vis (V, 0), pathvis (V, 0);
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathvis))    return true; 
        }
    }
    return false;
}