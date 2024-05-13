#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination

int countPaths(int n, vector<vector<int>>& roads) {
        
    int MOD = (int)(1e9+7);
    
    vector<pair<int, int>> adj[n];
    for(auto it : roads){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    int src = 0, dest = n-1;
    
    vector<int> dist (n, 1e18);
    dist[src] = 0;
    
    vector<int> ways (n, 0);
    ways[src] = 1;
    
    set<pair<int, int>> set;    // {dist, node}.
    set.insert({0, src});
    
    while(!set.empty()){
        auto it = *(set.begin());
        int node = it.second;
        long long int nodeDist = it.first;
        set.erase(it);
        
        for(auto i : adj[node]){
            int adjNode = i.first;
            long long int adjNodeDist = i.second;
            long long int oldDist = dist[adjNode];
            long long int newDist = nodeDist + adjNodeDist;
            
            // this is the first time with updated distance.
            if(newDist < oldDist){
                dist[adjNode] = newDist;
                set.insert({newDist, adjNode});
                ways[adjNode] = ways[node];
            }
            
            // again got shortest distance.
            else if(newDist == oldDist){
                ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
            }
        }
    }
    
    return ways[dest] % MOD;
}