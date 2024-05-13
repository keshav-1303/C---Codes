// Return an array of distances from src in UNDIRECTED GRAPH
#include <bits/stdc++.h>
using namespace std;

// Using BFS --> T.C = O(V + E)---------------------------
vector<int> shortest(int n, vector<int> adj[], int src){
    vector<int> dist(n, -1);
    dist[src] = 0;

    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i : adj[node]){
            if(dist[i] == -1){    // i.e it is unvisited
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
    return dist;
}