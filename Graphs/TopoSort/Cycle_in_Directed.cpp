#include <bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// for 1-based indexing -----------------------------------------
bool topoSort(int V, vector<int> adj[]) {
    vector<int> indegree (V+1, 0);
    for(int i=1 ; i<=V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=1 ; i<=V ; i++){
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
    return ans.size() == V;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   vector<int> adj[n+1];
   for(auto i : edges){
     adj[i.first].push_back(i.second);
   }
   return !topoSort(n, adj);
}

// for 0-based indexing -----------------------------------------
bool topoSort(int V, vector<int> adj[]) {
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
    return ans.size() == V;
}

bool detectCycleInDirectedGraph(int n, vector<vector<int>>& edges) {
    vector<int> adj[n];
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
    }
    return topoSort(n, adj);
}