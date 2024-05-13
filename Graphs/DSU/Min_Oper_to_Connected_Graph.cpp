#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph

class Disjoint_Set{

    vector<int> rank, parent;

    public:

    Disjoint_Set(int n){
        rank.resize(n+1, 0);
        int start = 0;
        parent.resize(n+1, 0);
        iota(parent.begin(), parent.end(), start);   // does parent[i] = i;
    }

    int findUpar(int node){
        if(node == parent[node])    return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionbyRank(int u, int v){
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);
        // if already same do nothing.
        if(ult_u == ult_v)    return ;
        if(rank[ult_u] < rank[ult_v]){
            // Smaller goes and gets attatched to the greater one.
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            // Smaller goes and gets attatched to the greater one.
            parent[ult_v] = ult_u;
        }
        else{
            // if they are same.
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        Disjoint_Set ds(n);
        int extraedges = 0;
        for(auto it : edge){
            if(ds.findUpar(it[0]) == ds.findUpar(it[1])){
                // matlab dono same component se hai, so no need of this edge.
                extraedges++;
            }
            else{
                ds.UnionbyRank(it[0], it[1]);
            }
        }

        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(ds.findUpar(i) == i)    count++;
        }

        int ans = count - 1;    // Connected Components - 1;
        if(extraedges >= ans){
            return ans;
        }

        return -1;
    }
};