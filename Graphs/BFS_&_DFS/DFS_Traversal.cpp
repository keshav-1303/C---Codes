#include <bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
// Use it for visualising GRAPH -->
// https://csacademy.com/app/graph_editor/

// s.c = O(n), t.c = O(n) + O(2*E)
void dfs(int node, vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans){

    visited[node] = 1;
    ans.push_back(node);

    // Traverse all its neighbours
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, adj, visited, ans);
        }
    }
}

vector<int> DFS(vector<pair<int, int>> edges){

    // Creating Adjacency List
    vector<int> adj[edges.size()];

    for(auto i : edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    // -----------------------

    vector<int> ans;

    unordered_map<int, bool> visited;
    int start = 0;

    dfs(start, adj, visited, ans);    

    return ans;
}

int main(){

    int n;    cout << "Enter number of nodes : ";     cin >> n;
    int m;    cout << "Enter number of edges : ";     cin >> m;

    vector<pair<int, int>> edges;

    for(int i=0 ; i<m ; i++){
        int u, v;     cin >> u >> v;
        edges.push_back({u, v});
    }

    //For input -->
    // 9 10
    // 0 8
    // 1 6
    // 1 7
    // 1 8
    // 5 8
    // 6 0
    // 7 3
    // 7 4
    // 8 7
    // 2 5
    
    // Ajacency List -->
    // 5 -> 2 8
    // 7 -> 1 3 4 8
    // 0 -> 6 8
    // 8 -> 0 1 5 7
    // 1 -> 6 7 8
    // 6 -> 0 1

    // DFS -->
    // 0 6 1 7 3 4 8 5 2

    print(DFS(edges));

    return 0;
}



