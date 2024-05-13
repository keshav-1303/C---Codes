#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
    vector<int> dist (V, 1e8);
    dist[S] = 0;
    
    // (N-1) iterations...
    for(int i=0 ; i<V-1 ; i++){
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int weight = i[2];
            
            if(dist[u] != 1e8 && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    // Perform Nth iteration to check negative cycle...
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int weight = i[2];
        
        if(dist[u] != 1e8 && dist[u] + weight < dist[v]){
            return {-1};
        }
    }
    
    return dist;
}