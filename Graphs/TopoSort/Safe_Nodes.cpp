#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

// Using DFS --------------->
bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathvis, vector<bool> &check){
        
    vis[node] = 1;
    pathvis[node] = 1;
    
    for(auto i : adj[node]){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathvis, check) == true){
                return true;
            }
        }
        else if(pathvis[i]){
            return true;
        }
    }
    
    check[node] = 1;
    // bec if cycle was present, it will not reach here.
    pathvis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    
    vector<int> safeNodes;
    vector<bool> vis(V, 0), pathvis(V, 0), check(V, 0);
    
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            dfs(i, adj, vis, pathvis, check);
        }
    }
    
    for(int i=0 ; i<V ; i++){
        if(check[i] == 1)   safeNodes.push_back(i);
    }
    
    return safeNodes;
}

//---------------------------------------

// USing BFS ---------------------------->
vector<int> Topo_Sort(vector<int> adj[], int V){
    vector<int> indegree (V, 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0)   q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // Now we will remove elements so thier adjacents' indegree will decrease.
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i] == 0)    q.push(i);
        }
    }
    return ans;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    // Reverse all existing edges...
    vector<int> adjRev[V];
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            adjRev[it].push_back(i);
        }
    }
    // Perform TOPOLOGICAL Sort...
    vector<int> safeNodes = Topo_Sort(adjRev, V);
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}