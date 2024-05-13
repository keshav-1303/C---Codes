#include <bits/stdc++.h>
using namespace std;

// There are n stones at some integer coordinate points on a 2D plane. Each coordinate
// point may have at most one stone. You need to remove some stones. A stone can be 
// removed if it shares either the same row or the same column as another stone that 
// has not been removed. Given an array stones of length n, 
// return the maximum possible number of stones you can remove.

// https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal

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

int maxRemove(vector<vector<int>>& stones, int n) {
    
    int maxRow = 0, maxCol = 0;
    for(auto i : stones){
        maxRow = max(maxRow, i[0]);
        maxCol = max(maxCol, i[1]);
    }
    
    Disjoint_Set ds(maxRow + maxCol + 1);
    
    // Now, we just need to store stones those are in disjoint set.
    unordered_map<int, int> map;
    
    for(auto i : stones){
        int nodeRow = i[0];
        int nodeCol = i[1] + maxRow + 1;
        ds.UnionbyRank(nodeRow, nodeCol);
        map[nodeRow] = 1;
        map[nodeCol] = 1;
    }
    // After doing this, I have unique Ultimate parents for all Components.
    
    int count = 0;
    for(auto i : map){
        if(ds.findUpar(i.first) == i.first){
            // i.e it is the Ultimate parent.
            count++;
        }
    }
    return n - count;
}