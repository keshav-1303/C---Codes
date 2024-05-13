#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
// Both codes are for 0-based indexing

// Using DFS ----------------------------------------------
// T.C = O(V+E), S.C = O(V).
void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &s){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i])   dfs(i, adj, vis, s);
    }
    s.push(node);
}

vector<int> topoSort1(int V, vector<int> adj[]) {
    vector<bool> vis (V, 0);
    stack<int> s;
    for(int i=0 ; i<V ; i++){
        if(!vis[i])    dfs(i, adj, vis, s);
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Using BFS (Kahn's Algo) ----------------------------------
// T.C = O(V+E), S.C = O(V).
// Topo Order = Increasing order of INDEGREE
vector<int> topoSort2(int V, vector<int> adj[]) {
    vector<int> indegree (V, 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0)    q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)   q.push(it);
        }
    }
    return ans;
}

signed main(){
    int V = 7;
    vector<int> adj[V] = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> topo = topoSort2(V, adj);
    for(auto i : topo){
        cout << i << " ";
    }
    cout << endl;
}
