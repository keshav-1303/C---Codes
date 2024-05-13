#include <bits/stdc++.h> 
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// T.C = O(E * logV), S.C = O(E).

// 0 based indexing --------------------------------------------------------
int spanningTree(int V, vector<vector<int>> adj[]){
        
    set<pair<int, pair<int, int>>> set;    // stores <weight, <node, parent>>
    set.insert({0, {0, -1}});
    
    vector<int> vis (V, 0);
    int sum = 0;    // stores sum of weights in MST
    
    vector<pair<int, int>> MST;    // stores edges that need to be in MST.
    
    while(!set.empty()){
        auto it = *(set.begin());
        int weight = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        set.erase(it);
        
        // if not visited, go beyond, it already visited, no need to go.
        if(!vis[node]){
            vis[node] = 1;
            sum += weight;
            if(parent != -1)    MST.push_back({parent, node});
        
            for(auto i : adj[node]){
                int adjNode = i[0];
                int adjNodeWt = i[1];
                
                if(!vis[adjNode]){
                    set.insert({adjNodeWt, {adjNode, node}});
                }
            }
        }
    }
    // Now use MST[] to form Minimum Spanning Tree.
    return sum;
}

// // 1 based indexing --------------------------------------------------------
// int spanningTree(int V, vector<vector<int>> adj[], int k){
        
//     set<pair<int, pair<int, int>>> set;    // stores <weight, <node, parent>>
//     set.insert({0, {1, -1}});
    
//     vector<int> vis (V+1, 0);
//     int sum = 0;    // stores sum of weights in MST
    
//     vector<pair<int, int>> MST;
//     // stores edges that need to be in MST.
    
//     while(!set.empty()){
        
//         auto it = *(set.begin());
//         int weight = it.first;
//         int node = it.second.first;
//         int parent = it.second.second;
//         set.erase(it);
        
//         // if not visited, go beyond, it already visited, no need to go.
//         if(!vis[node]){
//             vis[node] = 1;
//             sum = (sum + weight) % k;
//             if(parent != -1)    MST.push_back({parent, node});
        
//             for(auto i : adj[node]){
//                 int adjNode = i[0];
//                 int adjNodeWt = i[1];
                
//                 if(!vis[adjNode]){
//                     set.insert({adjNodeWt, {adjNode, node}});
//                 }
//             }
//         }
//     }
    
//     // Now use MST[] to form Minimum Spanning Tree.
    
//     return sum % k;
// }

void __________(int testcases){

    int V, E, k;   cin >> V >> E >> k;
    vector<vector<int>> adj[V+1];

    for(int i=1 ; i<=E ; i++){
        int u, v, w;    cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    
    cout << spanningTree(V, adj) << "\n";
}