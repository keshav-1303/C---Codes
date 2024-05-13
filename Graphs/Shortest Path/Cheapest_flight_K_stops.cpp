#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dest, int k) {
    vector<pair<int, int>> adj[n];
    for(auto i : edges){
        adj[i[0]].push_back({i[1], i[2]});
    }

    set<pair<int, pair<int, int>>> S;   // <stops, <node, dist>>
    S.insert({0, {src, 0}});

    vector<int> dist(n, 1e9);
    dist[src] = 0;
    
    while(!S.empty()){
        auto it = *S.begin();
        int stops = it.first;
        int node = it.second.first;
        int Dist = it.second.second;
        S.erase(it);
        if(stops <= k){
            for(auto i : adj[node]){
                int adjNode = i.first;
                int wt = i.second;
                if(Dist + wt < dist[adjNode]){
                    S.insert({stops+1, {adjNode, Dist + wt}});
                    dist[adjNode] = Dist + wt;
                }
            }
        }
    }
    return dist[dest] == 1e9 ? -1 : dist[dest];
}