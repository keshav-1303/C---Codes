#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-height-trees/?envType=daily-question&envId=2024-04-23
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // Remove leaves until ans found
    vector<int> degree(n, 0);   // leaf nodes have degree = 1
    vector<int> adj[n];
    for(auto i : edges){
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    queue<int> q;
    for(int i=0 ; i<n ; i++){
        if(degree[i] == 1){   // leaf node
            q.push(i);
        }
    }

    vector<int> ans;    // to store last level indexed
    while(!q.empty()){
        ans.clear();  
        int size = q.size();
        for(int i=0 ; i<size ; i++){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr : adj[node]){
                degree[nbr]--;
                if(degree[nbr] == 1)    q.push(nbr);    // bec leaf node
            }
        }
    }
    if(ans.empty())   ans.push_back(0);
    return ans;
}