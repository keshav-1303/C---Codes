#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
// Find the number of strongly connected components in the graph.

// T.C = O(V + E), S.C = O(V + E)

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &stack){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i, adj, vis, stack);
        }
    }
    stack.push(node);
}

void dfs1(int node, vector<int> Adj[], vector<int> &vis, vector<int> &temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto i : Adj[node]){
        if(!vis[i]){
            dfs1(i, Adj, vis, temp);
        }
    }
}

//Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>>& adj){
    
    vector<int> vis (V, 0);
    
    // 1. Sort edges according to finishing time...
    stack<int> stack;
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            dfs(i, adj, vis, stack);
        }
    }
    
    // 2. Reverse the graph...
    vector<int> Adj[V];
    for(int i=0 ; i<V ; i++){
        for(auto j : adj[i]){
            // there was an edge i -> j
            // we have to make it j -> i
            Adj[j].push_back(i);
        }
    }
    
    for(int i=0 ; i<V ; i++){    // this is done bec we have to use vis[] again.
        vis[i] = 0;
    }
    
    vector<vector<int>> ans;    // it stores all SCCs
    
    // 3. Perform dfs on basis of finishing time...
    while(!stack.empty()){
        int node = stack.top();
        stack.pop();
        vector<int> temp;
        
        if(!vis[node]){
            dfs1(node, Adj, vis, temp);
        }
        if(!temp.empty())    ans.push_back(temp);
    }
    return ans.size();
}