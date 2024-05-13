// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
#include <bits/stdc++.h>
using namespace std;

// Using BFS -->
// We will use a vis array, and start with a start node, then exploring all edges 
// connected to that start node, and so on.. If we reach a node that is already visited,
// it means the other edge of start node have came here before, it is only possible if
// a cycle is present, bec we started on diff directions.

// T.C = O(N + 2*E), S.C = O(N) + O(N)

bool DetectCycleBFS(int src, vector<int> adj[], vector<bool> &vis){
    vis[src] = 1; 
    queue<pair<int, int>> q;    // <node, parent>
    q.push({src, -1});
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto i : adj[node]){
            if(!vis[i]){
                vis[i] = 1;
                q.push({i, node});
            }
            else if(parent != i){
                // if node is already visited and it did not come from parent.
                // it means, other edge has visited it, thus cycle present.
                return true;
            }
        }
    }
    return false;
}

// Using DFS -->
// If any forward node is already visited, cycle is present.

bool DetectCycleDFS(int node, int parent, vector<int> adj[], vector<bool> &vis){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]){
            if(DetectCycleDFS(i, node, adj, vis)){
                return true;
            }
        }
        else if(parent != i){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, 0);
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            if(DetectCycleBFS(i, adj, vis)){
                return true;
            }
            // if(DetectCycleDFS(i, -1, adj, vis)){
            //     return true;
            // }
        }
    }
    return false;
}